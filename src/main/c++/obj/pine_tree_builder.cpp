#include "pine_tree_builder.h"
#include "pine_tree.h"
#include "scalable_saver.h"

PineTreeBuilder::PineTreeBuilder()
{
}
PineTreeBuilder::~PineTreeBuilder()
{
}

Object *PineTreeBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   PineTree *pt = new PineTree() ;
   pt->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( pt, "PineTree" ) ;
   pt->saver( ss ) ;

   return pt ;
}
