#include "slab.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"
Slab::Slab( const Point2d &a, const Point2d &b ) : _scale(1,1)
{
   _points.push_back( a ) ;
   _points.push_back( b ) ;
}


Slab::~Slab()
{
};

const Point2d& Slab::scale( ) const
{
   return _scale;
} ;

void Slab::scale( Point2d s ) 
{
   _scale = s ;
};
void Slab::addPoint( const Point2d& p ) 
{
   _points.push_back(p);
};
const Point2d& Slab::position( unsigned int i ) const 
{
   return _points[i] ;
} ;

void Slab::position( unsigned int i, const Point2d& p ) 
{
   if( i>1 )
      return ;

   _points[i] = p ;
};
unsigned int Slab::numPoints() const
{
   return (unsigned int)_points.size() ;
};


void Slab::draw( const Point2d& s ) const
{
} ;
void Slab::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;
      double mod_x = fabs( p2._x-p1._x ) ;

      if( mod_lin == 0 )
      {
         mod_lin = 1 ;
      }
      if( mod_x == 0 )
      {
         mod_x = 1 ;
      }
      {
         Point2d aux1 =       (p2 - p1) * 4 /  mod_x ;
         Point2d aux0 =       (p2 - p1) * 12 /  mod_lin ;
         Point2d aux2 =  p1 + (p2 - p1) * 20 /  mod_lin ;

         double mody = fabs(aux1._y) ; 

         wdLine( p1._x, p1._y, p2._x, p2._y ) ;

         Point2d aux3 = p1 ;

         for( int i=0 ; i<mod_x ; i+= 4 )
         {
            wdLine( aux3._x, aux3._y, aux3._x, aux3._y - 1.5*mody  ) ; 
            wdLine( aux3._x, aux3._y  - 1.5*mody-5 , aux3._x, aux3._y - 3*mody-5   ) ; 

            aux3._x += aux1._x ;
            aux3._y += aux1._y ;
            aux2._x += aux0._x ;
            aux2._y += aux0._y ;
         }
      }
   }
};
void Slab::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   for( unsigned int i = 0 ; i< _points.size() ;i ++ )
   {
      updateBoundingBox( min, max, _points[i] );
   }
};