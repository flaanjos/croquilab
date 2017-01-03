#include "piton_builder.h"
#include "piton.h"
#include "solid_saver.h"

PitonBuilder::PitonBuilder()
{
}
PitonBuilder::~PitonBuilder()
{
}

Object *PitonBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Piton *t = new Piton() ;
   t->position( p ) ;

   SolidSaver *ss = new SolidSaver( t, "Piton" );
   t->saver( ss );

   return t ;
}
