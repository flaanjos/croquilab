#include "block.h"
#include "float.h"
#include "cd.h"
enum
{
  NUM_FACE_POINTS  =13,
  NUM_SHADOW_POINTS =10
};

static float face_coords[NUM_FACE_POINTS][2] = 
{
   {  102.0f/20.0f,   94.0f/20.0f },
   {   62.0f/20.0f,  152.0f/20.0f },
   {   -8.0f/20.0f,  169.0f/20.0f },
   {  -73.0f/20.0f,  151.0f/20.0f },
   { -128.0f/20.0f,   67.0f/20.0f },
   { -142.0f/20.0f,   -6.0f/20.0f },
   { -106.0f/20.0f, -132.0f/20.0f },
   {  -76.0f/20.0f, -157.0f/20.0f },
   {  -41.0f/20.0f, -168.0f/20.0f },
   //{  -21.0f/20.0f, -168.0f/20.0f }
   {  -23.0f/20.0f, -168.0f/20.0f },
   {   71.0f/20.0f, -145.0f/20.0f },
   {  108.0f/20.0f, -105.0f/20.0f },
   {  120.0f/20.0f,   17.0f/20.0f },
};
static float shadow_coords[NUM_SHADOW_POINTS][2] = 
{ 
   {  -23.0f/20.0f, -168.0f/20.0f },
   {   63.0f/20.0f, -169.0f/20.0f },
   {   92.0f/20.0f, -153.0f/20.0f },
   {  137.0f/20.0f, -107.0f/20.0f },
   {  142.0f/20.0f,  -42.0f/20.0f },
   {  138.0f/20.0f,   24.0f/20.0f },
   {  101.0f/20.0f,   96.0f/20.0f },
   {  120.0f/20.0f,   17.0f/20.0f },
   {  108.0f/20.0f, -105.0f/20.0f },
   {   71.0f/20.0f, -145.0f/20.0f },
};



Block::Block() 
{
   int i =  0 ;
   for( i=0 ; i<NUM_SHADOW_POINTS ; i++ )
   {
      _shadow.addPoint( i, Point2d(shadow_coords[i][0], shadow_coords[i][1]) ) ;
   }
   for( i=0 ; i<NUM_FACE_POINTS ; i++ )
   {
      _face.addPoint( i, Point2d(face_coords[i][0], face_coords[i][1]) ) ;
   }
   _face.autoBezier() ;
}


Block::~Block()
{
};

const Point2d & Block::scale( ) const
{
   return _scale ;
} ;

void Block::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Block::position( ) const
{
   return _position ;
} ;

void Block::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Block::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   int i = 0 ;
   for( i=0 ; i<NUM_SHADOW_POINTS ; i++ )
   {
      _shadow.editPoint( i, Point2d(shadow_coords[i][0]*s._x+p._x, shadow_coords[i][1]*s._y+p._y) ) ;
   }

   for( i=0 ; i<NUM_FACE_POINTS ; i++ )
   {
      _face.editPoint( i, Point2d(face_coords[i][0]*s._x+p._x, face_coords[i][1]*s._y+p._y) ) ;
   }
   _face.autoBezier() ;
};


void Block::draw( const Point2d & s, const Point2d & p ) const
{
   _face.draw( s, p ) ;
   cdInteriorStyle( CD_SOLID ) ; 
   _shadow.draw( s, p ) ;
} ;

void Block::draw( ) const
{
   cdForeground( CD_WHITE );
   _face.draw( Bezier::FILL ) ;
   cdForeground( color() );
   _face.draw() ;
   cdInteriorStyle( CD_SOLID ) ; 
   _shadow.draw( ) ;
} ;

void Block::drawSelectable( )
{
   _face.draw( Bezier::FILL ) ;
   _face.draw() ;
   cdInteriorStyle( CD_SOLID ) ; 
   _shadow.draw( ) ;
} ;

void Block::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   for( unsigned int i = 0 ; i< _face.numPoints() ;i ++ )
   {
      updateBoundingBox( min, max, _face.pointVal(i) );
   }
   for( unsigned int i = 0 ; i< _shadow.numPoints() ;i ++ )
   {
      updateBoundingBox( min, max, _shadow.pointVal(i) );
   }
};

Object *Block::copy()
{
   return new Block( *this ) ;
}