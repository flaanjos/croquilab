


#include "opt_station.h"
#include "cd.h"
#include "wd.h"



OptStation::OptStation() 
{
}


OptStation::~OptStation()
{
};



const Point2d & OptStation::position( ) const
{
   return _position ;
} ;

void OptStation::position( const Point2d & p ) 
{
   _position = p  ;
};


void OptStation::draw( ) const
{
   cdInteriorStyle( CD_SOLID ) ;
   wdSector( _position._x, _position._y, 16.0f, 16.0f, 0.0, 360.0 ) ;
 } ;

void OptStation::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(8,8);
   max = _position + Point2d(8,8);
};
Object *OptStation::copy()
{
   return new OptStation( *this ) ;
}