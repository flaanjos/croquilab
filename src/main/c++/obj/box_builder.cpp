#include "box_builder.h"
#include "box.h"
#include "scalable_saver.h"

BoxBuilder::BoxBuilder() 
{
}
BoxBuilder::~BoxBuilder()
{
}

Object *BoxBuilder::newObject( double x, double y )
{
   Box *e = new Box( ) ;
   ScalableSaver *ss = new ScalableSaver( e, "Box" );
   e->saver( ss );

   return e ;
}
