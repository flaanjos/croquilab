#include "solid_saver.h"

//fstream

SolidSaver::SolidSaver( Solid* s ) : _type_name( "Solid" )
{
   _solid = s ;
}


SolidSaver::SolidSaver( Solid* s, const std::string &type_name ) : _type_name( type_name )
{
   _solid = s ;
}


SolidSaver::SolidSaver()
{
   _solid = 0 ;
}


SolidSaver::~SolidSaver()
{
}


Saver* SolidSaver::copy()
{
   return new SolidSaver( _solid, _type_name ) ;
}


Object* SolidSaver::object()
{
   return _solid ;
}


void SolidSaver::object( Object* o ) 
{
   _solid = (Solid*)o ;
}


void SolidSaver::save( std::ostream& stream )
{
   if( _solid )
   {
      stream << _type_name ;
      stream << " = [ _position = [ " ;
      stream << _solid->position()._x ;
      stream << ", " ;
      stream << _solid->position()._y ;
      stream << "], ";
      stream << "_line_type = " ;
      stream << _solid->lineType() ;
      stream << ", ";
      stream << "_line_size = " ;
      stream << _solid->lineSize() ;
      stream << ", ";   
      stream << " _color = " ;
      stream << _solid->color( ) ;
      stream << " ] ;\n" ;
   }
};

