#include "stations.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

static float CIRCLE_RADIUS = 8.0f ;
static float CIRCLE_DIAMETER = 16.0f ;

Stations::Stations( ) : Segmented()
{
}

Stations::Stations( const Point2d &a, const Point2d &b ) : Segmented( a, b )
{
}


Stations::~Stations()
{
}


void Stations::draw( ) const 
{
   unsigned int n = (unsigned int)_points.size() ;

   cdInteriorStyle( CD_SOLID ) ;
   for( unsigned int p=0 ; p<n ; p++ )
   {
      wdSector( _points[p]._x, _points[p]._y, CIRCLE_DIAMETER, CIRCLE_DIAMETER, 0.0, 360.0 ) ;
   }

   char number[64] ;

   cdTextAlignment( CD_CENTER );
   cdForeground(CD_WHITE) ;
  
   //cdLineWidth( 1 ) ;
  // cdLineCap( CD_CAPROUND ) ;
   cdLineJoin( CD_ROUND ) ;

   wdVectorCharSize( 11 ) ; 
   //cdFont( CD_HELVETICA, CD_BOLD, 12 ); 
   for( unsigned int p=0 ; p<n&&p<9 ; p++ )
   {      
      sprintf( number, "%d", p+1 ) ;
      wdVectorText( _points[p]._x, _points[p]._y, number);
   }
   if( n>9 )
   {
      wdVectorCharSize( 9 ) ; 
      //cdFont( CD_HELVETICA, CD_BOLD, 9 ); 
      for( unsigned int p=9 ; p<n&&p<99 ; p++ )
      {
         sprintf( number, "%d", p+1 ) ;
         wdVectorText( _points[p]._x, _points[p]._y, number);
      }
   }
   if( n>99)
   {
      wdVectorCharSize( 7 ) ; 
      //cdFont( CD_HELVETICA, CD_BOLD, 7 ); 
      for( unsigned int p=99 ; p<n ; p++ )
      {
         sprintf( number, "%d", p+1 ) ;
         wdVectorText( _points[p]._x, _points[p]._y, number);
      }
   }
}


void Stations::drawSelectable( )  
{
   unsigned int n = (unsigned int)_points.size() ;
   cdInteriorStyle( CD_SOLID ) ;
   for( unsigned int p=0 ; p<n ; p++ )
   {
      wdSector( _points[p]._x, _points[p]._y, CIRCLE_DIAMETER, CIRCLE_DIAMETER, 0.0, 360.0 ) ;
   }
}

void Stations::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - CIRCLE_RADIUS ;
   min._y = _min._y - CIRCLE_RADIUS ;
   max._x = _max._x + CIRCLE_RADIUS ;
   max._y = _max._y + CIRCLE_RADIUS ;
}


Object *Stations::copy()
{
   return new Stations( *this ) ;
}