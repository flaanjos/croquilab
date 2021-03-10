#include "block_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"

BlockManipulator* BlockManipulator::_unique = NULL ;

BlockManipulator * BlockManipulator::instance( Block *b )
{
   if( !_unique )
      _unique = new BlockManipulator() ;

   _unique->block( b ) ;
   return _unique ;
}
BlockManipulator::BlockManipulator( ) : _bb_min(0,0),_bb_max(0,0),_bb_mid(0,0), 
_start(0,0), _original_pos (0,0), _original_scale (1,1)
{
   _block = NULL ;
   _manipulating = false ;
}
void BlockManipulator::block( Block *b ) 
{
   _block = b ;
   _block->boundingBox( _bb_min, _bb_max ) ;
   _bb_mid = (_bb_max+_bb_min)/2 ;
   _original_pos = _block->position() ;
   _original_scale = _block->scale() ;
   _manipulating = false ;
   _tp_manipulation = Manipulator::NONE ;
}
Manipulator::Type BlockManipulator::type( double x, double y ) const 
{
   if( !_block )
      return Manipulator::NONE ;

   if( _manipulating )
      return _tp_manipulation ;

   double radius = 2 ;

   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
      return Manipulator::RESIZE_SW ;

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
      return Manipulator::RESIZE_NE;

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
      return Manipulator::RESIZE_SE ;

   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
      return Manipulator::RESIZE_NW ;

   if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
      return Manipulator::MOVE_ALL ;

   return Manipulator::NONE ;
}
bool BlockManipulator::select( double x, double y )
{
   if( !_block )
      return false;

   _original_pos = _block->position() ;
   _original_scale = _block->scale() ;

   double radius = 2 ;
   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
   {
      _start = _bb_min ;
      _tp_manipulation = Manipulator::RESIZE_SW ;
      _manipulating = true ;
      return true ;
   }

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
   {
      _start = _bb_max ;
      _tp_manipulation = Manipulator::RESIZE_NE ;
      _manipulating = true ;
      return true;
   }

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
   {
      _start._x = _bb_max._x ;
      _start._y = _bb_min._y ;
      _tp_manipulation = Manipulator::RESIZE_SE ;
      _manipulating = true ;
      return true ;
   }

   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
   {
      _start._x = _bb_min._x ;
      _start._y = _bb_max._y ;
      _tp_manipulation = Manipulator::RESIZE_NW ;
      _manipulating = true ;
      return true ;
   }
   radius = 3 ;
   if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
   {     
      _start = _bb_mid ;
      _tp_manipulation = Manipulator::MOVE_ALL ; 
      _manipulating = true ;
      return true ;
   }

  _tp_manipulation = Manipulator::NONE ;
   _manipulating = false ;
   return false ;
}
bool BlockManipulator::moveSelected( double x, double y ) 
{
   if( !_block )
      return false ;

   Point2d p(x,y) ;
   // Its a rectangle, so every half-diagonal has the same size
   // Old half diagonal
   double old_size = sqrt( (_bb_mid-_bb_max).squareSize() ) ;
   // new halfe diagonal
   double new_size = sqrt( (p-_bb_mid).squareSize() ) ;

   switch( _tp_manipulation ) 
   {
   case Manipulator::RESIZE_SW :
      if( y >_bb_mid._y || x>_bb_mid._x )
         return false ;      
      _block->scale( _original_scale * new_size / old_size ) ;
      return true ;

   case Manipulator::RESIZE_NE :
      if( y <_bb_mid._y || x<_bb_mid._x )
         return false ;
      _block->scale( _original_scale * new_size / old_size ) ;
      return true;

   case Manipulator::RESIZE_SE :
      if( y >_bb_mid._y || x<_bb_mid._x )
         return false ;
      _block->scale( _original_scale * new_size / old_size ) ;
      return true;

   case Manipulator::RESIZE_NW :
      if( y <_bb_mid._y || x>_bb_mid._x )
         return false ;
      _block->scale( _original_scale * new_size / old_size ) ;
      return true;

      return true ;
   case Manipulator::MOVE_ALL : 
      _block->position( Point2d( x, y ) );
      return true ;
   }

   return false ;
}
bool BlockManipulator::aproveManipulation( double x, double y ) 
{
   if( moveSelected( x,y ) )  
   {
      block( _block ) ;
      _manipulating = false ;
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false ;
}
bool BlockManipulator::undoManipulation() 
{
   if( !_block )
      return false ;

   _block->edit( _original_scale, _original_pos ) ;
   _manipulating = false ;
   return false ;
}

bool BlockManipulator::drawPoints() const 
{
   double zero=0, two=2 ;
   wdCanvas2World( 0, 0, &zero, NULL ) ;
   wdCanvas2World( 2, 2, &two, NULL ) ;
   double radius = two-zero ;

   Point2d min(0,0), max(0,0) ;
   _block->boundingBox( min, max ) ;
   Point2d mid = (max+min)/2 ;

   cdMarkSize( 4 ) ;
   cdMarkType( CD_HOLLOW_BOX ) ;
   cdForeground( CD_BLUE ) ;

   wdMark( min._x, min._y ) ;
   wdMark( max._x, min._y ) ;
   wdMark( min._x, max._y ) ;
   wdMark( max._x, max._y ) ;

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_CIRCLE ) ;
   wdMark( mid._x, mid._y ) ;

   return true ;
}

bool BlockManipulator::manipulating() const
{
   return _manipulating ;
}