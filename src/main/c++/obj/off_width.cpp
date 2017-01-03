#include "off_width.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

static float OFFWIDTH_WIDTH = 4.0f ;

OffWidth::OffWidth( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


OffWidth::~OffWidth()
{
}



void OffWidth::draw( const Point2d& s ) const
{
}


void OffWidth::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   for( unsigned int p=1 ; p<n ; p++ )
   {
      Point2d p2( _points[p] ) ;
      Point2d p1( _points[p-1] );

      double mod_lin = sqrt( (p2-p1).squareSize() ) ;

      if( mod_lin > 0 )
      {
         Point2d perp(0,0);
         perp._x =  (p2._y - p1._y) * OFFWIDTH_WIDTH / mod_lin ;
         perp._y = -(p2._x - p1._x) * OFFWIDTH_WIDTH / mod_lin ;

         Point2d parl(( p2 - p1) * OFFWIDTH_WIDTH / mod_lin );

         Point2d mid( (p1._x+p2._x)/2, (p1._y+p2._y)/2 ) ;


         wdLine( p1._x-perp._x,p1._y - perp._y, mid._x-parl._x, mid._y-parl._y ) ;
         wdLine( mid._x-parl._x,mid._y-parl._y, mid._x-2*perp._x-parl._x, mid._y-2*perp._y-parl._y ) ;
         wdLine( mid._x-parl._x-2*perp._x,mid._y-parl._y-2*perp._y, p2._x-perp._x, p2._y-perp._y ) ;

         wdLine( p1._x + perp._x,p1._y + perp._y, mid._x+parl._x+2*perp._x, mid._y+parl._y+2*perp._y ) ;
         wdLine( mid._x+parl._x+2*perp._x,mid._y+parl._y+2*perp._y, mid._x+parl._x, mid._y+parl._y ) ;
         wdLine( mid._x+parl._x,mid._y+parl._y, p2._x+perp._x, p2._y+perp._y ) ;
      }
   }
}


void OffWidth::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - OFFWIDTH_WIDTH ;
   min._y = _min._y - OFFWIDTH_WIDTH ;
   max._x = _max._x + OFFWIDTH_WIDTH ;
   max._y = _max._y + OFFWIDTH_WIDTH ;
}



Object *OffWidth::copy()
{
   return new OffWidth( *this ) ;
}