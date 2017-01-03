#include "rapel_builder.h"
#include "rapel.h"
#include "solid_saver.h"

RapelBuilder::RapelBuilder()
{
}
RapelBuilder::~RapelBuilder()
{
}

Object *RapelBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Rapel *r = new Rapel() ;
   r->position( p ) ;

   SolidSaver *ss = new SolidSaver( r, "Rapel" );
   r->saver( ss );


   return r ;
}
