#include "segmented_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"
#include "iup.h"

#include "EditSegmentedPointCommand.h"
#include "EditPositionCommand.h"
#include "RemoveSegmentedPointCommand.h"
#include "CommandStack.h"


SegmentedManipulator* SegmentedManipulator::_unique = 0 ;



SegmentedManipulator * SegmentedManipulator::instance( Segmented *d )
{
   if( !_unique )
      _unique = new SegmentedManipulator() ;

   _unique->segmented( d ) ;
   return _unique ;
}



SegmentedManipulator::SegmentedManipulator( ) : _bb_min(0,0),_bb_max(0,0),_bb_mid(0,0), 
   _start(0,0), _original_scale(1,1), _new_pos(0,0)
{
   _selected_index = 0 ;
   _segmented = NULL ;
   _pressed = false ;
   _manipulating = false; 
}



void SegmentedManipulator::segmented( Segmented *d ) 
{
   _segmented = d ;
   _segmented->boundingBox( _bb_min, _bb_max ) ;
   _bb_mid = (_bb_max+_bb_min)/2 ;

   _pressed = false ;
   _manipulating = false; 
   _selected_index = 0 ;
   _tp_manipulation = Manipulator::NONE ;
}



bool SegmentedManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( !_segmented )
      return false;


   double radius = 2 ;

   unsigned int n = _segmented->numPoints() ;
   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d p = _segmented->position( i ) ;

      if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius )
      {
         _start = p ;
         _new_pos = p;
         _tp_manipulation =  Manipulator::MOVE_POINT ;
         _pressed = true ;
         _manipulating = true ;
         _selected_index = i ;
         return true ;
      }
   }

   radius = 3 ;
   if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
   {     
      _start = _bb_mid ;
      _new_pos = _bb_mid ;
      _tp_manipulation = Manipulator::MOVE_ALL ; 
      _pressed = true ;
      _manipulating = true ;
      return true ;
   }

   _tp_manipulation = Manipulator::NONE ;
   _pressed = false ;
   _manipulating = false ;
   return false ;
}



Manipulator::Type SegmentedManipulator::motion( double x, double y, bool shift, bool control )
{
   if( !_segmented )
      return Manipulator::NONE ;

   if( !_pressed )
   {

      double radius = 2 ;

      unsigned int n = _segmented->numPoints() ;
      for( unsigned int i=0 ; i<n ; i++ )
      {
         Point2d p = _segmented->position( i ) ;

         if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius )
            return Manipulator::MOVE_POINT ;
      }

      if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
         return Manipulator::MOVE_ALL ;

      return Manipulator::NONE ;
   }
   else
   {
      Point2d p(x,y) ;

      if( _tp_manipulation == Manipulator::MOVE_POINT )
      {
         _segmented->position( _selected_index, p ) ;
         _new_pos = p;
      }
      else if( _tp_manipulation == Manipulator::MOVE_ALL )
      {         
         _segmented->position( p );
         _new_pos = p ;
      }
      return _tp_manipulation ;
   }
   return Manipulator::NONE ; ;
}



bool SegmentedManipulator::cancel() 
{
   if( !_segmented || !_pressed )
      return false ;

   Point2d diff = _new_pos-_bb_mid ;

   if( _tp_manipulation == Manipulator::MOVE_POINT )
   {
      _segmented->position( _selected_index, _start ) ;
   }
   else if( _tp_manipulation == Manipulator::MOVE_ALL )
   {
      _segmented->position( _start );
   }
   _new_pos = _start;

   _tp_manipulation = Manipulator::NONE ;
   _pressed = false ;
   _manipulating = false ;
   return true ;
}



void SegmentedManipulator::draw() const 
{
   double zero=0, two=2 ;
   wdCanvas2World( 0, 0, &zero, NULL ) ;
   wdCanvas2World( 2, 2, &two, NULL ) ;
   double radius = two-zero ;

   Point2d min(0,0), max(0,0) ;
   _segmented->boundingBox( min, max ) ;
   Point2d mid = (max+min)/2 ;

   cdForeground ( cdEncodeColor( 92, 92, 92 ) ) ;
   cdInteriorStyle( CD_HOLLOW );
   _segmented->boundingBox( min, max );
   wdBox( min._x, max._x, min._y, max._y); 

   cdMarkSize( 4 ) ;
   cdMarkType( CD_BOX ) ;
   cdForeground( CD_RED ) ;
   unsigned int n = _segmented->numPoints() ;
   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d pos = _segmented->position( i ) ;
      wdMark( pos._x, pos._y ) ;
   }

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_CIRCLE ) ;
   cdForeground( CD_BLUE ) ;
   wdMark( mid._x, mid._y ) ;

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_BOX ) ;
   cdForeground( CD_BLACK ) ;
   if( _manipulating && !_pressed)
   {
      Point2d pos = _segmented->position( _selected_index ) ;
      wdMark( pos._x, pos._y ) ;
   }
}



bool SegmentedManipulator::manipulating() const
{
   return _manipulating ;
}



bool SegmentedManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) 
{
   if( _pressed )  
   {
      std::vector< Object* > list;
      list.push_back( _segmented );

      Command* command = 0;
      switch( _tp_manipulation)
      {
      case Manipulator::NONE: break; 
      case Manipulator::MOVE_ALL : command = new EditPositionCommand( list, _new_pos, _start );  break;
      case Manipulator::MOVE_POINT: command = new EditSegmentedPointCommand( _segmented, _selected_index, _new_pos, _start ); break;
      default:
         break;
      }  ;
      if( command )
         CommandStack::insert( command );


      _segmented->boundingBox( _bb_min, _bb_max ) ;
      _bb_mid = (_bb_max+_bb_min)/2 ;
      _pressed = false ;

      if( _tp_manipulation == Manipulator::MOVE_ALL )
      {
         _manipulating = false ;
      }
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false ;
}



bool SegmentedManipulator::pressKey( int c ) 
{
   if( _manipulating )
   {
      if( c== K_DEL )
      {
         Command* command = new RemoveSegmentedPointCommand( _segmented, _selected_index );
         CommandStack::insert( command ) ;

         unsigned int n_points = _segmented->numPoints() ;
         if( n_points <=2 )
            return false; 

         _segmented->removePoint( _selected_index ) ;
         _manipulating = false; 
         _selected_index = 0 ;
         return true ;
      }
   }
   return false; 
}

