#include "pine_tree.h"
#include "float.h"
#include "cd.h"
#include "wd.h"

enum
{
    NUM_PINE_TOP_CROWN_POINTS = 27,
    NUM_PINE_MID_TOP_CROWN_POINTS = 48,
    NUM_PINE_MID_BOTTOM_CROWN_POINTS = 66,
    NUM_PINE_BOTTOM_CROWN_POINTS = 66,
    NUM_PINE_TRUNK_POINTS = 33,
};

static double pine_tree_x_min = -11.840 ;
static double pine_tree_y_min = -26.275 ;
static double pine_tree_x_max =  11.840 ;
static double pine_tree_y_max =  26.275 ;


static double pine_top_crown_coords[NUM_PINE_TOP_CROWN_POINTS][2] = 
{
{   -2.2800,  25.9050   },
{   -2.2800,  25.9050   },
{   -2.2800,  24.4050   },
{   -3.7100,  20.2650   },
{   -4.8800,  17.4050   },
{   -4.1600,  17.8450   },
{   -4.2000,  18.0950   },
{   -3.4400,  18.1950   },
{   -3.3000,  16.5950   },
{   -3.9000,  15.8650   },
{   -4.4900,  14.9250   },
{   -3.3300,  15.2050   },
{   -3.0300,  15.4250   },
{   -2.5300,  16.8850   },
{   -2.0200,  15.2750   },
{   -1.7200,  14.5450   },
{   -0.8200,  13.4850   },
{   -0.2900,  14.2850   },
{   -0.7000,  15.2450   },
{   -1.0900,  16.7550   },
{    0.2700,  15.8950   },
{    0.0500,  15.9750   },
{    1.5400,  15.9750   },
{   -0.7400,  19.5250   },
{   -1.1200,  22.9050   },
{   -2.3200,  26.2750   },
{   -2.3200,  26.2750   }
};

static double pine_mid_top_crown_coords[NUM_PINE_MID_TOP_CROWN_POINTS][2] = 
{
{   -3.7600,  16.5650   },
{   -3.7600,  16.5650   },
{   -3.7600,  16.5650   },
{   -5.4600,  12.7950   },
{   -7.7900,  10.8450   },
{   -6.3300,   9.5750   },
{   -5.8100,  10.2150   },
{   -4.3200,  10.3550   },
{   -5.1700,   9.3450   },
{   -4.8200,   8.0250   },
{   -5.6300,   7.1350   },
{   -3.4900,   7.3350   },
{   -4.0100,   8.7150   },
{   -3.1300,   9.1850   },
{   -2.6200,   8.3150   },
{   -2.8800,   6.7550   },
{   -1.9400,   6.3550   },
{   -1.7600,   7.3950   },
{   -1.7600,   8.3150   },
{   -1.4300,   8.4650   },
{   -0.5400,   7.6250   },
{   -0.2000,   6.4750   },
{    0.3300,   5.7450   },
{    0.2700,   6.8750   },
{    0.2700,   7.4550   },
{    0.2100,   8.7950   },
{    1.3100,   8.3750   },
{    3.0400,   7.5050   },
{    4.5800,   7.3550   },
{    3.1000,   8.4250   },
{    2.4600,   9.2650   },
{    2.2600,  10.5750   },
{    2.9300,  10.7850   },
{    3.3900,  10.4450   },
{    4.0700,  10.5750   },
{    2.2900,  12.5650   },
{    2.3600,  14.3150   },
{    1.2900,  16.0650   },
{    0.8600,  16.7750   },
{    0.3400,  17.5250   },
{   -0.4100,  17.8950   },
{   -1.0000,  18.1950   },
{   -1.7900,  18.1650   },
{   -2.4000,  17.8950   },
{   -2.8400,  17.7050   },
{   -2.9300,  17.0850   },
{   -3.1900,  16.6750   },
{   -3.1900,  16.6750   }
};

