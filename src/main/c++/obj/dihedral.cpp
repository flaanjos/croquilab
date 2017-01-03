#include "dihedral.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

//static const double d_width = 14 ;

Dihedral::Dihedral( const Point2d &a, const Point2d &b ) : WideSegmented( a, b )
{
   _width = 14 ;
}


Dihedral::~Dihedral()
{
};



void Dihedral::draw( const Point2d& s ) const
{
} ;

void Dihedral::draw( ) const 
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
         Point2d aux1 =  p2 - ( (p2-p1) * _width ) /  mod_lin ;
         Point2d aux2 =  p1 - ( (p2-p1) * _width ) /  mod_lin ;

         wdBegin( CD_CLOSED_LINES );

         wdVertex( aux1._x - (p2._y-aux1._y), aux1._y + (p2._x-aux1._x) );
         wdVertex( p2._x, p2._y ) ;
         wdVertex( aux1._x + (p2._y-aux1._y), aux1._y - (p2._x-aux1._x) );

         wdVertex( aux2._x + (p1._y-aux2._y), aux2._y - (p1._x-aux2._x) );
         wdVertex( p1._x, p1._y ) ;
         wdVertex( aux2._x - (p1._y-aux2._y), aux2._y + (p1._x-aux2._x) );

         wdEnd() ;
         wdLine(  p1._x, p1._y ,  p2._x, p2._y ) ;
      }
   }
}


Object *Dihedral::copy()
{
   return new Dihedral( *this ) ;
}


void Dihedral::boundingBox( Point2d& min, Point2d& max ) const 
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
         Point2d aux1 =  p2 - ( (p2-p1) * _width ) /  mod_lin ;
         Point2d aux2 =  p1 - ( (p2-p1) * _width ) /  mod_lin ;


        updateBoundingBox( min, max, Point2d( aux1._x - (p2._y-aux1._y), aux1._y + (p2._x-aux1._x) ));
        updateBoundingBox( min, max, Point2d( p2._x, p2._y ) );
        updateBoundingBox( min, max, Point2d( aux1._x + (p2._y-aux1._y), aux1._y - (p2._x-aux1._x) ));

         updateBoundingBox( min, max,Point2d( aux2._x + (p1._y-aux2._y), aux2._y - (p1._x-aux2._x) ));
        updateBoundingBox( min, max, Point2d( p1._x, p1._y ) );
       updateBoundingBox( min, max,  Point2d( aux2._x - (p1._y-aux2._y), aux2._y + (p1._x-aux2._x) ));

      }
   }
}