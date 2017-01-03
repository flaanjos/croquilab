#include "ellipse.h"
#include "cd.h"
#include "wd.h"


Ellipse::Ellipse() : _center(0,0)
{
   _width = 1 ;
   _height = 1 ;  
   _ini_angle = 0;
   _end_angle = 360 ;
};
Ellipse::~Ellipse()
{
};


void Ellipse::center( const Point2d& c  ) 
{
   _center = c ;
}

void Ellipse::width( double w ) 
{
   _width = w ;
}
void Ellipse::height( double h ) 
{
   _height = h ;
}
void Ellipse::beginAngle( double a )
{
   _ini_angle = a ;
}
void Ellipse::endAngle( double a )
{
   _end_angle =a ;
}
const Point2d& Ellipse::center( ) const 
{
   return _center ;
}

double Ellipse::width( ) const 
{
   return _width ;
}
double Ellipse::height( ) const 
{
   return _height ;
}
double Ellipse::beginAngle( )const 
{
   return _ini_angle ;
}
double Ellipse::endAngle( )const 
{
   return _end_angle ;
}

void Ellipse::draw( const Point2d& s, const Point2d& p )  const 
{
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _center._x+p._x, _center._y+p._y, _width*s._x, _height*s._y, _ini_angle, _end_angle );
} ;

void Ellipse::draw(  )  const 
{
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _center._x, _center._y, _width, _height, _ini_angle, _end_angle );
} ;





