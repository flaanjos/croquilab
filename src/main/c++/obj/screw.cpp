
#include "screw.h"
#include "cd.h"
#include "wd.h"

static double RADIUS = 6.5 ; //8.0/1.5 ;
static double HALFRADIUS = 6.5/2 ; //8.0/3.0 ;
static double HALFCROSSWIDTH = .3/1.5 ;  
static double HALCROSSLENGHT = 2.0/1.4 ; 

//Screw::Screw( const Point2d& position ) 
//{
//   _position = position ;
//}

Screw::Screw()
{
}


Screw::~Screw()
{
};



const Point2d & Screw::position( ) const
{
   return _position ;
} ;

void Screw::position( const Point2d & p ) 
{
   _position = p  ;
};


void Screw::draw( ) const
{
   cdForeground( CD_WHITE );
   cdInteriorStyle( CD_SOLID ) ;
   wdSector( _position._x, _position._y, RADIUS, RADIUS, 0.0, 360.0 ) ;

   cdForeground( this->color() );
   cdInteriorStyle( CD_HOLLOW ) ;
   wdSector( _position._x, _position._y, RADIUS, RADIUS, 0.0, 360.0 ) ;

   cdInteriorStyle( CD_SOLID ) ;

   wdBox( _position._x-HALCROSSLENGHT, _position._x+HALCROSSLENGHT,  _position._y-HALFCROSSWIDTH, _position._y+HALFCROSSWIDTH ) ;
   wdBox( _position._x-HALFCROSSWIDTH, _position._x+HALFCROSSWIDTH,  _position._y-HALCROSSLENGHT, _position._y+HALCROSSLENGHT ) ;

} ;

void Screw::drawSelectable( ) 
{
   cdInteriorStyle( CD_SOLID ) ;
   wdSector( _position._x, _position._y, RADIUS, RADIUS, 0.0, 360.0 ) ;
} ;

void Screw::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(HALFRADIUS,HALFRADIUS);
   max = _position + Point2d(HALFRADIUS,HALFRADIUS);
};
Object *Screw::copy()
{
   return new Screw( *this ) ;
}
