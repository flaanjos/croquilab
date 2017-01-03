#include "crystal_builder.h"
#include "crystal.h"
#include "scalable_saver.h"

CrystalBuilder::CrystalBuilder()
{
}
CrystalBuilder::~CrystalBuilder()
{
}

Object *CrystalBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Crystal *b = new Crystal() ;
   b->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( b, "Crystal" ) ;
   b->saver( ss ) ;

   return b ;
}
