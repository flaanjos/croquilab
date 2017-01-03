#include "text_saver.h"

//fstream

TextSaver::TextSaver( Text* t ) 
{
   _text = t ;
};

TextSaver::TextSaver()
{
   _text = 0 ;
};
TextSaver::~TextSaver()
{
};

Saver* TextSaver::copy()
{
   return new TextSaver( _text ) ;
}


Object* TextSaver::object()
{
   return _text ;
}


void TextSaver::object( Object* o ) 
{
   _text = (Text*)o ;
}

void TextSaver::save( std::ostream& stream )
{

   if( _text )
   {
      stream << "Text" ;
      stream << " = [ _position = [ " ;
      stream << _text->position()._x ;
      stream << ", " ;
      stream << _text->position()._y ;
      stream << "], ";
      stream << "_line_type = " ;
      stream << _text->lineType() ;
      stream << ", ";
      stream << "_line_size = " ;
      stream << _text->lineSize() ;
      stream << ", ";   
      stream << " _color = " ;
      stream << _text->color( ) ;
      stream << ", ";   
      stream << " _size = " ;
      stream << _text->size( ) ;
      stream << ", ";

      stream << " _length = " ;
      stream << _text->text( ).length() ;
      stream << ", ";

      stream << "_text = \"" ;
      stream << _text->text() ;
      stream << "\" ] ;\n";
   }
};

