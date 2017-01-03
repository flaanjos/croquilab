#include "polygonal_builder.h"
#include "polygonal.h"
#include "segmented_saver.h"

PolygonalBuilder::PolygonalBuilder()
{
}
PolygonalBuilder::~PolygonalBuilder()
{
}

Object *PolygonalBuilder::newObject( double x, double y )
{
   Polygonal *d = new Polygonal( Point2d(x, y), Point2d(x, y) ) ;
   SegmentedSaver *ss = new SegmentedSaver( d, "Polygonal" );
   d->saver( ss );
   return d ;
}
