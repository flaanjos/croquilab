#include "grass_builder.h"
#include "grass.h"
#include "scalable_saver.h"

GrassBuilder::GrassBuilder()
{
}
GrassBuilder::~GrassBuilder()
{
}

Object *GrassBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Grass *t = new Grass() ;
   t->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( t, "Grass" ) ;
   t->saver( ss ) ;

   return t ;
}