static double pine_mid_bottom_crown_coords[NUM_PINE_MID_BOTTOM_CROWN_POINTS][2] = 
{
{	-4.6100 ,	10.0150	},
{	-4.6100 ,	10.0150	},
{	-4.6100 ,	10.0150	},
{	-7.3700 ,	7.3950	},
{	-8.9200 ,	7.3550	},
{	-9.2800 ,	6.9050	},
{	-7.4300 ,	6.7850	},
{	-7.6200 ,	6.2450	},
{	-7.9100 ,	5.4050	},
{	-8.7600 ,	4.8050	},
{	-9.8300 ,	4.7450	},
{	-9.7600 ,	3.9150	},
{	-8.2400 ,	3.9450	},
{	-7.4400 ,	4.0250	},
{	-7.2700 ,	2.5850	},
{	-8.5800 ,	1.0150	},
{	-9.2600 ,	0.0850	},
{	-8.5100 ,	-0.9950	},
{	-6.6700 ,	0.8950	},
{	-5.5200 ,	1.2450	},
{	-6.0400 ,	-0.0250	},
{	-6.0400 ,	-0.9950	},
{	-6.5400 ,	-1.6950	},
{	-3.6700 ,	-2.5550	},
{	-3.2600 ,	-0.0250	},
{	-2.3400 ,	1.3050	},
{	-1.6400 ,	-0.0750	},
{	-1.9300 ,	-2.6050	},
{	-1.8300 ,	-2.9650	},
{	0.1500 ,	-1.2250	},
{	-0.7200 ,	0.0350	},
{	0.1000 ,	1.2450	},
{	0.7300 ,	1.1250	},
{	1.1300 ,	-1.4550	},
{	1.1800 ,	-1.9750	},
{	2.2300 ,	-1.2250	},
{	1.6600 ,	0.4350	},
{	1.7500 ,	1.5250	},
{	2.7000 ,	1.0750	},
{	3.6200 ,	0.3850	},
{	4.2400 ,	-1.0250	},
{	4.5500 ,	-0.0750	},
{	3.2200 ,	1.7650	},
{	3.5000 ,	2.9150	},
{	4.1400 ,	2.6850	},
{	5.5900 ,	2.1650	},
{	5.8300 ,	1.7450	},
{	6.2800 ,	2.2750	},
{	5.1700 ,	3.2650	},
{	5.6000 ,	3.8050	},
{	6.3400 ,	3.4850	},
{	7.3800 ,	3.6050	},
{	7.7000 ,	4.0250	},
{	6.2300 ,	4.5250	},
{	5.4200 ,	5.7250	},
{	4.7000 ,	6.6350	},
{	3.5300 ,	7.6550	},
{	2.5900 ,	8.9850	},
{	1.2400 ,	9.7350	},
{	0.4000 ,	10.2050	},
{	-0.6500 ,	10.0550	},
{	-1.6000 ,	10.1250	},
{	-2.3900 ,	10.1850	},
{	-3.1900 ,	10.1250	},
{	-3.9800 ,	10.1250	},
{	-3.9800 ,	10.1250	}

};

