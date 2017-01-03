
#include "opt_station_builder.h"
#include "opt_station.h"
#include "solid_saver.h"

OptStationBuilder::OptStationBuilder()
{
}
OptStationBuilder::~OptStationBuilder()
{
}

Object *OptStationBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   OptStation *os = new OptStation() ;
   os->position( p ) ;

   SolidSaver *ss = new SolidSaver( os, "OptStation" );
   os->saver( ss );


   return os ;
}
