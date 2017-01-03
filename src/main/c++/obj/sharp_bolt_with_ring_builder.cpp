#include "sharp_bolt_with_ring_builder.h"
#include "sharp_bolt_with_ring.h"
#include "solid_saver.h"

SharpBoltWithRingBuilder::SharpBoltWithRingBuilder()
{
}
SharpBoltWithRingBuilder::~SharpBoltWithRingBuilder()
{
}

Object *SharpBoltWithRingBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   SharpBoltWithRing *sb = new SharpBoltWithRing() ;
   sb->position( p ) ;

   SolidSaver *ss = new SolidSaver( sb, "SharpBoltWithRing" );
   sb->saver( ss );


   return sb ;
}
