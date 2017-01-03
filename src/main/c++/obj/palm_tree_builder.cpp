#include "palm_tree_builder.h"
#include "palm_tree.h"
#include "scalable_saver.h"

PalmTreeBuilder::PalmTreeBuilder()
{
}
PalmTreeBuilder::~PalmTreeBuilder()
{
}

Object *PalmTreeBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   PalmTree *pt = new PalmTree() ;
   pt->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( pt, "PalmTree" ) ;
   pt->saver( ss ) ;

   return pt ;
}
