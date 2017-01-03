#include "grass.h"
#include "float.h"

enum
{
   NUM_GRASS_SEGMENTS =8,
};

static float grass_coords[NUM_GRASS_SEGMENTS][2][2] =
{
   {{-12.0f/2.0f, -6.0f/2.0f},{-1.0f/2.0f, -12.0f/2.0f}},
   {{-11.0f/2.0f, 0.0f/2.0f},{-1.0f/2.0f, -11.0f/2.0f}},
   {{-8.0f/2.0f, 7.0f/2.0f},{0, -12.0f/2.0f}},
   {{-4.0f/2.0f, 12.0f/2.0f},{0, -11.0f/2.0f}},
   {{12.0f/2.0f, -6.0f/2.0f},{1.0f/2.0f, -12.0f/2.0f}},
   {{11.0f/2.0f, 0.0f/2.0f},{1.0f/2.0f, -11.0f/2.0f}},
   {{8.0f/2.0f, 7.0f/2.0f},{0, -12.0f/2.0f}},
   {{4.0f/2.0f, 12.0f/2.0f},{0, -11.0f/2.0f}}
} ;

Grass::Grass() 
{
   int i = 0 ;
   for( i=0 ; i<NUM_GRASS_SEGMENTS ; i++ ) {
      _segments[i].addPoint( 0, Point2d( grass_coords[i][0][0], grass_coords[i][0][1] ) );
      _segments[i].addPoint( 1, Point2d( grass_coords[i][1][0], grass_coords[i][1][1] ) );
   }
}
Grass::~Grass() 
{
};
const Point2d& Grass::scale( )const
{
   return _scale ;
} ;

void Grass::scale( const Point2d & s )
{
   edit( s, _position ) ;
};
const Point2d & Grass::position( ) const
{
   return _position ;
} ;
void Grass::position( const Point2d & p )
{
   edit( _scale, p ) ;
};
void Grass::edit( const Point2d & s, const Point2d &p )
{
   _position = p ;
   _scale = s ;
   int i = 0 ;
   for( i=0 ; i<NUM_GRASS_SEGMENTS ; i++ )
   {
      _segments[i].editPoint( 0, Point2d( grass_coords[i][0][0]*s._x+p._x, grass_coords[i][0][1]*s._y+p._y ) );
      _segments[i].editPoint( 1, Point2d( grass_coords[i][1][0]*s._x+p._x, grass_coords[i][1][1]*s._y+p._y ) );
   }
};
void Grass::draw( const Point2d & s, const Point2d & p )const
{
   for( int i=0 ; i<NUM_GRASS_SEGMENTS ; i++ )
   {
      _segments[i].draw(s,p) ;
   }
} ;
void Grass::draw( ) const
{
   for( int i=0 ; i<NUM_GRASS_SEGMENTS ; i++ )
   {
      _segments[i].draw() ;
   }
} ;
void Grass::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;
   for( int i=0 ; i<NUM_GRASS_SEGMENTS ; i++ )
   {
      updateBoundingBox( min, max, _segments[i].pointVal(0) );
      updateBoundingBox( min, max, _segments[i].pointVal(1) );
   }
};
Object *Grass::copy()
{
   return new Grass( *this ) ;
}
