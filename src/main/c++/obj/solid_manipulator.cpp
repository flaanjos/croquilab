#include "solid_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"

#include "EditPositionCommand.h"
#include "CommandStack.h"

SolidManipulator* SolidManipulator::_unique = 0 ;

SolidManipulator * SolidManipulator::instance( Solid *s )
{
   if( !_unique )
      _unique = new SolidManipulator() ;

   _unique->solid( s ) ;
   return _unique ;
}
SolidManipulator::SolidManipulator( ) :
_original_pos (0,0)
{
   _solid = 0 ;
   _pressed = false ;
}
void SolidManipulator::solid( Solid *b ) 
{
   _solid = b ;
   _original_pos = _solid->position() ;
   _pressed = false ;
   _tp_manipulation = Manipulator::NONE ;
}




bool SolidManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( !_solid )
      return false;

   _original_pos = _solid->position() ;

   double radius = 3 ;
   if( x<= _original_pos._x+radius && x>= _original_pos._x-radius && y<= _original_pos._y+radius && y>= _original_pos._y-radius )
   {     
      _tp_manipulation = Manipulator::MOVE_ALL ; 
      _pressed = true ;
      return true ;
   }

   _tp_manipulation = Manipulator::NONE ;
   return false ;
}

Manipulator::Type SolidManipulator::motion( double x, double y, bool shift, bool control )
{
   if( !_solid )
      return Manipulator::NONE ;

   if( !_pressed )
   {
      double radius = 3 ;
      if( x<= _original_pos._x+radius && x>= _original_pos._x-radius && y<= _original_pos._y+radius && y>= _original_pos._y-radius )
      {     
         return Manipulator::MOVE_ALL ;
      }
   }
   else
   {
      switch( _tp_manipulation ) 
      {
      case Manipulator::MOVE_ALL : 
         _solid->position( Point2d( x, y ) );
         return Manipulator::MOVE_ALL ;
      }
   }

   return Manipulator::NONE ;
}
bool SolidManipulator::pressKey( int c )
{
   return 0 ;
}
bool SolidManipulator::releaseKey( int c )
{
   return 0 ;
}

bool SolidManipulator::cancel()
{
   if( !_solid )
      return false ;

   _solid->position( _original_pos ) ;
   _pressed = false ;
   return false ;
}

void SolidManipulator::draw() const 
{
   Point2d pos = _solid->position() ;

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_CIRCLE ) ;
   wdMark( pos._x, pos._y ) ;
}
bool SolidManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _pressed )  
   {
            std::vector< Object* > list;
      list.push_back( _solid );

      Command* command = 0;
      switch( _tp_manipulation)
      {
      case Manipulator::NONE: break; 
      case Manipulator::MOVE_ALL : command = new EditPositionCommand( list, _solid->position(), _original_pos );  break;
      default:
         break;
      }  ;
      if( command )
         CommandStack::insert( command );

      solid( _solid ) ;
      _pressed = false ;
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false ;
}
bool SolidManipulator::manipulating() const 
{
   return _pressed ;
}