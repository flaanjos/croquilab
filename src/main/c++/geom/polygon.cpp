#include "polygon.h"
#include "cd.h"
#include "wd.h"


Polygon::Polygon()
{
   _points.clear() ;

};
Polygon::~Polygon()
{
   _points.clear() ;
};


unsigned int Polygon::addPoint( unsigned int i, const Point2d& p  ) 
{
   if( _points.size() < i )
   {
      i = (unsigned int)_points.size() ;
   }

   _points.insert( _points.begin() + i, p ) ;

   return i ;
};


unsigned int Polygon::removePoint( unsigned int i )
{
   if( _points.size() <= 0 )
      return 0 ;

   if( _points.size() < i )
   {
      i = (unsigned int)_points.size()-1 ;
   }

   _points.erase( _points.begin() + i ) ;

   return i ;
};

unsigned int Polygon::numPoints() const 
{
   return (unsigned int)_points.size() ;
};

const Point2d& Polygon::pointVal( unsigned int i )const
{
   return _points[i] ;
};


unsigned int Polygon::editPoint( unsigned int i, const Point2d& p )
{
   if( _points.size() > i )
   {
      _points[i] = p ;
      return true ;
   }
   return false ;
};



void Polygon::draw( const Point2d& s, const Point2d& p )  const 
{
   unsigned int n = (unsigned int)_points.size() ;
   if( n <= 1 )
   {
      return ;
   }

   if( n==2 )
   {
      wdLine( _points[0]._x*s._x+p._x, _points[0]._y*s._x+p._y, _points[1]._x*s._x+p._x, _points[1]._y*s._x+p._y ) ;
      return;
   }
   wdBegin( CD_FILL ) ;
   {
      for( unsigned int i=0 ; i<n; i++ )
      {
         wdVertex( _points[i]._x*s._x+p._x, _points[i]._y*s._x+p._y) ;
      }
   }
   wdEnd() ;
} ;

void Polygon::draw(  )  const 
{
   unsigned int n = (unsigned int)_points.size() ;
   
   if( n <= 1 )
   {
      return ;
   }
   if( n==2 )
   {
      wdLine( _points[0]._x, _points[0]._y, _points[1]._x, _points[1]._y ) ;
      return;
   }
   wdBegin( CD_FILL ) ;
   {
      
      for( unsigned int i=0 ; i<n; i++ )
      {
         wdVertex( _points[i]._x, _points[i]._y ) ;
      }
   }
   wdEnd() ;
} ;









//void calc_mid_point_flavia( Point2d p0, Point2d p1, Point2d p2, Point2d p3, Point2d &mid ) 
//{
//   mid.x =     p0.x * .125f 
//      + 3 * p1.x * .125f
//      + 3 * p2.x * .125f
//      +     p3.x * .125f ;
//
//   mid.y =     p0.y * .125f 
//      + 3 * p1.y * .125f
//      + 3 * p2.y * .125f
//      +     p3.y * .125f ;
//}

//void calc_mid_point_net( Point2d p0, Point2d p1, Point2d p2, Point2d p3, Point2d &mid, float t ) 
//{
//  // float t = 0.5f ;
//   float   ax, bx, cx;
//   float   ay, by, cy;
//   float   tSquared, tCubed;
//
//   /* calculate the polynomial coefficients */
//
//   cx = 3.0f * (p1.x - p0.x);
//   bx = 3.0f * (p2.x - p1.x) - cx;
//   ax = p3.x - p0.x - cx - bx;
//
//   cy = 3.0f * (p1.y - p0.y);
//   by = 3.0f * (p2.y - p1.y) - cy;
//   ay = p3.y - p0.y - cy - by;
//
//   /* calculate the curve point at parameter value t */
//
//   tSquared = t * t;
//   tCubed = tSquared * t;
//
//   mid.x = (ax * tCubed) + (bx * tSquared) + (cx * t) + p0.x ;
//   mid.y = (ay * tCubed) + (by * tSquared) + (cy * t) + p0.y ;
//
//}
//
//void Polygon::bezierPolygon( Line *bez_line )
//{
//   int p = 0 ;
//   int N = bez_line->numPoints() ;
//
//   _points.clear() ;
//
//   Point2d p0 = {0,0};
//   Point2d p1 = {0,0};
//   Point2d p2 = {0,0};
//   Point2d p3 = {0,0};
//
//   Point2d mid = {0,0};
//
//   float temp0 = 0 ; 
//   float temp1 = 0 ;
//
//   bez_line->pointVal( p, &(p0.x), &(p0.y) ) ;
//   bez_line->pointScapesVals( p, &temp0, &temp1, &(p1.x), &(p1.y) ) ;
//
//   for( p=1 ; p<N-1 ; p++ )
//   {
//      bez_line->pointScapesVals( p, &(p2.x), &(p2.y), &temp0, &temp1 ) ;
//      bez_line->pointVal( p, &(p3.x), &(p3.y) ) ;
//
//      _points.push_back( p0 ) ;
//      calc_mid_point_flavia( p0, p1, p2, p3, mid )  ;
//      _points.push_back( mid ) ;
//
//
//      printf( "{ %d, %d }, { %d, %d },\n", (int)p0.x, (int)p0.y, (int)mid.x, (int)mid.y ) ;
//
//      p0.x = p3.x ;
//      p0.y = p3.y ;
//
//      p1.x = temp0 ;
//      p1.y = temp1 ;
//   }
//
//};
