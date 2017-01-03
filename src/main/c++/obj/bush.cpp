#include "bush.h"
#include "float.h"
enum
{
   NUM_BUSH_POINTS =12,
   NUM_BUSH_LEAVES_POINTS = 4
};

static float bush_coords[NUM_BUSH_POINTS][2] = 
{
   {-112.50f/10.0f,	 -48.50f/10.0f },
   { -80.50f/10.0f,	   5.50f/10.0f },
   { -46.50f/10.0f,	  57.50f/10.0f },
   {  15.50f/10.0f,	  68.50f/10.0f },
   {  81.50f/10.0f,	  44.50f/10.0f },
   { 112.50f/10.0f,	  -3.50f/10.0f },
   {  99.50f/10.0f,	 -39.50f/10.0f },
   {  81.50f/10.0f,	 -62.50f/10.0f },
   {  20.50f/10.0f,	 -68.50f/10.0f },
   { -36.50f/10.0f,	 -65.50f/10.0f },
   { -80.50f/10.0f,	 -57.50f/10.0f },
   {-112.50f/10.0f,	 -48.50f/10.0f }
} ;
static float bush_prev_scapes[NUM_BUSH_POINTS][2] =
{
   {       0,	      0 },
   {-103.50f/10.0f,	 22.50f/10.0f },
   { -58.50f/10.0f,	 92.50f/10.0f },
   {  -5.50f/10.0f,	103.50f/10.0f },
   { 105.50f/10.0f,	 76.50f/10.0f },
   { 148.50f/10.0f,	 23.50f/10.0f },
   { 126.50f/10.0f,	-46.50f/10.0f },
   {  94.50f/10.0f,	-57.50f/10.0f },
   {  41.50f/10.0f,	-67.50f/10.0f },
   { -15.50f/10.0f,	-66.50f/10.0f },
   { -72.50f/10.0f,	-68.50f/10.0f },
   {-110.50f/10.0f,	-51.50f/10.0f }
};

static float bush_aft_scapes[NUM_BUSH_POINTS][2] = 
{
   {-151.50f/10.0f,	-10.50f/10.0f },
   {-113.50f/10.0f,	 56.50f/10.0f },
   { -43.50f/10.0f,	 91.50f/10.0f },
   {  21.50f/10.0f,	118.50f/10.0f },
   { 118.50f/10.0f,	 68.50f/10.0f },
   { 135.50f/10.0f,	-16.50f/10.0f },
   { 114.50f/10.0f,	-66.50f/10.0f },
   {  71.50f/10.0f,	-66.50f/10.0f },
   {  -2.50f/10.0f,	-69.50f/10.0f },
   { -41.50f/10.0f,	-64.50f/10.0f },
   { -81.50f/10.0f,	-55.50f/10.0f },
   {       0,	      0 },
};

static float bush_leaves1_prev_scape[NUM_BUSH_LEAVES_POINTS][2] = 	
{{0,0},{-40.50f/10.0f, 40.50f/10.0f},{-5.50f/10.0f, 32.50f/10.0f},{5.50f/10.0f, 27.50f/10.0f} };
static float bush_leaves1_coords [NUM_BUSH_LEAVES_POINTS][2] = 	
{{-66.50f/10.0f, 29.50f/10.0f},{ -37.50f/10.0f, 25.50f/10.0f},{ -16.50f/10.0f, 19.50f/10.0f},{11.50f/10.0f, 21.50f/10.0f}};
static float bush_leaves1_aft_scape[NUM_BUSH_LEAVES_POINTS][2] = 	
{{-59.50f/10.0f, 37.50f/10.0f},{-32.50f/10.0f, 51.50f/10.0f},{-5.50f/10.0f, 30.50f/10.0f},{0 ,0} };

static float bush_leaves2_prev_scape [NUM_BUSH_LEAVES_POINTS][2] = 	
{{0, 0},{15.50f/10.0f, -18.50f/10.0f},{51.50f/10.0f, -10.50f/10.0f},{86.50f/10.0f, 1.50f/10.0f}};
static float bush_leaves2_coords[NUM_BUSH_LEAVES_POINTS][2] = 	
{{0.50f/10.0f, -36.50f/10.0f},{30.50f/10.0f, -29.50f/10.0f},{62.50f/10.0f, -24.50f/10.0f},{83.50f/10.0f, -21.50f/10.0f}};
static float bush_leaves2_aft_scape[NUM_BUSH_LEAVES_POINTS][2] = 	
{{5.50f/10.0f, -20.50f/10.0f},{31.50f/10.0f, -11.50f/10.0f},{60.50f/10.0f, -9.50f/10.0f},{0,0}};








