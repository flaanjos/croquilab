#include "arrow_builder.h"
#include "Arrow.h"
#include "segmented_saver.h"

ArrowBuilder::ArrowBuilder()
{
}
ArrowBuilder::~ArrowBuilder()
{
}

Object *ArrowBuilder::newObject( double x, double y )
{
   Arrow *d = new Arrow( Point2d(x, y), Point2d(x, y) ) ;
   SegmentedSaver *ss = new SegmentedSaver( d, "Arrow" );
   d->saver( ss );
   return d ;
}
