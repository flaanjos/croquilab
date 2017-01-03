#include "curved_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"
#include "iup.h"

#include "EditCurvedPointCommand.h"
#include "EditPointScapeCommand.h"
#include "EditPositionCommand.h"
#include "RemoveCurvedPointCommand.h"
#include "CommandStack.h"


CurvedManipulator* CurvedManipulator::_unique = 0 ;

CurvedManipulator * CurvedManipulator::instance( Curved *d )
{
   if( !_unique )
      _unique = new CurvedManipulator() ;

   _unique->curved( d ) ;
   return _unique ;
}
CurvedManipulator::CurvedManipulator( ) : _bb_min(0,0),_bb_max(0,0),_bb_mid(0,0), 
   _start(0,0), _original_scale(1,1), _new_pos(0,0)
{
   _selected_index = 0 ;
   _curved = NULL ;
   _pressed = false ;
   _manipulating = false;
}
void CurvedManipulator::curved( Curved *d ) 
{
   _curved = d ;
   _curved->boundingBox( _bb_min, _bb_max ) ;
   _bb_mid = (_bb_max+_bb_min)/2 ;
   _pressed = false ;
   _manipulating = false;
   _selected_index = 0 ;
   _tp_manipulation = Manipulator::NONE ;
}

bool CurvedManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)  
{
   if( !_curved )
      return false;

   //   _original_scale = _curved->scale() ;

   double zero=0, two=2 ;
   wdCanvas2World( 0, 0, &zero, NULL ) ;
   wdCanvas2World( 2, 2, &two, NULL ) ;
   double radius = two-zero ;

   unsigned int n = _curved->numPoints() ;
   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d p = _curved->positionPrevScape( i ) ;
      if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius &&i>0)
      {
         _start = p ;
         _tp_manipulation =  Manipulator::MOVE_POINT ;
         _pressed = true ;
         _manipulating = true ;
         _selected_index = i ;
         _type_selected = PREV ;
         return true ;
      }
      p = _curved->positionAftScape( i ) ;
      if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius &&i<_curved->numPoints()-1)
      {
         _start = p ;
         _tp_manipulation =  Manipulator::MOVE_POINT ;
         _pressed = true ;
         _manipulating = true ;
         _selected_index = i ;
         _type_selected = AFT ;
         return true ;
      }
      p = _curved->position( i ) ;
      if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius )
      {
         _start = p ;
         _tp_manipulation =  Manipulator::MOVE_POINT ;
         _pressed = true ;
         _manipulating = true ;
         _selected_index = i ;
         _type_selected = MAIN ;
         return true ;
      }
   }

   double three=3 ;
   wdCanvas2World( 3, 3, &three, NULL ) ;
   radius = three-zero ;

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

Manipulator::Type CurvedManipulator::motion( double x, double y, bool shift, bool control )
{
   if( !_curved )
      return Manipulator::NONE ;

   if( !_pressed )
   {
      double zero=0, two=2 ;
      wdCanvas2World( 0, 0, &zero, NULL ) ;
      wdCanvas2World( 2, 2, &two, NULL ) ;
      double radius = two-zero ;

      unsigned int n = _curved->numPoints() ;
      for( unsigned int i=0 ; i<n ; i++ )
      {
         Point2d p = _curved->positionPrevScape( i ) ;
         if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius &&i>0 )
            return Manipulator::MOVE_POINT ;

         p = _curved->positionAftScape( i ) ;
         if( x<= p._x+radius && x>= p._x-radius && y<= p._y+radius && y>= p._y-radius && i<_curved->numPoints()-1 )
            return Manipulator::MOVE_POINT ;

         p = _curved->position( i ) ;
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
      //  

      if( _tp_manipulation == Manipulator::MOVE_POINT )
      {
         Point2d diff = p-_curved->position( _selected_index ) ;
         if( _type_selected == MAIN )
         {
            _curved->position( _selected_index, p ) ;
            Point2d prev = _curved->positionPrevScape( _selected_index ) ;
            Point2d aft = _curved->positionAftScape( _selected_index ) ;
            _curved->positionPrevScape( _selected_index, prev+diff ) ;
            _curved->positionAftScape( _selected_index, aft+diff ) ;
         }
         else if( _type_selected == PREV )
         {
            _curved->positionPrevScape( _selected_index, p ) ;
         }
         else if( _type_selected == AFT )
         {
            _curved->positionAftScape( _selected_index, p ) ;
         }
         return _tp_manipulation ;
      }
      else if( _tp_manipulation == Manipulator::MOVE_ALL )
      {
         _new_pos = p ;
         _curved->position( p );
         return _tp_manipulation ;
      }
   }
   return Manipulator::NONE ;
}

