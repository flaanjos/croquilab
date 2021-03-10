#include "text_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"
#include "iup.h"
#include "iupcontrols.h"

#include "edit_position_command.h"
#include "edit_text_command.h"
#include "commandStack.h"

TextManipulator* TextManipulator::_unique = 0 ;

TextManipulator * TextManipulator::instance( Text *t )
{
   if( !_unique )
      _unique = new TextManipulator() ;

   _unique->text( t ) ;

   return _unique ;
}
TextManipulator::TextManipulator( ) : _start( 0 , 0 ), _original_pos ( 0 , 0 )
{
   _text = 0 ;
   _manipulating = false;
   _motion = false;

}
void TextManipulator::text( Text *b ) 
{
   _text = b ;
   _original_pos = _text->position() ;
   _manipulating = false ;
   _tp_manipulation = Manipulator::NONE ;
      _motion = false;
}


bool TextManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) 
{
   if( !_text )
      return false;

   _motion = false;
   if( !d_click )
   {
      _original_pos = _text->position() ;

      double radius = 3 ;
      if( x<= _original_pos._x+radius && x>= _original_pos._x-radius && y<= _original_pos._y+radius && y>= _original_pos._y-radius )
      {     
         _start = _original_pos ;
         _tp_manipulation = Manipulator::MOVE_ALL ; 
         _manipulating = true ;
         return true ;
      }
      Point2d min, max;
      _text->boundingBox( min, max );

      if( x<= max._x && x>= min._x && y<= max._y && y >= min._y )
      {
         _tp_manipulation = Manipulator::NONE ; 
         _manipulating = true ;
         return false;
      }

      _tp_manipulation = Manipulator::NONE ;
      _manipulating = false ;
      return false ;
   }
   else
   {
      _tp_manipulation = Manipulator::NONE;
      _manipulating = false;

      char txt[1000] ;
      int size = 2;
      strcpy( txt, _text->text().c_str() ) ;

      int choice = IupGetParam("Editor de Texto", 0, 0,
         "Tamanho: %l|Micro|Pequeno|Normal|Grande|Enorme|\n" 
         "Texto: %m\n",
         &size, txt, NULL) ;

      if (choice == 1 )
      {   
         int new_size = ((size-1)*4) + 8; 
         if( new_size != _text->size() || txt != _text->text() )
         {
            Command* command = new EditTextCommand( _text, txt, _text->text(), new_size, _text->size() );
            CommandStack::insert( command );
            _text->text( txt ) ;
            _text->size( new_size );
            return true;
         }
      }
   }
   return false ;
}

Manipulator::Type TextManipulator::motion( double x, double y, bool shift, bool control )
{
   if( !_text )
      return Manipulator::NONE ;

   if( !_manipulating )
   {


      Point2d pos = _text->position() ;

      double radius = 2 ;

      if( x<= pos._x+radius && x>= pos._x-radius && y<= pos._y+radius && y>= pos._y-radius )
         return Manipulator::MOVE_ALL ;

      return Manipulator::NONE ;
   }
   else
   {
             _motion = true;

      switch( _tp_manipulation ) 
      {
      case Manipulator::MOVE_ALL : 
         _text->position( Point2d( x, y ) );
         return _tp_manipulation ;
      }
   }

   return Manipulator::NONE ;
}



bool TextManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _manipulating && _motion )
   {
      std::vector<Object*> list;
      list.push_back( _text );

      Command* command = 0;

      switch( _tp_manipulation)
      {
      case Manipulator::MOVE_ALL : command = new EditPositionCommand( list, _text->position(), _original_pos );  break;
      default: break;
      }  ;

      if( command )
         CommandStack::insert( command ) ;

      _motion = false;

      text( _text ) ;
      _manipulating = false ;
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false; 
}



bool TextManipulator::cancel() 
{
   if( !_text )
      return false ;

   _text->position( _original_pos ) ;
   _manipulating = false ;
   return false ;
}

void TextManipulator::draw() const 
{
   Point2d pos = _text->position() ;

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_CIRCLE ) ;
   wdMark( pos._x, pos._y ) ;

   return ;
}

bool TextManipulator::manipulating() const
{
   return _manipulating ;
}
