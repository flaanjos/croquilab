#include "Arrow.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"


Arrow::Arrow( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Arrow::~Arrow()
{
}



void Arrow::draw( const Point2d& s ) const
{
}


void Arrow::draw() const
{
   unsigned int n = (unsigned int)_points.size() ;

   int old_w = cdLineWidth(lineSize()); 
   wdBegin( CD_OPEN_LINES );
   for( unsigned int p=0 ; p<n ; p++ )
   {
      wdVertex( _points[p]._x, _points[p]._y ) ;
   }
   wdEnd() ;


   Point2d p2( _points[n-1] ) ;
   Point2d p1( _points[n-2] );

   double mod_lin = sqrt( (p2-p1).squareSize() ) ;
   if( mod_lin == 0 )
   {
      mod_lin = 1 ;
   }
   Point2d aux0 =  p2 - (p2 - p1) * 8 /  mod_lin ;
   Point2d aux2 =  p2 - (p2 - p1) * 5 /  mod_lin ;

   
   wdLine( p1._x, p1._y, p2._x, p2._y ) ;

   Point2d aux3 = p2 ;

   wdLine( aux3._x, aux3._y, aux0._x + (aux3._y-aux2._y), aux0._y - (aux3._x-aux2._x) ) ; 
   wdLine( aux3._x, aux3._y, aux0._x - (aux3._y-aux2._y), aux0._y + (aux3._x-aux2._x) ) ; 

   cdLineWidth(old_w); 
}


Object *Arrow::copy()
{
   return new Arrow( *this ) ;
}