bool CurvedManipulator::cancel() 
{
   if( !_curved || !_pressed )
      return false ;

   Point2d diff = _new_pos-_bb_mid ;

   if( _tp_manipulation == Manipulator::MOVE_POINT )
   {
      //_curved->position( _selected_index, _start ) ;


      if( _type_selected == MAIN )
      {
         diff = _start-_curved->position( _selected_index ) ;
         _curved->position( _selected_index, _start ) ;
         Point2d prev = _curved->positionPrevScape( _selected_index ) ;
         Point2d aft = _curved->positionAftScape( _selected_index ) ;
         _curved->positionPrevScape( _selected_index, prev+diff ) ;
         _curved->positionAftScape( _selected_index, aft+diff ) ;
      }
      else if( _type_selected == PREV )
      {
         _curved->positionPrevScape( _selected_index, _start ) ;
      }
      else if( _type_selected == AFT )
      {
         _curved->positionAftScape( _selected_index, _start ) ;
      }


   }
   else if( _tp_manipulation == Manipulator::MOVE_ALL )
   {
      _curved->position( _start );
   }

   _tp_manipulation = Manipulator::NONE ;
   _pressed = false ;
   _manipulating = false ;
   return true ;
}

void CurvedManipulator::draw() const 
{
   double zero=0, two=2 ;
   wdCanvas2World( 0, 0, &zero, NULL ) ;
   wdCanvas2World( 2, 2, &two, NULL ) ;
   double radius = two-zero ;

   Point2d min(0,0), max(0,0) ;
   _curved->boundingBox( min, max ) ;
   Point2d mid = (max+min)/2 ;

   cdMarkSize( 4 ) ;

   unsigned int n = _curved->numPoints() ;
   int ls = cdLineStyle( CD_DOTTED ) ;
   cdMarkType( CD_HOLLOW_BOX ) ;
   cdForeground( cdEncodeColor( 255, 96, 0 ) ) ;
   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d prev = _curved->positionPrevScape( i );
      Point2d aft = _curved->positionAftScape( i );
      Point2d pos = _curved->position( i ) ;
      wdMark( prev._x, prev._y ) ;
      wdMark( aft._x, aft._y ) ;
      wdLine( pos._x, pos._y, prev._x, prev._y ) ;
      wdLine( pos._x, pos._y, aft._x, aft._y ) ;
   }
   cdLineStyle( CD_CONTINUOUS ) ;
   cdMarkType( CD_BOX ) ;
   cdForeground( CD_RED ) ;

   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d pos = _curved->position( i ) ;
      wdMark( pos._x, pos._y ) ;
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
      Point2d pos(0,0);
      if( _type_selected == CurvedManipulator::MAIN )
      {
         pos = _curved->position( _selected_index ) ;
      }
      wdMark( pos._x, pos._y ) ;
   }

    cdTextAlignment( CD_WEST );
    wdVectorCharSize( 10 ) ; 
    cdLineCap( CD_CAPROUND ) ;
    cdLineJoin( CD_ROUND ) ;
    char txt[100];
    sprintf( txt, "%.1f", (_curved->length()*.2) ) ;
    cdLineWidth( 1 ) ;
    wdMultiLineVectorText( _curved->position(n-1)._x+10, _curved->position(n-1)._y+10, txt ); 
}

bool CurvedManipulator::manipulating() const
{
   return _manipulating ;

}
bool CurvedManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _pressed )  
   {
      std::vector< Object* > list;
      list.push_back( _curved );

      Command* command = 0;
      switch( _tp_manipulation)
      {
      case Manipulator::NONE: break; 
      case Manipulator::MOVE_ALL : command = new EditPositionCommand( list, _new_pos, _start );  break;
      case Manipulator::MOVE_POINT: 
         if( _type_selected == MAIN )
            command = new EditCurvedPointCommand( _curved, _selected_index, _new_pos, _start );
         if( _type_selected == AFT )
            command = new EditPointScapeCommand( _curved, 1, _selected_index, _new_pos, _start );
         if( _type_selected == PREV )
            command = new EditPointScapeCommand( _curved, 0, _selected_index, _new_pos, _start );
         break;
      default:
         break;
      }  ;
      if( command )
         CommandStack::insert( command );

      _curved->boundingBox( _bb_min, _bb_max ) ;
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
bool CurvedManipulator::pressKey( int c ) 
{
   if( _manipulating )
   {
      if( c== K_DEL )
      {
         Command* command = new RemoveCurvedPointCommand( _curved, _selected_index );
         CommandStack::insert( command ) ;
         unsigned int n_points = _curved->numPoints() ;
         if( n_points <=2 )
            return false; 

         Point2d pos(0,0);
         if( _type_selected == CurvedManipulator::MAIN )
         {
            _curved->removePoint( _selected_index ) ;
            _manipulating = false; 
            if( _selected_index == 0 )
            {
               _curved->positionPrevScape( 0, _curved->position(0) ) ;
            }
            if( _selected_index == n_points-1 )
            {
               _curved->positionAftScape( n_points-2, _curved->position(n_points-2) ) ;
            }
            _selected_index = 0 ;
            return true ;
         }
      }

   }
   return false; 

};
bool CurvedManipulator::releaseKey( int c )
{
   return false ;
};