#include "chimney_builder.h"
#include "chimney.h"
#include "wide_segmented_saver.h"
ChimneyBuilder::ChimneyBuilder()
{
}
ChimneyBuilder::~ChimneyBuilder()
{
}

Object *ChimneyBuilder::newObject( double x, double y )
{
   Chimney *d = new Chimney( Point2d(x, y), Point2d(x, y) ) ;
   WideSegmentedSaver *ss = new WideSegmentedSaver( d, "Chimney" );
   d->saver( ss );
   return d ;
}
