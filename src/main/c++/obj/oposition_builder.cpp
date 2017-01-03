#include "oposition_builder.h"
#include "oposition.h"
#include "segmented_saver.h"

OpositionBuilder::OpositionBuilder()
{
}
OpositionBuilder::~OpositionBuilder()
{
}

Object *OpositionBuilder::newObject( double x, double y )
{
   Oposition *d = new Oposition( Point2d(x, y), Point2d(x, y) ) ;

   SegmentedSaver *ss = new SegmentedSaver( d, "Oposition" );
   d->saver( ss );

   return d ;
}

