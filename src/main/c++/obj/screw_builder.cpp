#include "screw_builder.h"
#include "screw.h"
#include "solid_saver.h"

ScrewBuilder::ScrewBuilder()
{
}
ScrewBuilder::~ScrewBuilder()
{
}

Object *ScrewBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Screw *s = new Screw() ;
   s->position( p ) ;
   SolidSaver* ss = new SolidSaver( s, "Screw" ) ;
   s->saver( ss );
   return s ;
}
