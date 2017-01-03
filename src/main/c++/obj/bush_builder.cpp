#include "bush_builder.h"
#include "bush.h"
#include "scalable_saver.h"

BushBuilder::BushBuilder()
{
}
BushBuilder::~BushBuilder()
{
}

Object *BushBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Bush *b = new Bush() ;
   b->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( b, "Bush" ) ;
   b->saver( ss ) ;

   return b ;
}