#include "crystal.h"
#include "float.h"
enum
{
   NUM_CRYSTAL_POINTS = 3,
} ;

static float h_crystal_coords[NUM_CRYSTAL_POINTS][2] = 
{
   { -7.5f/3.0f,  7.5f/3.0f},
   {  2.5f/3.0f,  7.5f/3.0f},
   {  2.5f/3.0f, -2.5f/3.0f},
};
static float l_crystal_coords[NUM_CRYSTAL_POINTS][2] = 
{
   { -2.5f/3.0f,  2.5f/3.0f},
   {  7.5f/3.0f,  2.5f/3.0f},
   {  7.5f/3.0f, -7.5f/3.0f},
};



Crystal::Crystal() 
{
   int i =  0 ;
   for( i=0 ; i<NUM_CRYSTAL_POINTS ; i++ )
   {
      _high_crystal.addPoint( i, Point2d(h_crystal_coords[i][0], h_crystal_coords[i][1]) ) ;
      _low_crystal.addPoint( i, Point2d(l_crystal_coords[i][0], l_crystal_coords[i][1]) ) ;
   }
}


Crystal::~Crystal()
{
};

const Point2d & Crystal::scale( ) const
{
   return _scale ;
} ;

void Crystal::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Crystal::position( ) const
{
   return _position ;
} ;

void Crystal::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Crystal::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   int i = 0 ;
   for( i=0 ; i<NUM_CRYSTAL_POINTS ; i++ )
   {
      _high_crystal.editPoint( i, Point2d(h_crystal_coords[i][0]*s._x+p._x, h_crystal_coords[i][1]*s._y+p._y) ) ;
      _low_crystal.editPoint( i, Point2d(l_crystal_coords[i][0]*s._x+p._x, l_crystal_coords[i][1]*s._y+p._y) ) ;
   }
};


void Crystal::draw( const Point2d & s, const Point2d & p  ) const
{
   _high_crystal.draw( s, p ) ;
   _low_crystal.draw( s, p ) ;
} ;

void Crystal::draw( ) const
{
   _high_crystal.draw() ;
   _low_crystal.draw() ;
} ;

void Crystal::boundingBox( Point2d& min, Point2d& max ) const 
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   for( unsigned int i = 0 ; i< _high_crystal.numPoints() ; i++ )
   {
      updateBoundingBox( min, max, _high_crystal.pointVal(i) );
   }
   for( unsigned int i = 0 ; i< _low_crystal.numPoints() ; i++ )
   {
      updateBoundingBox( min, max, _low_crystal.pointVal(i) );
   }
};
Object *Crystal::copy()
{
   return new Crystal( *this ) ;
}