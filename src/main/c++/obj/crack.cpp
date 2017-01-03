#include "crack.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

static float CRACK_WIDTH = 4.0f ;

Crack::Crack( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Crack::~Crack()
{
};



void Crack::draw( const Point2d& s ) const
{
} 


void Crack::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin > 0 )
      {
         Point2d aux1(0,0);
         aux1._x =  -(p2._y - p1._y) * CRACK_WIDTH / mod_lin ;
         aux1._y =   (p2._x - p1._x) * CRACK_WIDTH / mod_lin ;

         Point2d aux3( (p1._x+p2._x)/2, (p1._y+p2._y)/2 ) ;
         wdLine( p1._x, p1._y, aux3._x-aux1._x, aux3._y-aux1._y ) ;
         wdLine( aux3._x-aux1._x, aux3._y-aux1._y, aux3._x+aux1._x, aux3._y+aux1._y ) ;
         wdLine( p2._x, p2._y, aux3._x+aux1._x, aux3._y+aux1._y ) ;
        }
   }
};

void Crack::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - CRACK_WIDTH ;
   min._y = _min._y - CRACK_WIDTH ;
   max._x = _max._x + CRACK_WIDTH ;
   max._y = _max._y + CRACK_WIDTH ;
}


Object *Crack::copy()
{
   return new Crack( *this ) ;
}