Bush::Bush()  
{
   int i =  0 ;

   for( i=0 ; i<NUM_BUSH_POINTS ; i++ )
   {
      _points.addPoint( i, Point2d( bush_coords[i][0], bush_coords[i][1] ) );
      _points.editPointScapes( i, Point2d( bush_prev_scapes[i][0], bush_prev_scapes[i][1] ), 
         Point2d( bush_aft_scapes [i][0], bush_aft_scapes [i][1] ) ) ; 
   }
   for( i=0 ; i<NUM_BUSH_LEAVES_POINTS ; i++ )
   {
      _leaves_1.addPoint( i, Point2d( bush_leaves1_coords[i][0], bush_leaves1_coords[i][1] ) );
      _leaves_1.editPointScapes( i, Point2d( bush_leaves1_prev_scape[i][0], bush_leaves1_prev_scape[i][1] ), 
         Point2d( bush_leaves1_aft_scape [i][0], bush_leaves1_aft_scape [i][1] ) ) ; 

      _leaves_2.addPoint( i, Point2d( bush_leaves2_coords[i][0], bush_leaves2_coords[i][1] ) );
      _leaves_2.editPointScapes( i, Point2d( bush_leaves2_prev_scape[i][0], bush_leaves2_prev_scape[i][1] ), 
         Point2d( bush_leaves2_aft_scape [i][0], bush_leaves2_aft_scape [i][1] ) ) ; 
   }
}

Bush::~Bush()
{
};

const Point2d & Bush::scale( ) const
{
   return _scale ;
} ;

void Bush::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Bush::position( ) const
{
   return _position ;
} ;

void Bush::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Bush::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   int i = 0 ;
   for( i=0 ; i<NUM_BUSH_POINTS ; i++ )
   {
      _points.editPoint      ( i, Point2d( bush_coords     [i][0]*s._x+p._x, bush_coords     [i][1]*s._y+p._y ) );
      _points.editPointScapes( i, Point2d( bush_prev_scapes[i][0]*s._x+p._x, bush_prev_scapes[i][1]*s._y+p._y ), 
         Point2d( bush_aft_scapes [i][0]*s._x+p._x, bush_aft_scapes [i][1]*s._y+p._y ) ) ; 
   }
   for( i=0 ; i<NUM_BUSH_LEAVES_POINTS ; i++ )
   {
      _leaves_1.editPoint( i, Point2d( bush_leaves1_coords[i][0]*s._x+p._x, bush_leaves1_coords[i][1]*s._y+p._y  ) );
      _leaves_1.editPointScapes( i, Point2d( bush_leaves1_prev_scape[i][0]*s._x+p._x, bush_leaves1_prev_scape[i][1]*s._y+p._y  ), 
         Point2d( bush_leaves1_aft_scape [i][0]*s._x+p._x, bush_leaves1_aft_scape [i][1]*s._y+p._y  ) ) ; 

      _leaves_2.editPoint( i, Point2d( bush_leaves2_coords[i][0]*s._x+p._x, bush_leaves2_coords[i][1]*s._y+p._y  ) );
      _leaves_2.editPointScapes( i, Point2d( bush_leaves2_prev_scape[i][0]*s._x+p._x, bush_leaves2_prev_scape[i][1]*s._y+p._y  ), 
         Point2d( bush_leaves2_aft_scape [i][0]*s._x+p._x, bush_leaves2_aft_scape [i][1]*s._y+p._y  ) ) ; 
   }

};

void Bush::draw( const Point2d & s, const Point2d & p )const 
{
   _points.draw( s, p ) ;
   _leaves_1.draw( s, p ) ;
   _leaves_2.draw( s, p) ;
} ;

void Bush::draw( ) const
{
   cdForeground( CD_WHITE );
   _points.draw( Bezier::FILL) ;

   cdForeground( this->color() );
   _points.draw( ) ;
   _leaves_1.draw( ) ;
   _leaves_2.draw( ) ;

} ;
void Bush::drawSelectable() 
{
   _points.draw( Bezier::FILL ) ;
   _points.draw( ) ;
   _leaves_1.draw( ) ;
   _leaves_2.draw( ) ;
}
void Bush::boundingBox( Point2d& min, Point2d& max ) const 
{
   _points.boundingBox( min, max );
   //min._x = min._y = DBL_MAX;
   //max._x = max._y = -DBL_MAX;

   //for( unsigned int i = 0 ; i< _points.numPoints() ; i++ )
   //{
   //   updateBoundingBox( min, max, _points.pointVal(i) );
   //}
};

Object *Bush::copy()
{
   return new Bush( *this ) ;
}
