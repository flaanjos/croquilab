
#include "expo.h"
#include "cd.h"
#include "wd.h"



Expo::Expo() : _position ( 0, 0 )
{
}


Expo::~Expo()
{
};



const Point2d & Expo::position( ) const
{
   return _position ;
} ;

void Expo::position( const Point2d & p ) 
{
   _position = p  ;
};


void Expo::draw( ) const
{  
  int x8, y8  ;
  int x0, y0  ;
  wdWorld2Canvas( 20,20, &x8, &y8 ) ;
  wdWorld2Canvas( 0,0, &x0, &y0 ) ;
  double dx, dy ;
  cdPixel2MM( x8-x0, y8-y0, &dx, &dy ) ;
  dx = CD_MM2PT * dx ;
  dy = CD_MM2PT * dy ;
  int dyy = (int)dy ;
  char font [128] ;
  sprintf( font, "Comic sans MS, %d", dyy );
   cdNativeFont( font ); 
   //cdFont( CD_HELVETICA, CD_BOLD, 12 ); 
   cdTextAlignment( CD_CENTER );
   wdText( _position._x, _position._y, "E!"); 
}

void Expo::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(2,2);
   max = _position + Point2d(2,2);
};