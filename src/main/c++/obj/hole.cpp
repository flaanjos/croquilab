#include "hole.h"
#include "cd.h"
#include "wd.h"

static int _x_ = 0 ;
static int _y_ = 1 ;

enum 
{
   NUM_HOLE_LINES = 14,
} ;

static int _p1_ = 0 ;
static int _p2_ = 1 ;

static float hole_coords[NUM_HOLE_LINES][2][2] =
{
   { {  -94.5f/20.0f, -177.0f/20.0f }, {  -66.5f/20.0f, -113.0f/20.0f } },
   { {  -17.5f/20.0f, -194.0f/20.0f }, {   -7.5f/20.0f, -127.0f/20.0f } },
   { {   68.5f/20.0f, -182.0f/20.0f }, {   50.5f/20.0f, -114.0f/20.0f } },
   { {  147.5f/20.0f, -137.0f/20.0f }, {   83.5f/20.0f,  -87.0f/20.0f } },
   { {  186.5f/20.0f,  -47.0f/20.0f }, {  112.5f/20.0f,  -42.0f/20.0f } },
   { {  188.5f/20.0f,    1.0f/20.0f }, {  120.5f/20.0f,   -1.0f/20.0f } },
   { {  152.5f/20.0f,   95.0f/20.0f }, {  104.5f/20.0f,   59.0f/20.0f } },
   { {  143.5f/20.0f,  149.0f/20.0f }, {   79.5f/20.0f,   90.0f/20.0f } },
   { {   73.5f/20.0f,  175.0f/20.0f }, {   36.5f/20.0f,  118.0f/20.0f } },
   { {  -25.5f/20.0f,  194.0f/20.0f }, {   -8.5f/20.0f,  124.0f/20.0f } },
   { { -106.5f/20.0f,  152.0f/20.0f }, {  -70.5f/20.0f,  108.0f/20.0f } },
   { { -172.5f/20.0f,  100.0f/20.0f }, { -105.5f/20.0f,   76.0f/20.0f } },
   { { -188.5f/20.0f,   -5.0f/20.0f }, { -133.5f/20.0f,   -4.0f/20.0f } },
   { { -165.5f/20.0f, -119.0f/20.0f }, { -112.5f/20.0f,  -71.0f/20.0f } },
};
static float hole_boundingbox[2][2]=
{ {  -188.5f/20.0f, -194.0f/20.0f }, {  188.5f/20.0f, 194.0f/20.0f } } ;


Hole::Hole()
{
}

Hole::~Hole()
{
};

const Point2d & Hole::scale( ) const
{
   return _scale ;
} ;

void Hole::scale( const Point2d & s ) 
{
   _scale = s ;
};

const Point2d & Hole::position( ) const
{
   return _position ;
} ;

void Hole::position( const Point2d & p ) 
{
   _position = p ;
};

void Hole::edit(const Point2d &s, const Point2d & p ) 
{
   _scale = s ;
   _position = p ;
};

void Hole::draw( const Point2d &s, const Point2d & p) const 
{
   Point2d ss( _scale._x*s._x, _scale._y*s._y );
   Point2d pp( _position._x*s._x + p._x, _position._y*s._y + p._y );
   
   int grey = cdEncodeColor( 180, 180, 180 );
   int color = cdForeground( grey );

   cdInteriorStyle( CD_SOLID ) ; 
   wdSector( _position._x+pp._x, _position._y+pp._y, 188.5f/20.0f*ss._x, 194.0f/20.0f*ss._y, 0, 360 );
   
   cdForeground( color );
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _position._x+pp._x, _position._y+pp._y, 188.5f/20.0f*ss._x, 194.0f/20.0f*ss._y, 0, 360 );

} ;

void Hole::draw( ) const
{
   int grey = cdEncodeColor( 160, 160, 160 );
   int color = cdForeground( grey );

   cdInteriorStyle( CD_SOLID ) ; 
   wdSector( _position._x, _position._y, 188.5f/10.0f*_scale._x, 194.0f/10.0f*_scale._y, 0, 360 );
   
   grey = cdEncodeColor( 220, 220, 220 );
   cdForeground( grey );
   double aaaa = 188.5f/10.0f*_scale._x -10;
   double bbbbb =  194.0f/10.0f*_scale._y-10;
   wdSector( _position._x, _position._y, aaaa,bbbbb, 0, 360 );


   cdForeground( color );
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _position._x, _position._y, 188.5f/10.0f*_scale._x, 194.0f/10.0f*_scale._y, 0, 360 );



  //for( int l=0 ; l<NUM_HOLE_LINES ; l++ )
  // {
  //    wdLine( hole_coords[l][_p1_][_x_]*_scale._x+_position._x,
  //            hole_coords[l][_p1_][_y_]*_scale._y+_position._y,
  //            hole_coords[l][_p2_][_x_]*_scale._x+_position._x,         
  //            hole_coords[l][_p2_][_y_]*_scale._y+_position._y ) ;
  // }
} ;



void Hole::drawSelectable( ) 
{
   cdInteriorStyle( CD_SOLID ) ; 
   wdSector( _position._x, _position._y, 188.5f/10.0f*_scale._x, 194.0f/10.0f*_scale._y, 0, 360 );
} ;



void Hole::boundingBox( Point2d& min, Point2d& max ) const 
{
  min._x = hole_boundingbox[_p1_][_x_]*_scale._x+_position._x ;
  min._y = hole_boundingbox[_p1_][_y_]*_scale._y+_position._y ;

  max._x = hole_boundingbox[_p2_][_x_]*_scale._x+_position._x ;
  max._y = hole_boundingbox[_p2_][_y_]*_scale._y+_position._y ;
};
Object *Hole::copy()
{
   return new Hole( *this ) ;
}