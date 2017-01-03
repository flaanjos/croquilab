#include "stations_builder.h"
#include "stations.h"
#include "cd.h"
#include "wd.h"
#include "segmented_saver.h"

StationsBuilder::StationsBuilder()
{
}
StationsBuilder::~StationsBuilder()
{
}

Object *StationsBuilder::newObject( double x, double y )
{
   Stations *s = new Stations( Point2d(x, y), Point2d(x, y) ) ;

   SegmentedSaver *ss = new SegmentedSaver( s, "Stations" );
   s->saver( ss );
   return s ;
}

void StationsBuilder::draw()
{
   if( !_obj )
      return ;


   long int c = cdForeground( CD_GRAY ) ;
   int x = cdLineStyle( CD_DOTTED ) ;
   Stations *s = (Stations*)_obj ;
   for( unsigned int i=0; i<s->numPoints()-1 ; i++ )
   {
      wdLine( s->position(i)._x, s->position(i)._y, s->position(i+1)._x, s->position(i+1)._y );
   }
   cdLineStyle( x ) ;
   cdForeground( c ) ;
   _obj->draw() ;

};