static double pine_bottom_crown_coords[NUM_PINE_BOTTOM_CROWN_POINTS][2] = 
{
{   -6.8200,   1.3350   },
{   -6.8200,   1.3350   },
{   -7.2200,  -0.4350   },
{  -10.0000,  -3.7150   },
{  -11.7000,  -3.8550   },
{  -11.8400,  -5.0350   },
{   -8.8600,  -4.7650   },
{   -8.3500,  -5.0250   },
{   -8.8100,  -6.9350   },
{  -10.3900,  -8.5450   },
{  -11.8100,  -9.2450   },
{  -10.6200, -10.9850   },
{   -8.2400,  -9.5950   },
{   -6.7100,  -8.4050   },
{   -6.2000,  -9.8750   },
{   -7.3900, -11.5950   },
{   -7.7300, -12.4050   },
{   -5.8400, -12.6150   },
{   -4.6600, -10.8750   },
{   -3.3000,  -8.7950   },
{   -3.2500,  -9.5950   },
{   -3.7600, -11.6450   },
{   -3.8700, -12.4550   },
{   -2.5700, -11.5350   },
{   -2.1700,  -9.9250   },
{   -1.6000,  -9.0150   },
{   -1.0300, -10.1450   },
{   -1.0900, -12.4250   },
{   -1.3700, -12.7950   },
{    0.2700, -11.5950   },
{   -0.1800, -10.3750   },
{    0.5500,  -8.1850   },
{    1.7400,  -7.7850   },
{    1.6300, -10.2050   },
{    2.2000, -11.5750   },
{    2.9400, -10.1450   },
{    2.6000,  -8.4250   },
{    2.4800,  -6.8550   },
{    3.2800,  -7.5450   },
{    4.3600,  -8.3150   },
{    4.8700,  -9.3550   },
{    5.0900,  -7.9850   },
{    4.3600,  -7.0950   },
{    3.9000,  -5.5250   },
{    5.4900,  -6.0950   },
{    6.3400,  -6.9350   },
{    6.5100,  -7.4650   },
{    7.1400,  -6.7050   },
{    6.5100,  -5.8250   },
{    6.5100,  -5.1850   },
{    8.2100,  -5.5450   },
{    9.8000,  -5.4850   },
{   11.8400,  -4.6350   },
{    8.1000,  -2.7650   },
{    7.3600,  -0.7750   },
{    5.8300,   1.5850   },
{    4.7900,   2.6150   },
{    4.0500,   4.3650   },
{    2.6000,   4.5750   },
{    0.3900,   4.9050   },
{   -1.7800,   3.6550   },
{   -3.9300,   3.0250   },
{   -4.8900,   2.7450   },
{   -5.7800,   2.2450   },
{   -6.7100,   1.8550   },
{   -6.7100,   1.8550   }
};

static double pine_trunk_coords[NUM_PINE_TRUNK_POINTS][2] = 
{
{   -2.5700,   -9.9650   },
{   -2.5700,   -9.9650   },
{   -2.5700,   -9.9650   },
{   -2.4200,  -14.8750   },
{   -2.4500,  -17.3250   },
{   -2.4800,  -20.0350   },
{   -3.5300,  -22.8450   },
{   -2.7400,  -25.4350   },
{   -2.4800,  -26.2750   },
{   -1.0100,  -25.0550   },
{   -0.1400,  -24.9150   },
{    0.7300,  -24.7850   },
{    2.3300,  -25.4950   },
{    2.4700,  -24.6250   },
{    2.9300,  -21.6150   },
{    1.5500,  -18.5850   },
{    1.3100,  -15.5450   },
{    1.1200,  -13.2150   },
{    1.1600,  -10.8750   },
{    1.1900,   -8.5350   },
{    1.2000,   -7.8750   },
{    1.9500,   -6.9650   },
{    1.4200,   -6.5750   },
{    0.5200,   -5.9150   },
{   -0.8300,   -6.0050   },
{   -1.9300,   -6.2350   },
{   -2.7000,   -6.3950   },
{   -3.6100,   -6.9050   },
{   -3.7800,   -7.6750   },
{   -3.9100,   -8.2450   },
{   -2.9300,   -8.4750   },
{   -2.5100,   -8.8750   },
{   -2.5100,   -8.8750   }
};


