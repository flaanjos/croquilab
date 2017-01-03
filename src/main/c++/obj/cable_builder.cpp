#include "cable_builder.h"
#include "cable.h"
#include "segmented_saver.h"

CableBuilder::CableBuilder()
{
}
CableBuilder::~CableBuilder()
{
}

Object *CableBuilder::newObject( double x, double y )
{
   Cable *c = new Cable( Point2d(x, y), Point2d(x, y) ) ;
   SegmentedSaver *ss = new SegmentedSaver( c, "Cable" );
   c->saver( ss );
   return c ;
}
