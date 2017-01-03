#include "object.h"


long int Object::_id_count = 0 ;


Object::Object ( ) : _temp_scale( 1, 1 )
{
   _id_count++ ;

   _id = _id_count ;
   _color = 0 ;
   _line_size = 1 ;
   _line_type = 0 ;
   _saver = 0 ;
}


Object::Object( const Object& obj ): _temp_scale( 1, 1 )
{
   _id_count++ ;

   _id = _id_count ;
   _color = obj._color ;
   _line_size = obj._line_size ;
   _line_type = obj._line_type ;
   _saver = 0 ;
}  


Object::~Object( )
{
}


long int Object::id() const
{
   return _id ;
}


long int Object::noId()
{
   return 0 ;
}

void Object::drawSelectable()
{
   draw();
}


long int Object::color() const
{
   return _color;
}


void Object::color( long int c )
{
   _color = c ;
}


long int Object::lineSize() const
{
   return _line_size ;
}


void Object::lineSize( long int ls )
{
   _line_size = ls ;
}


long int Object::lineType() const
{
   return _line_type ;
}


void Object::lineType( long int lt )
{
   _line_type = lt ;
}


Saver *Object::saver()
{
   return _saver ;
}


void Object::saver( Saver* s )
{
   _saver = s ;
}
