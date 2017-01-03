#include "text_builder.h"
#include "text.h"
#include "iup.h"
#include "text_saver.h"

TextBuilder::TextBuilder()
{
   _obj = 0 ;
}
TextBuilder::~TextBuilder()
{
}

Object *TextBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Text *t = new Text() ;
   t->position( p ) ;

   TextSaver *ss = new TextSaver( t );
   t->saver( ss );

   return t ;
}
Object * TextBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click )
{
   if( button != 1 ) 
      return 0 ;

   if( !_obj )
   {
	   char txt[1000] = "" ;
       int option = IupGetText( "Editor de texto", txt ) ; 

	   if( option == 0 )
		   return 0 ;

	   if( strlen( txt ) == 0 )
		   return 0 ;
	 
      _obj = newObject( x, y ) ;
	  
      Text *t = (Text*)_obj ;
      t->text( txt ) ;

      _obj = 0 ;
      return t ;
   }
   return 0 ;
}



