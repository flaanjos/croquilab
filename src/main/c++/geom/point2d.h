#pragma once
#ifndef __POINT_2_DOUBLE__H__
#define __POINT_2_DOUBLE__H__ 0

#include "math.h"

class Point2d 
{
public:
   Point2d( ) { _x=0; _y=0; } ;
   Point2d( int x, int y ) { _x=(double)x ; _y=(double)y ; } ;
   Point2d( float x, float y ) { _x=(double)x ; _y=(double)y ; } ;
   Point2d( double x, double y ) { _x=x ; _y=y ; } ;
   Point2d( const Point2d &p )
   {
      _x=p._x ;
      _y= p._y ;
   };
   const Point2d& operator=( const Point2d&p )
   {
      _x=p._x ;
      _y= p._y ;
      return *this ;
   };

   double squareSize() const
   {
      return  _x*_x+_y*_y  ; 
   } ;

   double size() const
   {
      return  sqrt(_x*_x+_y*_y)  ; 
   } ;

   void rot90 ()
   {
      double t = _x ;
      _x = _y ;
      _y = -t ;
   };

   void normalize()
   {
      double s = size() ;
      _x = _x / s;
      _y = _y / s;
   }

   ~Point2d( ) {} ;
   double _x ;
   double _y ;
}  ;

bool operator==( const Point2d&a, const Point2d&b );
const Point2d operator+( const Point2d&a, const Point2d&b );
const Point2d operator-( const Point2d&a, const Point2d&b );
const Point2d operator/( const Point2d&a, double v);
const Point2d operator*( const Point2d&a, double v);

//const Point2d operator/( const Point2d&a, const Point2d&b );
//const Point2d operator*( const Point2d&a, const Point2d&b );

double dot( const Point2d&a, const Point2d&b );



void updateBoundingBox( Point2d& bb_min, Point2d& bb_max, const Point2d& p );

#endif


