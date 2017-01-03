#include "chimney.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

//static const double c_total_width = 24 ;
//static const double c_center_width = 14 ;
static const double c_width_diff = 10 ;

Chimney::Chimney( const Point2d &a, const Point2d &b ) : WideSegmented( a, b )
{
   _width = 14 ;
}


Chimney::~Chimney()
{
};



void Chimney::draw( const Point2d& s ) const
{
} ;

void Chimney::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin == 0 )
      {
         mod_lin = 1 ;
      }
      {
         Point2d aux1 =  p2 + (p2 - p1) * (_width + c_width_diff) /  mod_lin ;
         Point2d aux2 =  p1 - (p2 - p1) * (_width + c_width_diff) /  mod_lin ;
         Point2d aux3 =  p2 + (p2 - p1) * _width /  mod_lin ;
         Point2d aux4 =  p1 - (p2 - p1) * _width /  mod_lin ;

         Point2d aux5 =  p2+aux1-aux3 ;
         Point2d aux6 =  aux2+p1-aux4 ;

         wdBegin( CD_OPEN_LINES );
         wdVertex( (aux5._x + (p2._y-aux1._y)), (aux5._y - (p2._x-aux1._x) ) );
         wdVertex( (p2._x   + (p2._y-aux3._y)), (p2._y   - (p2._x-aux3._x) ) );
         wdVertex( (p1._x   - (p1._y-aux4._y)), (p1._y   + (p1._x-aux4._x) ) );
         wdVertex( (aux6._x - (p1._y-aux2._y)), (aux6._y + (p1._x-aux2._x) ) );
         wdEnd() ;

         wdBegin( CD_OPEN_LINES );
         wdVertex( (aux5._x - (p2._y-aux1._y)), (aux5._y + (p2._x-aux1._x) ) );
         wdVertex( (p2._x - (p2._y-aux3._y)), (p2._y + (p2._x-aux3._x) ) );
         wdVertex( (p1._x + (p1._y-aux4._y)), (p1._y - (p1._x-aux4._x) ) );
         wdVertex( (aux6._x + (p1._y-aux2._y)), (aux6._y - (p1._x-aux2._x) ) );
         wdEnd() ;
      }
   }
}

void Chimney::boundingBox( Point2d& min, Point2d& max ) const
{
   unsigned int n = (unsigned int)_points.size() ;
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   if( n <= 0 )
      return;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin == 0 )
      {
         mod_lin = 1 ;
      }
      {
         Point2d aux1 =  p2 + (p2 - p1) * (_width + c_width_diff) /  mod_lin ;
         Point2d aux2 =  p1 - (p2 - p1) * (_width + c_width_diff) /  mod_lin ;
         Point2d aux3 =  p2 + (p2 - p1) * _width /  mod_lin ;
         Point2d aux4 =  p1 - (p2 - p1) * _width /  mod_lin ;

         Point2d aux5 =  p2 + aux1 - aux3 ;
         Point2d aux6 =  aux2 + p1 - aux4 ;

         updateBoundingBox( min, max, Point2d( (aux5._x + (p2._y-aux1._y)), (aux5._y - (p2._x-aux1._x)) ) ) ;
         updateBoundingBox( min, max, Point2d( (aux6._x - (p1._y-aux2._y)), (aux6._y + (p1._x-aux2._x)) ) ) ;
         updateBoundingBox( min, max, Point2d( (aux5._x - (p2._y-aux1._y)), (aux5._y + (p2._x-aux1._x)) ) ) ;
         updateBoundingBox( min, max, Point2d( (aux6._x + (p1._y-aux2._y)), (aux6._y - (p1._x-aux2._x)) ) ) ;
      }
   }
}


Object *Chimney::copy()
{
   return new Chimney( *this ) ;
}