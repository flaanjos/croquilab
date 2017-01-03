#include "bezier.h"
#include "cd.h"
#include "wd.h"
#include "math.h"


static void calc_mid_point_net( Point2d p0, Point2d p1, Point2d p2, Point2d p3, Point2d &mid, double t ) 
{
   double   ax, bx, cx;
   double   ay, by, cy;
   double   tSquared, tCubed;

   /* calculate the polynomial coefficients */

   cx = 3.0f * (p1._x - p0._x);
   bx = 3.0f * (p2._x - p1._x) - cx;
   ax = p3._x - p0._x - cx - bx;

   cy = 3.0f * (p1._y - p0._y);
   by = 3.0f * (p2._y - p1._y) - cy;
   ay = p3._y - p0._y - cy - by;

   /* calculate the curve point at parameter value t */

   tSquared = t * t;
   tCubed = tSquared * t;

   mid._x = (ax * tCubed) + (bx * tSquared) + (cx * t) + p0._x ;
   mid._y = (ay * tCubed) + (by * tSquared) + (cy * t) + p0._y ;
}

Bezier::Bezier()
{
   _points.clear() ;
   _prev_scapes.clear() ;
   _aft_scapes.clear() ;
}


Bezier::~Bezier()
{
   _points.clear() ;
   _prev_scapes.clear() ;
   _aft_scapes.clear() ;
}


unsigned int Bezier::addPoint( unsigned int i, const Point2d& p )
{
   if(_points.size()<i)
   {
      i=(unsigned int)_points.size() ;
   }
   _points.insert(_points.begin()+i,p) ;
   _prev_scapes.insert(_prev_scapes.begin()+i,p) ;
   _aft_scapes.insert(_aft_scapes.begin()+i,p) ;
   return i ;
} 


unsigned int Bezier::removePoint( unsigned int i )
{
   if( _points.size() <= 0 )
      return 0 ;
   if( _points.size() < i )
   {
      i = (unsigned int)_points.size()-1 ;
   }
   _points.erase( _points.begin() + i ) ;
   _prev_scapes.erase( _prev_scapes.begin() + i ) ;
   _aft_scapes.erase( _aft_scapes.begin() + i ) ;
   return i ;
}


unsigned int Bezier::numPoints() const
{
   return (unsigned int)_points.size() ;
}


const Point2d& Bezier::pointVal( unsigned int i ) const
{
   return _points[i] ;
} 


void Bezier::pointScapesVals( unsigned int i, Point2d& prev, Point2d& aft ) const
{
   prev = _prev_scapes[i] ;
   aft = _aft_scapes[i] ;
}


const Point2d &Bezier::prevScapeVal( unsigned int i ) const
{
   return _prev_scapes[i] ;
}


const Point2d &Bezier::aftScapeVal( unsigned int i )const
{
   return _aft_scapes[i] ;
}


unsigned int Bezier::editPoint( unsigned int i, const Point2d& p )
{
   if( _points.size() > i )
   {
      _points[i] = p ;
      return i ;
   }
   return (unsigned int)_points.size() ;
}


unsigned int Bezier::editPointScapes( unsigned int i, const Point2d& prev, const Point2d& aft ) 
{
   if( _points.size() > i )
   {
      _prev_scapes[i] = prev ;
      _aft_scapes[i] = aft ;
      return i ;
   }
   return (unsigned int)_points.size() ;
}


void Bezier::autoBezier()
{
   int n = (int)_points.size() ;
   _aft_scapes[0] = _points[0] ;
   for( int i=1 ; i<n-1 ; i++ )
   {
      double ratio = 1 ;
      ratio = sqrt( ( _points[i-1]-_points[i]).squareSize() / ( _points[i-1]-_points[i+1]).squareSize() ) / 2 ;
      _prev_scapes[i] = _points[i] + (_points[i-1]-_points[i+1]) * ratio ;
      ratio = sqrt( ( _points[i+1]-_points[i]).squareSize() / ( _points[i-1]-_points[i+1]).squareSize() ) / 2 ;
      _aft_scapes[i] = _points[i] + (_points[i+1]-_points[i-1]) * ratio ;
   }
   _prev_scapes[n-1] = _points[n-1] ;
}


void Bezier::autoBezier( unsigned int i )
{
   if( i==0 || i==_points.size()-1 )
   {
      _prev_scapes[i] = _aft_scapes[i] = _points[i] ;
      return ;
   }
   if( i>0 && i<(_points.size()-1) )
   {
      double ratio = 1 ; 
      ratio = sqrt( ( _points[i-1]-_points[i]).squareSize() / ( _points[i-1]-_points[i+1]).squareSize() ) / 2 ;
      _prev_scapes[i] = _points[i] + (_points[i-1]-_points[i+1]) * ratio ;
      ratio = sqrt( ( _points[i+1]-_points[i]).squareSize() / ( _points[i-1]-_points[i+1]).squareSize() ) / 2 ;
      _aft_scapes[i] = _points[i] + (_points[i+1]-_points[i-1]) * ratio ;
   }
}


