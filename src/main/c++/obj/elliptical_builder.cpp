#include "elliptical_builder.h"
#include "elliptical.h"
#include "scalable_saver.h"

EllipticalBuilder::EllipticalBuilder() 
{
   _obj = 0 ;
}
EllipticalBuilder::~EllipticalBuilder()
{
}

Object *EllipticalBuilder::newObject( double x, double y )
{
   Elliptical *e = new Elliptical( ) ;
   ScalableSaver *ss = new ScalableSaver( e, "Elliptical" );
   e->saver( ss );
   return e ;
}
