#include "AreteBuilder.h"
#include "arete.h"
#include "wide_segmented_saver.h"

AreteBuilder::AreteBuilder()
{
}
AreteBuilder::~AreteBuilder()
{
}

Object *AreteBuilder::newObject( double x, double y )
{
   Arete *d = new Arete( Point2d(x, y), Point2d(x, y) ) ;
   WideSegmentedSaver *ss = new WideSegmentedSaver( d, "Arete" );
   d->saver( ss );
   return d ;
}