void Bezier::draw( const Point2d& s, const Point2d& p, Style style ) const
{
   unsigned int n = (unsigned int)_points.size() ;

   if( style == LINE )
   {
      wdBegin( CD_BEZIER  ) ;
      {
         wdVertex( _points[0]._x*s._x+p._x, _points[0]._y*s._y+p._y ) ;
         wdVertex( _aft_scapes[0]._x*s._x+p._x, _aft_scapes[0]._y*s._y+p._y ) ;
         for( unsigned int i=1 ; i<n-1 ; i++ )
         {
            wdVertex( _prev_scapes[i]._x*s._x+p._x, _prev_scapes[i]._y*s._y+p._y ) ;
            wdVertex( _points[i]._x*s._x+p._x, _points[i]._y*s._y+p._y ) ;
            wdVertex( _aft_scapes[i]._x*s._x+p._x, _aft_scapes[i]._y*s._y+p._y ) ;
         }
         wdVertex( _prev_scapes[n-1]._x*s._x+p._x, _prev_scapes[n-1]._y*s._y+p._y ) ;
         wdVertex( _points[n-1]._x*s._x+p._x, _points[n-1]._y*s._y+p._y ) ;
      }
      wdEnd() ;
   }
   else
   {
      Point2d point_t(0,0);
      cdInteriorStyle( CD_SOLID );

      wdBegin( CD_FILL ) ;
      {
         for( unsigned int i=0 ; i<n-1 ; i++ )
         {
            wdVertex( _points[i]._x*s._x+p._x, _points[i]._y*s._y+p._y ) ;

            Point2d pi( _points[i]._x*s._x+p._x, _points[i]._y*s._y+p._y ) ;
            Point2d aft( _aft_scapes[i]._x*s._x+p._x, _aft_scapes[i]._y*s._y+p._y ) ;
            Point2d prev( _prev_scapes[i+1]._x*s._x+p._x, _prev_scapes[i+1]._y*s._y+p._y ) ;
            Point2d pi1( _points[i+1]._x*s._x+p._x, _points[i+1]._y*s._y+p._y ) ;

            for( int j=0 ; j<11 ; j++ )
            {
               double t = ((double)j+1)/12 ;
               calc_mid_point_net( pi, aft, prev, pi1, point_t, t );
               wdVertex( point_t._x, point_t._y ) ;
            }
         }
         wdVertex( _points[n-1]._x, _points[n-1]._y ) ;
      }
      wdEnd();
   }
} 


void Bezier::draw( Style style ) const
{
   unsigned int n = (unsigned int)_points.size() ;

   if( style == LINE )
   {
      wdBegin( CD_BEZIER  ) ;
      {
         wdVertex( _points[0]._x, _points[0]._y ) ;
         wdVertex( _aft_scapes[0]._x, _aft_scapes[0]._y ) ;
         for( unsigned int i=1 ; i<n-1 ; i++ )
         {
            wdVertex( _prev_scapes[i]._x, _prev_scapes[i]._y ) ;
            wdVertex( _points[i]._x, _points[i]._y ) ;
            wdVertex( _aft_scapes[i]._x, _aft_scapes[i]._y ) ;
         }
         wdVertex( _prev_scapes[n-1]._x, _prev_scapes[n-1]._y ) ;
         wdVertex( _points[n-1]._x, _points[n-1]._y ) ;
      }
      wdEnd();
   }
   else // FILL
   {
      Point2d point_t(0,0);
      cdInteriorStyle( CD_SOLID );

      wdBegin( CD_FILL ) ;
      {
         for( unsigned int i=0 ; i<n-1 ; i++ )
         {
            wdVertex( _points[i]._x, _points[i]._y ) ;

            for( int j=0 ; j<3 ; j++ )
            {
               double t = ((double)j+1)/4 ;
               calc_mid_point_net( _points[i], _aft_scapes[i], _prev_scapes[i+1], _points[i+1], point_t, t );
               wdVertex( point_t._x, point_t._y ) ;
            }
         }
         wdVertex( _points[n-1]._x, _points[n-1]._y ) ;
      }
      wdEnd();
   }
} 

double Bezier::lenght(){

   double len = 0;
   Point2d point_t(0,0);
   Point2d point_a(0,0);

    unsigned int n = (unsigned int)_points.size() ;
    for( unsigned int i=0 ; i<n-1 ; i++ )
    {
      point_a = _points[i];

      for( double j=0 ; j<15 ; j+=1 )
      {
         double t = (j+1)/16.0 ;
         calc_mid_point_net( _points[i], _aft_scapes[i], _prev_scapes[i+1], _points[i+1], point_t, t );

         len += (point_t-point_a).size();
         point_a = point_t;               
      }
      len += (_points[i+1]-point_a).size();
   }
   return len;
}

void Bezier::boundingBox( Point2d& min, Point2d& max ) const 
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;
   unsigned int n = (unsigned int)_points.size() ;
         Point2d point_t(0,0);

   for( unsigned int i=0 ; i<n-1 ; i++ )
   {
      updateBoundingBox( min, max, _points[i] ) ;

      for( int j=0 ; j<3 ; j++ )
      {
         double t = ((double)j+1)/4 ;
         calc_mid_point_net( _points[i], _aft_scapes[i], _prev_scapes[i+1], _points[i+1], point_t, t );
         updateBoundingBox( min, max, point_t );
      }
   }
   updateBoundingBox( min, max, _points[n-1] );


}