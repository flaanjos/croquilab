#include "polygonal.h"
#include "cd.h"
#include "wd.h"



Polygonal::Polygonal( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Polygonal::~Polygonal()
{
}

void Polygonal::draw( const Point2d& s ) const
{
}


void Polygonal::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   if( n <= 1 )
   {
      return ;
   }

   if( n==2 )
   {
      wdLine( _points[0]._x, _points[0]._y, _points[1]._x, _points[1]._y ) ;
      return ;
   }

   cdInteriorStyle( CD_SOLID ) ;  
   wdBegin( CD_FILL ) ;
   {
      
      for( unsigned int i=0 ; i<n; i++ )
      {
         wdVertex( _points[i]._x, _points[i]._y ) ;
      }
   }
   wdEnd() ;
}


Object *Polygonal::copy()
{
   return new Polygonal( *this ) ;
}


