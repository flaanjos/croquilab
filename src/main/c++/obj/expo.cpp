#include "expo.h"
#include "float.h"
#include "cd.h"
enum
{
  NUM_EXCLAMATION_BAR_POINTS  =6,
  NUM_EXCLAMATION_POINT_POINTS =5,
  NUM_LETTER_E_POINTS =14
};

static double exclamation_bar_coords[NUM_EXCLAMATION_BAR_POINTS][2] = 
{
{	5.59f/1.3f,	7.76f/1.3f },
{	7.81f/1.3f,	8.36f/1.3f },
{	6.84f/1.3f,	-4.58f/1.3f },
{	5.42f/1.3f,	-4.58f/1.3f },
{	5.37f/1.3f,	7.43f/1.3f },
{	5.37f/1.3f,	7.43f/1.3f }
};
static double exclamation_point_coords[NUM_EXCLAMATION_POINT_POINTS][2] = 
{
{	5.14f/1.3f,	-6.44f/1.3f },
{	6.84f/1.3f,	-6.06f/1.3f },
{	7.07f/1.3f,	-8.20f/1.3f },
{	5.20f/1.3f,	-8.20f/1.3f },
{	5.20f/1.3f,	-8.20f/1.3f }

};
static double letter_e_point_coords[NUM_LETTER_E_POINTS][2] = 
{ 
{	-7.58f/1.3f ,	6.28f/1.3f },
{	-7.19f/1.3f ,	-8.41f/1.3f },
{	2.13f/1.3f ,	-8.58f/1.3f },
{	1.94f/1.3f ,	-6.06f/1.3f },
{	-5.88f/1.3f ,	-6.61f/1.3f },
{	-5.99f/1.3f ,	-1.34f/1.3f },
{	2.24f/1.3f ,	-0.63f/1.3f },
{	2.19f/1.3f ,	1.29f/1.3f },
{	-5.99f/1.3f ,	0.47f/1.3f },
{	-5.80f/1.3f ,	5.71f/1.3f },
{	2.72f/1.3f ,	6.35f/1.3f },
{	2.53f/1.3f ,	8.58f/1.3f },
{	-7.81f/1.3f ,	7.21f/1.3f },
{	-7.81f/1.3f ,	7.21f/1.3f }
};



Expo::Expo() 
{
   int i =  0 ;
   for( i=0 ; i<NUM_EXCLAMATION_BAR_POINTS ; i++ )
   {
      _exclamation_bar.addPoint( i, Point2d(exclamation_bar_coords[i][0], exclamation_bar_coords[i][1]) ) ;
   }
   for( i=0 ; i<NUM_EXCLAMATION_POINT_POINTS ; i++ )
   {
      _exclamation_point.addPoint( i, Point2d(exclamation_point_coords[i][0], exclamation_point_coords[i][1]) ) ;
   }
   for( i=0 ; i<NUM_LETTER_E_POINTS ; i++ )
   {
      _letter_e.addPoint( i, Point2d(letter_e_point_coords[i][0], letter_e_point_coords[i][1]) ) ;
   }
}


Expo::~Expo()
{
};


const Point2d & Expo::position( ) const
{
   return _position ;
} ;

void Expo::position( const Point2d & p ) 
{
   _position = p ;


   int i = 0 ;
   for( i=0 ; i<NUM_EXCLAMATION_BAR_POINTS ; i++ )
   {
      _exclamation_bar.editPoint( i, Point2d(exclamation_bar_coords[i][0]+p._x, exclamation_bar_coords[i][1]+p._y) ) ;
   }
   for( i=0 ; i<NUM_EXCLAMATION_POINT_POINTS ; i++ )
   {
      _exclamation_point.editPoint( i, Point2d(exclamation_point_coords[i][0]+p._x, exclamation_point_coords[i][1]+p._y) ) ;
   }
   for( i=0 ; i<NUM_LETTER_E_POINTS ; i++ )
   {
      _letter_e.editPoint( i, Point2d(letter_e_point_coords[i][0]+p._x, letter_e_point_coords[i][1]+p._y) ) ;
   }
};



void Expo::draw( ) const
{
   cdInteriorStyle( CD_SOLID ) ; 
   long int x = cdLineJoin( CD_ROUND ) ;
   _exclamation_bar.draw(  ) ;
   _exclamation_point.draw(  ) ;
   _letter_e.draw(  ) ;
   cdLineJoin( x ) ;
} ;


void Expo::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   for( unsigned int i = 0 ; i< _exclamation_bar.numPoints() ;i ++ )
   {
      updateBoundingBox( min, max, _exclamation_bar.pointVal(i) );
   }
   for( unsigned int i = 0 ; i< _exclamation_point.numPoints() ;i ++ )
   {
      updateBoundingBox( min, max, _exclamation_point.pointVal(i) );
   }
   for( unsigned int i = 0 ; i< _letter_e.numPoints() ;i ++ )
   {
      updateBoundingBox( min, max, _letter_e.pointVal(i) );
   }
};

Object *Expo::copy()
{
   return new Expo( *this ) ;
}