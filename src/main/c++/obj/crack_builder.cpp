#include "crack_builder.h"
#include "crack.h"
#include "segmented_saver.h"

CrackBuilder::CrackBuilder()
{
}
CrackBuilder::~CrackBuilder()
{
}

Object *CrackBuilder::newObject( double x, double y )
{
   Crack *c = new Crack( Point2d(x, y), Point2d(x, y) ) ;

   SegmentedSaver *ss = new SegmentedSaver( c, "Crack" );
   c->saver( ss );
   return c ;
}
