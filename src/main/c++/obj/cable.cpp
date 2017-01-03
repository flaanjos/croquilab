#include "cable.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

void calc_t_point( double t, Point2d p0, Point2d p1, Point2d p2, Point2d p3, Point2d &mid ) ;

Cable::Cable( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Cable::~Cable()
{
};


void Cable::draw( const Point2d& s ) const
{
} ;

void Cable::draw( ) const 
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

      Point2d aux1( p2 - (p2 - p1) /7 ) ;
      Point2d aux2( p1 + (p2 - p1) /7 ) ;

      Point2d aux3( p2 - (p2 - p1)*12 / mod_lin ) ;
      Point2d aux4( p1 + (p2 - p1)*12 / mod_lin ) ;


      int prev_lw =cdLineWidth( lineSize()+2 ); 
      cdBegin( CD_BEZIER );
      wdVertex( p2._x, p2._y ) ;
      wdVertex( aux3._x - (p2._y-aux1._y), aux3._y + (p2._x-aux1._x) );
      wdVertex( aux4._x - (p1._y-aux2._y), aux4._y + (p1._x-aux2._x) );
      wdVertex( p1._x, p1._y ) ;
      cdEnd() ;

      cdLineWidth( lineSize() ); 
      int prev_c =cdForeground( CD_WHITE) ;
      cdBegin( CD_BEZIER );
      wdVertex( p2._x, p2._y ) ;
      wdVertex( aux3._x - (p2._y-aux1._y), aux3._y + (p2._x-aux1._x) );
      wdVertex( aux4._x - (p1._y-aux2._y), aux4._y + (p1._x-aux2._x) );
      wdVertex( p1._x, p1._y ) ;
      cdEnd() ;

      cdForeground( prev_c ) ;

      Point2d aux5( (p2 - p1)*5 / mod_lin ) ;
      aux5.rot90() ;  
      Point2d temp1( aux3._x - (p2._y-aux1._y), aux3._y + (p2._x-aux1._x) ) ;   
      Point2d temp2( aux4._x - (p1._y-aux2._y), aux4._y + (p1._x-aux2._x) );
      Point2d temp3(0,0) ;
      calc_t_point( .1, p2, temp1, temp2, p1, temp3 );
      wdLine( (temp3+aux5)._x, (temp3+aux5)._y, (temp3-aux5)._x, (temp3-aux5)._y ) ;
      calc_t_point( 0.9, p2, temp1, temp2, p1, temp3 );
      wdLine( (temp3+aux5)._x, (temp3+aux5)._y, (temp3-aux5)._x, (temp3-aux5)._y ) ;

      cdLineWidth(prev_lw) ;
   }
};
void Cable::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - 12 ;
   min._y = _min._y - 12 ;
   max._x = _max._x + 12 ;
   max._y = _max._y + 12 ;
}
Object *Cable::copy()
{
   return new Cable( *this ) ;
}

void calc_t_point( double t, Point2d p0, Point2d p1, Point2d p2, Point2d p3, Point2d &mid ) 
{
   double T = (1-t) ;

   mid  = (p0 * T*T*T) + (p1 * t*T*T * 3) + (p2 * t*t*T * 3) + (p3 * t*t*t) ;
}
