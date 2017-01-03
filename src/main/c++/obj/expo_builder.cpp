#include "expo_builder.h"
#include "expo.h"
#include "solid_saver.h"

ExpoBuilder::ExpoBuilder()
{
}
ExpoBuilder::~ExpoBuilder()
{
}

Object *ExpoBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Expo *e = new Expo() ;
   e->position( p ) ;

   SolidSaver *ss = new SolidSaver( e, "Expo" );
   e->saver( ss );

   return e ;
}