PineTree::PineTree()  : _min( pine_tree_x_min, pine_tree_y_min ), _max( pine_tree_x_max, pine_tree_y_max ) 
{
   int i =  0 ;


   for( i=0 ; i<NUM_PINE_TRUNK_POINTS ; i+=3 )
   {
      _trunk.addPoint       ( i/3, Point2d( pine_trunk_coords[i+1][0], pine_trunk_coords[i+1][1] ) );
      _trunk.editPointScapes( i/3, Point2d( pine_trunk_coords[i  ][0], pine_trunk_coords[i  ][1] ) ,
                                   Point2d( pine_trunk_coords[i+2][0], pine_trunk_coords[i+2][1] ) );
   }
   for( i=0 ; i<NUM_PINE_TOP_CROWN_POINTS ; i+=3 )
   {
      _top_crown.addPoint       ( i/3, Point2d( pine_top_crown_coords[i+1][0], pine_top_crown_coords[i+1][1] ) );
      _top_crown.editPointScapes( i/3, Point2d( pine_top_crown_coords[i  ][0], pine_top_crown_coords[i  ][1] ) ,
                                       Point2d( pine_top_crown_coords[i+2][0], pine_top_crown_coords[i+2][1] ) );
   }
   for( i=0 ; i<NUM_PINE_MID_TOP_CROWN_POINTS ; i+=3 )
   {
      _mid_top_crown.addPoint       ( i/3, Point2d( pine_mid_top_crown_coords[i+1][0], pine_mid_top_crown_coords[i+1][1] ) );
      _mid_top_crown.editPointScapes( i/3, Point2d( pine_mid_top_crown_coords[i  ][0], pine_mid_top_crown_coords[i  ][1] ),
                                           Point2d( pine_mid_top_crown_coords[i+2][0], pine_mid_top_crown_coords[i+2][1] ) );
   }
   for( i=0 ; i<NUM_PINE_MID_BOTTOM_CROWN_POINTS ; i+=3 )
   {
      _mid_bottom_crown.addPoint       ( i/3, Point2d( pine_mid_bottom_crown_coords[i+1][0], pine_mid_bottom_crown_coords[i+1][1] ) );
      _mid_bottom_crown.editPointScapes( i/3, Point2d( pine_mid_bottom_crown_coords[i  ][0], pine_mid_bottom_crown_coords[i  ][1] ) ,
                                              Point2d( pine_mid_bottom_crown_coords[i+2][0], pine_mid_bottom_crown_coords[i+2][1] ) );
   }
   for( i=0 ; i<NUM_PINE_BOTTOM_CROWN_POINTS ; i+=3 )
   {
      _bottom_crown.addPoint       ( i/3, Point2d( pine_bottom_crown_coords[i+1][0], pine_bottom_crown_coords[i+1][1] ) );
      _bottom_crown.editPointScapes( i/3, Point2d( pine_bottom_crown_coords[i  ][0], pine_bottom_crown_coords[i  ][1] ),
                                          Point2d( pine_bottom_crown_coords[i+2][0], pine_bottom_crown_coords[i+2][1] ) );
   }
}


PineTree::~PineTree()
{
}


const Point2d & PineTree::scale( ) const
{
   return _scale ;
}


void PineTree::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
}


const Point2d & PineTree::position( ) const
{
   return _position ;
}


void PineTree::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
}


