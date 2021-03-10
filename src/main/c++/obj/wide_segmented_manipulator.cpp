#include "wide_segmented_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"
#include "iup.h"

#include "edit_segmented_point_command.h"
#include "remove_segmented_point_command.h"
#include "EditWideSegmentedWidth.h"
#include "edit_position_command.h"
#include "commandStack.h"


WideSegmentedManipulator* WideSegmentedManipulator::_unique = 0 ;

WideSegmentedManipulator * WideSegmentedManipulator::instance( WideSegmented *d )
{
   if( !_unique )
      _unique = new WideSegmentedManipulator() ;

   _unique->segmented( d ) ;
   return _unique ;
}
WideSegmentedManipulator::WideSegmentedManipulator( ) : _bb_min(0,0),_bb_max(0,0),_bb_mid(0,0), 
   _start(0,0), _original_scale(1,1), _new_pos(0,0)
{
   _selected_index = 0 ;
   _segmented = 0 ;
   _pressed = false ;
   _manipulating = false; 
   _original_width = 1 ;
   _new_width = _original_width;
}
void WideSegmentedManipulator::segmented( WideSegmented *d ) 
{
   _segmented = d ;
   _segmented->boundingBox( _bb_min, _bb_max ) ;
   _bb_mid = (_bb_max+_bb_min)/2 ;
   _pressed = false ;
   _manipulating = false; 
   _selected_index = 0 ;
   _tp_manipulation = Manipulator::NONE ;
   _original_width = _segmented->width();
   _new_width = _original_width;
}

bool WideSegmentedManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
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
         _tp_manipulation =  Manipulator::MOVE_POINT ;
         _pressed = true ;
         _manipulating = true ;
         _selected_index = i ;
         return true ;
      }
   }

   for( unsigned int i=0 ; i<n-1 ; i++ )
   { 
      Point2d wm(0,0);
      getWidthManipulator( wm, i, i+1 );

      if( x<= wm._x+radius && x>= wm._x-radius && y<= wm._y+radius && y>= wm._y-radius )
      {
         _original_width = _segmented->width();
         _new_width = _original_width;
         _start = wm ;
         _tp_manipulation =  Manipulator::ROTATE ;
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

Manipulator::Type WideSegmentedManipulator::motion( double x, double y, bool shift, bool control )
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
      for( unsigned int i=0 ; i<n-1 ; i++ )
      { 
         Point2d wm(0,0);
         getWidthManipulator( wm, i, i+1 );

         if( x<= wm._x+radius && x>= wm._x-radius && y<= wm._y+radius && y>= wm._y-radius )
         {
            return Manipulator::MOVE_POINT ;
         }
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
      else if( _tp_manipulation == Manipulator::ROTATE )
      { 
         Point2d pos_i = _segmented->position( _selected_index ) ;
         Point2d pos_j = _segmented->position( _selected_index + 1 ) ;
         Point2d center = ( pos_i + pos_j ) / 2 ;

         getWidthManipulator( pos_i, _selected_index, _selected_index + 1 ) ;

         pos_i = pos_i - center ;
         pos_j = p - center ;
         pos_i.normalize() ;
         double w = dot( pos_i, pos_j ) ;

         if( w <0 )
            w = -w;

         _new_width = w;
         _segmented->width( w );
      }
      else if( _tp_manipulation == Manipulator::MOVE_ALL )
      {
         _segmented->position( p );
         _new_pos = p;

      }
      return _tp_manipulation ;
   }
   return Manipulator::NONE ; ;
}


bool WideSegmentedManipulator::cancel() 
{
   if( !_segmented || !_pressed )
      return false ;

   Point2d diff = _new_pos-_bb_mid ;

   if( _tp_manipulation == Manipulator::MOVE_POINT )
   {
      _segmented->position( _selected_index, _start ) ;
   }
   else if( _tp_manipulation == Manipulator::ROTATE )
   {
      _segmented->width( _original_width ) ;
   }
   else if( _tp_manipulation == Manipulator::MOVE_ALL )
   {
      unsigned int n = _segmented->numPoints() ;
      for( unsigned int i=0 ; i<n ; i++ )
      {
         Point2d pos = _segmented->position( i ) ;
         _segmented->position( i, pos-diff ) ;
      }
   }

   _tp_manipulation = Manipulator::NONE ;
   _pressed = false ;
   _manipulating = false ;
   return true ;
}

void WideSegmentedManipulator::draw() const 
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

   cdMarkType( CD_HOLLOW_BOX ) ;
   int ls = cdLineStyle( CD_DOTTED ) ;
   cdForeground( cdEncodeColor( 255, 96, 0 ) ) ;
   for( unsigned int i=0 ; i<(n-1) ; i++ )
   {
      Point2d width_manipulator(0,0);
      Point2d pos_i = _segmented->position( i ) ;
      Point2d pos_j = _segmented->position( i+1 ) ;
      Point2d center = ( pos_i + pos_j ) / 2 ;
      getWidthManipulator( width_manipulator, i, i+1 );
      wdMark( width_manipulator._x, width_manipulator._y ) ;
      wdLine( center._x, center._y, width_manipulator._x, width_manipulator._y );
   }
   cdLineStyle( ls ) ;




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

bool WideSegmentedManipulator::manipulating() const
{
   return _manipulating ;

}
bool WideSegmentedManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _pressed )  
   {
      if( _tp_manipulation == Manipulator::ROTATE )
      {
         EditWideSegmentedWidth *command = new EditWideSegmentedWidth( _segmented, _segmented->width(), _original_width );
      }

      std::vector< Object* > list;
      list.push_back( _segmented );

      Command* command = 0;
      switch( _tp_manipulation)
      {
      case Manipulator::NONE: break; 
      case Manipulator::MOVE_ALL : command = new EditPositionCommand( list, _new_pos, _start );  break;
      case Manipulator::MOVE_POINT: command = new EditSegmentedPointCommand( _segmented, _selected_index, _new_pos, _start ); break;
      case Manipulator::ROTATE: command = new EditWideSegmentedWidth( _segmented, _segmented->width(), _original_width );
      default:
         break;
      }  ;
      if( command )
         CommandStack::insert( command );

      segmented( _segmented );
      _pressed = false ;
      _manipulating = false ;
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false ;
}
bool WideSegmentedManipulator::pressKey( int c ) 
{
   if( _manipulating )
   {
      if( c== K_DEL )
      {
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

void WideSegmentedManipulator::getWidthManipulator( Point2d& wm, int i, int j ) const
{
   Point2d pos_i = _segmented->position( i ) ;
   Point2d pos_j = _segmented->position( j ) ;
   Point2d center = ( pos_i + pos_j ) / 2 ;

   Point2d dir_vector = pos_j - pos_i ;
   double width = _segmented->width() ;
   dir_vector.normalize();
   dir_vector.rot90() ;
   dir_vector = dir_vector * width ;
   wm = center + dir_vector ;
};

