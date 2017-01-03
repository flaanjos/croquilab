#include "sharp_bolt_builder.h"
#include "sharp_bolt.h"
#include "solid_saver.h"

SharpBoltBuilder::SharpBoltBuilder()
{
}
SharpBoltBuilder::~SharpBoltBuilder()
{
}

Object *SharpBoltBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   SharpBolt *sb = new SharpBolt() ;
   sb->position( p ) ;

   SolidSaver *ss = new SolidSaver( sb, "SharpBolt" );
   sb->saver( ss );


   return sb ;
}