void PineTree::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   _min._x = pine_tree_x_min * s._x + p._x ;
   _min._y = pine_tree_y_min * s._y + p._y ;
   _max._x = pine_tree_x_max * s._x + p._x ;
   _max._y = pine_tree_y_max * s._y + p._y ;

   int i = 0 ;

   for( i=0 ; i<NUM_PINE_TRUNK_POINTS ; i+=3 )
   {
      _trunk.editPoint      ( i/3, Point2d( pine_trunk_coords[i+1][0] * s._x+p._x, pine_trunk_coords[i+1][1] * s._y+p._y ) );
      _trunk.editPointScapes( i/3, Point2d( pine_trunk_coords[i  ][0] * s._x+p._x, pine_trunk_coords[i  ][1] * s._y+p._y ) ,
                                   Point2d( pine_trunk_coords[i+2][0] * s._x+p._x, pine_trunk_coords[i+2][1] * s._y+p._y ) );
   }
   for( i=0 ; i<NUM_PINE_TOP_CROWN_POINTS ; i+=3 )
   {
      _top_crown.editPoint      ( i/3, Point2d( pine_top_crown_coords[i+1][0] * s._x+p._x, pine_top_crown_coords[i+1][1] * s._y+p._y ) );
      _top_crown.editPointScapes( i/3, Point2d( pine_top_crown_coords[i  ][0] * s._x+p._x, pine_top_crown_coords[i  ][1] * s._y+p._y ),
                                       Point2d( pine_top_crown_coords[i+2][0] * s._x+p._x, pine_top_crown_coords[i+2][1] * s._y+p._y ) );
   }
   for( i=0 ; i<NUM_PINE_MID_TOP_CROWN_POINTS ; i+=3 )
   {
      _mid_top_crown.editPoint      ( i/3, Point2d( pine_mid_top_crown_coords[i+1][0] * s._x+p._x, pine_mid_top_crown_coords[i+1][1] * s._y+p._y ) );
      _mid_top_crown.editPointScapes( i/3, Point2d( pine_mid_top_crown_coords[i  ][0] * s._x+p._x, pine_mid_top_crown_coords[i  ][1] * s._y+p._y ), 
                                           Point2d( pine_mid_top_crown_coords[i+2][0] * s._x+p._x, pine_mid_top_crown_coords[i+2][1] * s._y+p._y ) );
   }
   for( i=0 ; i<NUM_PINE_MID_BOTTOM_CROWN_POINTS ; i+=3 )
   {
      _mid_bottom_crown.editPoint      ( i/3, Point2d( pine_mid_bottom_crown_coords[i+1][0] * s._x+p._x, pine_mid_bottom_crown_coords[i+1][1] * s._y+p._y ) );
      _mid_bottom_crown.editPointScapes( i/3, Point2d( pine_mid_bottom_crown_coords[i  ][0] * s._x+p._x, pine_mid_bottom_crown_coords[i  ][1] * s._y+p._y ), 
                                              Point2d( pine_mid_bottom_crown_coords[i+2][0] * s._x+p._x, pine_mid_bottom_crown_coords[i+2][1] * s._y+p._y ) );
   }
   for( i=0 ; i<NUM_PINE_BOTTOM_CROWN_POINTS ; i+=3 )
   {
      _bottom_crown.editPoint      ( i/3, Point2d( pine_bottom_crown_coords[i+1][0] * s._x+p._x, pine_bottom_crown_coords[i+1][1] * s._y+p._y ) );
      _bottom_crown.editPointScapes( i/3, Point2d( pine_bottom_crown_coords[i  ][0] * s._x+p._x, pine_bottom_crown_coords[i  ][1] * s._y+p._y ),
                                          Point2d( pine_bottom_crown_coords[i+2][0] * s._x+p._x, pine_bottom_crown_coords[i+2][1] * s._y+p._y ) );
   }
}


void PineTree::draw( const Point2d & s, const Point2d & p )const 
{
}


void PineTree::draw() const
{
   cdForeground( CD_WHITE ) ;
   _trunk.draw( Bezier::FILL ) ;
   cdForeground( color() ) ;
   _trunk.draw( ) ;

   cdForeground( CD_WHITE ) ;
   _bottom_crown.draw( Bezier::FILL ) ;  
   cdForeground( color() ) ;
   _bottom_crown.draw(  ) ; 

   cdForeground( CD_WHITE ) ;
   _mid_bottom_crown.draw( Bezier::FILL ) ;
   cdForeground( color() ) ;
   _mid_bottom_crown.draw(  ) ;

   cdForeground( CD_WHITE ) ;
   _mid_top_crown.draw( Bezier::FILL ) ;
   cdForeground( color() ) ;
   _mid_top_crown.draw( ) ;

   cdForeground( CD_WHITE ) ;
   _top_crown.draw( Bezier::FILL ) ;
   cdForeground( color() ) ;
   _top_crown.draw() ;
}


void PineTree::drawSelectable( ) 
{
  _trunk.draw( Bezier::FILL ) ;
  _bottom_crown.draw( Bezier::FILL ) ;  
  _mid_bottom_crown.draw( Bezier::FILL ) ;
  _mid_top_crown.draw( Bezier::FILL ) ;
  _top_crown.draw( Bezier::FILL ) ;
}


void PineTree::boundingBox( Point2d& min, Point2d& max ) const 
{
   min = _min ;
   max = _max ;
}


Object *PineTree::copy()
{
   return new PineTree( *this ) ;
}

