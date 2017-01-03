#include "cactus.h"
#include "float.h"
#include "cd.h"
#include "wd.h"
#include "math.h"
enum
{
   NUM_CACTUS_POINTS =6,
};
int Cactus::_next_seed = 1 ;
static float cactus_coords[NUM_CACTUS_POINTS][2] = 
{
   { -14.0f/4, -30.0f/3},
   { 0.0f/4, -24.0f/3},
   { 2.0f/4, 46.0f/3},
   { 14.0f/4, 45.0f/3},
   { 9.0f/4, -31.0f/3},
{	-9.0f/4	,	-46.0f/3},

} ;
static float cactus_prev_scapes[NUM_CACTUS_POINTS][2] =
{
   { -14.0f/4, -30.0f/3},
   { -2.0f/4, -31.0f/3},
   { 0.0f/4, 15.0f/3},
   { 14.0f/4, 51.0f/3},
   { 14.0f/4, -16.0f/3},
   {	-1.0f/4	,	-38.0f/3},
};

static float cactus_aft_scapes[NUM_CACTUS_POINTS][2] = 
{
   { -10.0f/4, -32.0f/3},
   { 5.0f/4, -4.0f/3},
   { 3.0f/4, 51.0f/3},
   { 19.0f/4, 0.0f/3},
   { 4.0f/4, -37.0f/3},
   {	-9.0f/4	,	-46.0f/3},
};
			



Cactus::Cactus() 
{
   _seed = _next_seed ;
   int i =  0 ;

   for( i=0 ; i<NUM_CACTUS_POINTS ; i++ )
   {
      _points.addPoint( i, Point2d( cactus_coords[i][0], cactus_coords[i][1] ) );
      _points.editPointScapes( i, Point2d( cactus_prev_scapes[i][0], cactus_prev_scapes[i][1] ), 
                                  Point2d( cactus_aft_scapes [i][0], cactus_aft_scapes [i][1] ) ) ; 
   }
   _next_seed ++ ;
}

Cactus::~Cactus()
{
};

const Point2d & Cactus::scale( ) const
{
   return _scale ;
} ;

void Cactus::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Cactus::position( ) const
{
   return _position ;
} ;

void Cactus::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Cactus::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   Point2d ss = _scale = s ;
   //if( s._x > 3*s._y )
   //{
   //   ss._x = _scale._x = 3*s._y ;
   //}

   int i = 0 ;
   for( i=0 ; i<NUM_CACTUS_POINTS ; i++ )
   {
      _points.editPoint      ( i, Point2d( cactus_coords     [i][0]*ss._x+p._x, cactus_coords     [i][1]*ss._y+p._y ) );
      _points.editPointScapes( i, Point2d( cactus_prev_scapes[i][0]*ss._x+p._x, cactus_prev_scapes[i][1]*ss._y+p._y ), 
                                  Point2d( cactus_aft_scapes [i][0]*ss._x+p._x, cactus_aft_scapes [i][1]*ss._y+p._y ) ) ; 
   }
};

void Cactus::draw( const Point2d & s, const Point2d & p )const 
{
   _points.draw( s, p ) ;
} ;

void Cactus::draw( ) const
{
   cdForeground( CD_WHITE );
   _points.draw( Bezier::FILL ) ;
   cdForeground( color() );
   _points.draw() ;

   Point2d min(  1.0f, -29.0f/2 ) ;
   Point2d max(  12.0f/4, 46.0f/3 ) ;

   double area= (max._y-min._y)*_scale._y * (max._x-min._x)*_scale._x ;
   int n = (int)(sqrt(area)/4) ;

   min._x = min._x*_scale._x+_position._x;
   max._x = max._x*_scale._x+_position._x;
   min._y = min._y*_scale._y+_position._y;
   max._y = max._y*_scale._y+_position._y;

   srand( _seed ) ;
   if( n<10 )
      n=10 ;
      
   for( int i=0 ; i<n;i++ )
   {
      double rx1 = (double)rand() / RAND_MAX ;
      double ry1 = (double)rand() / RAND_MAX ;      
      double rx2 = (double)rand() / RAND_MAX ;
      double ry2 = (double)rand() / RAND_MAX ;

      Point2d ini( rx1*(max._x-min._x) + min._x, ry1*(max._y-min._y) + min._y ) ;
      Point2d fim( ini._x + rx2*3*_scale._x-1.5*_scale._x, ini._y + ry2*3*_scale._y-1.5*_scale._y ) ;

      wdLine( ini._x, ini._y, fim._x, fim._y ) ;
   }
} ;

void Cactus::drawSelectable( ) 
{
   _points.draw( Bezier::FILL ) ;
   _points.draw() ;

   Point2d min(  1.0f, -29.0f/2 ) ;
   Point2d max(  12.0f/4, 46.0f/3 ) ;

   double area= (max._y-min._y)*_scale._y * (max._x-min._x)*_scale._x ;
   int n = (int)(sqrt(area)/4) ;

   min._x = min._x*_scale._x+_position._x;
   max._x = max._x*_scale._x+_position._x;
   min._y = min._y*_scale._y+_position._y;
   max._y = max._y*_scale._y+_position._y;

   srand( _seed ) ;
   if( n<10 )
      n=10 ;
      
   for( int i=0 ; i<n;i++ )
   {
      double rx1 = (double)rand() / RAND_MAX ;
      double ry1 = (double)rand() / RAND_MAX ;      
      double rx2 = (double)rand() / RAND_MAX ;
      double ry2 = (double)rand() / RAND_MAX ;

      Point2d ini( rx1*(max._x-min._x) + min._x, ry1*(max._y-min._y) + min._y ) ;
      Point2d fim( ini._x + rx2*3*_scale._x-1.5*_scale._x, ini._y + ry2*3*_scale._y-1.5*_scale._y ) ;

      wdLine( ini._x, ini._y, fim._x, fim._y ) ;
   }
} ;

void Cactus::boundingBox( Point2d& min, Point2d& max ) const 
{
   _points.boundingBox( min, max );
};

Object *Cactus::copy()
{
   return new Cactus( *this ) ;
}
