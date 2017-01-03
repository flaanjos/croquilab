#include "round_bolt_builder.h"
#include "round_bolt.h"
#include "solid_saver.h"


RoundBoltBuilder::RoundBoltBuilder()
{
}
RoundBoltBuilder::~RoundBoltBuilder()
{
}

Object *RoundBoltBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   RoundBolt *t = new RoundBolt() ;
   t->position( p ) ;

   SolidSaver *ss = new SolidSaver( t, "RoundBolt" );
   t->saver( ss );

   return t ;
}
