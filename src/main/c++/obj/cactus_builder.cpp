#include "cactus_builder.h"
#include "cactus.h"
#include "scalable_saver.h"
CactusBuilder::CactusBuilder()
{
}
CactusBuilder::~CactusBuilder()
{
}

Object *CactusBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Cactus *c = new Cactus() ;
   c->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( c, "Cactus" ) ;
   c->saver( ss ) ;

   return c ;
}
