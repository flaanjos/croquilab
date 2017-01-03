#include "point2d.h"

bool operator==( const Point2d&a, const Point2d&b )
{
   if( a._x==b._x && a._y == b._y )
      return true ;
   return false ;
};
const Point2d operator+( const Point2d&a, const Point2d&b )
{
   return Point2d( a._x+b._x, a._y+b._y ) ;
};
const Point2d operator-( const Point2d&a, const Point2d&b )
{
   return Point2d( a._x-b._x, a._y-b._y ) ;
};
const Point2d operator/( const Point2d&a, double v)
{
   return Point2d( a._x/v, a._y/v ) ;
};
const Point2d operator*( const Point2d&a, double v)
{
   return Point2d( a._x*v, a._y*v ) ;
};

double dot( const Point2d&a, const Point2d&b )
{
   return a._x * b._x + a._y * b._y ;
};

void updateBoundingBox( Point2d& bb_min, Point2d& bb_max, const Point2d& p )
{
   if( p._x < bb_min._x )
      bb_min._x = p._x ;

   if( p._x > bb_max._x )
      bb_max._x = p._x ;

   if( p._y < bb_min._y )
      bb_min._y = p._y ;

   if( p._y > bb_max._y )
      bb_max._y = p._y ;

};

