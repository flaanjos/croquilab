#include "route_line.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
#include "float.h"

RouteLine::RouteLine( const Point2d &a, const Point2d &b ) : Curved( a, b )
{
}


RouteLine::~RouteLine()
{
}

void RouteLine::draw( const Point2d& s ) const
{
}


void RouteLine::draw( ) const 
{
   _curve.draw() ;
   cdForeground( cdEncodeColor( 128,128,128) );


   //wdBegin( CD_OPEN_LINES );
   //wdVertex( _min_point._x, _min_point._y );
   //wdVertex( _max_point._x, _min_point._y );
   //wdVertex( _max_point._x, _max_point._y );
   //wdVertex( _min_point._x, _max_point._y );
   //wdVertex( _min_point._x, _min_point._y );
   //wdEnd();

   //wdBegin( CD_OPEN_LINES );
   //wdVertex( _min_scape._x, _min_scape._y );
   //wdVertex( _max_scape._x, _min_scape._y );
   //wdVertex( _max_scape._x, _max_scape._y );
   //wdVertex( _min_scape._x, _max_scape._y );
   //wdVertex( _min_scape._x, _min_scape._y );
   //wdEnd();

   //wdBegin( CD_OPEN_LINES );
   //wdVertex( _min._x, _min._y );
   //wdVertex( _max._x, _min._y );
   //wdVertex( _max._x, _max._y );
   //wdVertex( _min._x, _max._y );
   //wdVertex( _min._x, _min._y );
   //wdEnd();

  
}


void RouteLine::drawSelectable( ) 
{
   cdLineStyle( CD_CONTINUOUS ) ;
   _curve.draw() ;
}


Object *RouteLine::copy()
{
   return new RouteLine( *this ) ;
}