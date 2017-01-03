#include "arete.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"
#include ".\arete.h"

static const double a_space = 8.4 ;
//static const double a_width = 14 ;

Arete::Arete( const Point2d &a, const Point2d &b ) : WideSegmented( a, b )
{
   _width = 14 ;
}


Arete::~Arete()
{
}


void Arete::draw( const Point2d& s ) const
{
} 


void Arete::draw( ) const 
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
         Point2d aux0 =       (p2 - p1) * a_space /  mod_lin ;
         Point2d aux2 =  p1 + (p2 - p1) * _width /  mod_lin ;

         wdLine( p1._x, p1._y, p2._x, p2._y ) ;

         Point2d aux3 = p1 ;

         for( double i=0 ; i<mod_lin ; i+= a_space )
         {
            wdLine( aux3._x, aux3._y, aux2._x + (aux3._y-aux2._y), aux2._y - (aux3._x-aux2._x) ) ; 
            wdLine( aux3._x, aux3._y, aux2._x - (aux3._y-aux2._y), aux2._y + (aux3._x-aux2._x) ) ; 

            aux3._x += aux0._x ;
            aux3._y += aux0._y ;
            aux2._x += aux0._x ;
            aux2._y += aux0._y ;
         }
      }
   }
}



Object *Arete::copy()
{
   return new Arete( *this ) ;
}



void Arete::boundingBox( Point2d& min, Point2d& max ) const 
{
   unsigned int n = (unsigned int)_points.size() ;
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   if( n <= 0 )
      return;

   updateBoundingBox( min, max, _points[0] );

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      updateBoundingBox( min, max, _points[p] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin == 0 )
      {
         mod_lin = 1 ;
      }
      
      {
         Point2d aux0 =       (p2 - p1);// * a_space /  mod_lin ;
         Point2d aux2 =  p1 + (p2 - p1) * _width /  mod_lin ;

         Point2d aux3 = p1 ;

         for( double i=0 ; i<2 ; i++ )
         {
            Point2d pA( aux2._x + (aux3._y-aux2._y), aux2._y - (aux3._x-aux2._x) ) ; 
            Point2d pB( aux2._x - (aux3._y-aux2._y), aux2._y + (aux3._x-aux2._x) ) ; 
            updateBoundingBox( min, max, pA ) ;
            updateBoundingBox( min, max, pB ) ;

            aux3._x += aux0._x ;
            aux3._y += aux0._y ;
            aux2._x += aux0._x ;
            aux2._y += aux0._y ;
         }
      }

   }
}