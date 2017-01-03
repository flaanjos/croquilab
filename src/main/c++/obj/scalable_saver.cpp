#include "scalable_saver.h"

//fstream

ScalableSaver::ScalableSaver( Scalable* s ) : _type_name( "Scalable" )
{
   _scalable = s ;
};
ScalableSaver::ScalableSaver( Scalable* s, const std::string &type_name ) : _type_name( type_name )
{
   _scalable = s ;
};
ScalableSaver::ScalableSaver()
{
   _scalable = 0 ;
};
ScalableSaver::~ScalableSaver()
{
};

Saver* ScalableSaver::copy()
{
   return new ScalableSaver( _scalable, _type_name ) ;
}

Object* ScalableSaver::object()
{
   return _scalable ;
}

void ScalableSaver::object( Object* o ) 
{
   _scalable = (Scalable*)o ;
}

void ScalableSaver::save( std::ostream& stream )
{

   if( _scalable )
   {
      stream << _type_name ;
      stream << " = [ _position = [ " ;
      stream << _scalable->position()._x ;
      stream << ", " ;
      stream << _scalable->position()._y ;
      stream << "], ";
      stream << "_scale = [ " ;
      stream << _scalable->scale()._x ;
      stream << ", " ;
      stream << _scalable->scale()._y ;
      stream << "], ";
      stream << "_line_type = " ;
      stream << _scalable->lineType() ;
      stream << ", ";
      stream << "_line_size = " ;
      stream << _scalable->lineSize() ;
      stream << ", ";   
      stream << " _color = " ;
      stream << _scalable->color( ) ;
      stream << " ] ;\n" ;
   }
};

