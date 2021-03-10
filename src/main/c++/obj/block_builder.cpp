#include "BlockBuilder.h"
#include "Block.h"
#include "scalable_saver.h"

BlockBuilder::BlockBuilder()
{
}
BlockBuilder::~BlockBuilder()
{
}

Object *BlockBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Block *b = new Block() ;
   b->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( b, "Block" ) ;
   b->saver( ss ) ;

   return b ;
}
