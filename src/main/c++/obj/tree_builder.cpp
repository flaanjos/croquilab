#include "tree_builder.h"
#include "tree.h"
#include "scalable_saver.h" 

TreeBuilder::TreeBuilder()
{
}
TreeBuilder::~TreeBuilder()
{
}

Object *TreeBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Tree *t = new Tree() ;
   t->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( t, "Tree" ) ;
   t->saver( ss ) ;

   return t ;
}
