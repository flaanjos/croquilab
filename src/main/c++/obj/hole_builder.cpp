#include "hole_builder.h"
#include "hole.h"
#include "scalable_saver.h"

HoleBuilder::HoleBuilder()
{
}
HoleBuilder::~HoleBuilder()
{
}

Object *HoleBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Hole *b = new Hole() ;
   b->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( b, "Hole" ) ;
   b->saver( ss ) ;

   return b ;
}
