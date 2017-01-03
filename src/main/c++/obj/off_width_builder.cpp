#include "off_width_builder.h"
#include "off_width.h"
#include "segmented_saver.h"

OffWidthBuilder::OffWidthBuilder()
{
}
OffWidthBuilder::~OffWidthBuilder()
{
}

Object *OffWidthBuilder::newObject( double x, double y )
{
   OffWidth *d = new OffWidth( Point2d(x, y), Point2d(x, y) ) ;
   SegmentedSaver *ss = new SegmentedSaver( d, "OffWidth" );
   d->saver( ss );
   return d ;
}
