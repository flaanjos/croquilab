
#include "chains.h"
#include "cd.h"
#include "wd.h"

static double SIDE =6.0 ;
static double HALFSIDE =3.3 ;

Chains::Chains()
{
}


Chains::~Chains()
{
};


const Point2d & Chains::position( ) const
{
   return _position ;
} ;

void Chains::position( const Point2d & p ) 
{
   _position = p  ;
};


void Chains::draw( ) const
{
   double RADIUS = 8;
    
   cdLineWidth( 1 );
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _position._x, _position._y, RADIUS*3/4, RADIUS*3/4, 0, 360 );
   wdSector( _position._x+RADIUS/2, _position._y-RADIUS/4, RADIUS*3/4, RADIUS*3/4, 0, 360 );
   wdSector( _position._x+RADIUS, _position._y, RADIUS*3/4, RADIUS*3/4, 0, 360 );


} ;
void Chains::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(HALFSIDE,HALFSIDE);
   max = _position + Point2d(HALFSIDE,HALFSIDE);
};
Object *Chains::copy()
{
   return new Chains( *this ) ;
}
