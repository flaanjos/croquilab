#include "oposition.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

static const double o_space = 5.6 ;
static const double o_width = 7 ;

Oposition::Oposition( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Oposition::~Oposition()
{
}


void Oposition::draw( const Point2d& s ) const
{
}


void Oposition::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin > 0 )
      {

         Point2d aux1 = (p2 - p1) * o_space /  mod_lin ;

         Point2d aux2(0,0) ;
         aux2._x = -aux1._y / o_space * o_width ;
         aux2._y =  aux1._x / o_space * o_width ;

         Point2d aux3 = p1 ;

         wdLine( p1._x, p1._y, p2._x, p2._y ) ;
         wdLine( p2._x, p2._y, p2._x+aux2._x, p2._y+aux2._y ) ;

         for( double i=0 ; i<(mod_lin) ; i+=o_space )
         {
            wdLine( aux3._x, aux3._y, aux3._x+aux2._x, aux3._y+aux2._y ) ;
            aux3._x += aux1._x ;
            aux3._y += aux1._y ;
         }
      }
   }
}


void Oposition::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - o_width ;
   min._y = _min._y - o_width ;
   max._x = _max._x + o_width ;
   max._y = _max._y + o_width ;
}


Object *Oposition::copy()
{
   return new Oposition( *this ) ;
}