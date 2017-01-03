#include "palm_tree.h"
#include "float.h"
#include "cd.h"
#include "wd.h"


static unsigned int NUM_SEGMENTS = 16;
static unsigned int NUM_BEZIERS = 6;
static unsigned int NUM_BEZIER_POINTS[6] = {6, 10, 9 ,8, 11,6};

//LINES      
static float palm_tree_lines[16][2][2] =   
{
   // trunk
   {    
      { -26.79275f/10.0f , -224.4132f/10.0f }, 
      { 31.00755f/10.0f , -219.4199f/10.0f }, 
   },     
   {    
      { -21.80995f/10.0f , -134.5338f/10.0f }, 
      { 26.02475f/10.0f , -125.5459f/10.0f }, 
   },     
   {    
      { -18.82035f/10.0f , -62.6303f/10.0f }, 
      { 23.03505f/10.0f , -52.6437f/10.0f }, 
   },     
   {    
      { -17.82375f/10.0f , -3.7094f/10.0f }, 
      { 21.04195f/10.0f , 5.2785f/10.0f }, 
   },     
   {    
      { -14.83405f/10.0f , 52.2155f/10.0f }, 
      { 19.04885f/10.0f , 59.2061f/10.0f }, 
   },     
   {    
      { -13.83755f/10.0f , 94.1592f/10.0f }, 
      { 17.05575f/10.0f , 104.1458f/10.0f }, 
   },


   //folha1     
   {    
      { -69.29705f/10.0f , 61.6726f/10.0f }, 
      { -87.18865f/10.0f , 80.2517f/10.0f }, 
   },     
   {    
      { -52.06815f/10.0f , 100.1579f/10.0f }, 
      { -64.65855f/10.0f , 112.7651f/10.0f }, 
   },     
   {    
      { -46.76695f/10.0f , 151.9139f/10.0f }, 
      { -60.68265f/10.0f , 164.5211f/10.0f }, 
   },   

   //folha2     
   {    
      { -32.85135f/10.0f , 212.9595f/10.0f }, 
      { -40.14045f/10.0f , 226.2303f/10.0f }, 
   },     
   {    
      { -98.12235f/10.0f , 197.3663f/10.0f }, 
      { -101.43565f/10.0f , 208.6465f/10.0f }, 
   },   

   //folha3     
   {    
      { 114.18295f/10.0f , 240.292f/10.0f }, 
      { 99.55415f/10.0f , 253.5985f/10.0f }, 
   },     
   {    
      { 67.63675f/10.0f , 236.3f/10.0f }, 
      { 58.32755f/10.0f , 246.9453f/10.0f }, 
   }, 

   //folha4     
   {    
      { 49.61235f/10.0f , 194.0874f/10.0f }, 
      { 52.60205f/10.0f , 207.0699f/10.0f }, 
   },     
   {    
      { 86.48505f/10.0f , 150.1463f/10.0f }, 
      { 88.47815f/10.0f , 166.1249f/10.0f }, 
   },    

   //folha5     
   {    
      { 24.10075f/10.0f , 158.5608f/10.0f }, 
      { 27.63565f/10.0f , 163.2801f/10.0f }, 
   },     
};    

// BEZIERS
float palmtree_beziers[6][3][11][2] = 
{
   {
      //TRUNK     
      //float left_trunk_prev_coords[3][2]=     
      {
         { -9.85135f/10.0f , 219.9903f/10.0f },  
         { -19.20575f/10.0f , -41.6832f/10.0f },
         { -30.77905f/10.0f , -269.3528f/10.0f }, 
         { 34.99375f/10.0f , -269.3528f/10.0f }, 
         { 29.45495f/10.0f , -205.4909f/10.0f }, 
         { 18.05235f/10.0f , 88.1673f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0} 
      },  

      //float trunk_aft_coords[3][2]=     
      { 
         { -14.83405f/10.0f , 89.1659f/10.0f }, 
         { -26.18195f/10.0f , -204.8048f/10.0f }, 
         { -30.77905f/10.0f , -269.3528f/10.0f }, 
         { 34.99375f/10.0f , -269.3528f/10.0f }, 
         { 22.14615f/10.0f , -42.694f/10.0f }, 
         { 13.06955f/10.0f , 218.9917f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0}  
      },  

      //float trunk_pts_coords[3][2]=     
      {
         { -9.85135f/10.0f , 219.9903f/10.0f },  
         { -24.79965f/10.0f , -172.4829f/10.0f },
         { -30.77905f/10.0f , -269.3528f/10.0f }, 
         { 34.99375f/10.0f , -269.3528f/10.0f }, 
         { 28.01785f/10.0f , -173.4815f/10.0f }, 
         { 13.06955f/10.0f , 218.9917f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0}  
      },    
   },

   {
      //FOLHA1:  
      //float leav1_prev_coords[10][2]=     
      {    
         { -8.85475f/10.0f , 219.9903f/10.0f }, 
         { -45.44165f/10.0f , 203.6699f/10.0f }, 
         { -97.22075f/10.0f , 145.0836f/10.0f }, 
         { -100.44165f/10.0f , 63.6632f/10.0f }, 
         { -72.63445f/10.0f , 56.2102f/10.0f }, 
         { -69.29705f/10.0f , 88.2142f/10.0f }, 
         { -60.68265f/10.0f , 86.8871f/10.0f }, 
         { -53.14885f/10.0f , 89.0361f/10.0f }, 
         { -52.07825f/10.0f , 138.4958f/10.0f }, 
         { -21.47785f/10.0f , 198.6856f/10.0f },{0,0}
      },    
      //float leav1_aft_coords[10][2]=     
      {    
         { -8.85475f/10.0f , 219.9903f/10.0f }, 
         { -81.03245f/10.0f , 166.8253f/10.0f }, 
         { -102.75835f/10.0f , 87.115f/10.0f }, 
         { -89.83925f/10.0f , 22.5238f/10.0f }, 
         { -65.32115f/10.0f , 82.2423f/10.0f }, 
         { -63.33325f/10.0f , 88.8777f/10.0f }, 
         { -52.56745f/10.0f , 82.7265f/10.0f }, 
         { -49.48665f/10.0f , 114.7255f/10.0f }, 
         { -37.46525f/10.0f , 181.4053f/10.0f }, 
         { -9.85135f/10.0f , 217.993f/10.0f },{0,0}
      },    
      //float leav1_pts_coords[10][2]=     
      {    
         { -8.85475f/10.0f , 219.9903f/10.0f }, 
         { -62.00795f/10.0f , 187.0815f/10.0f }, 
         { -103.75495f/10.0f , 118.0734f/10.0f }, 
         { -100.53805f/10.0f , 24.253f/10.0f }, 
         { -60.67575f/10.0f , 75.1847f/10.0f }, 
         { -73.93565f/10.0f , 96.1766f/10.0f }, 
         { -55.69295f/10.0f , 83.174f/10.0f }, 
         { -52.70325f/10.0f , 92.1619f/10.0f }, 
         { -44.73085f/10.0f , 160.0707f/10.0f }, 
         { -9.85135f/10.0f , 217.993f/10.0f },{0,0}
      },
   },
   {
      //FOLHA2     
      //float leav2_prev_coords[9][2]=     
      {    
         { -7.67055f/10.0f , 219.5949f/10.0f }, 
         { -26.22475f/10.0f , 248.127f/10.0f }, 
         { -103.16815f/10.0f , 237.3775f/10.0f }, 
         { -152.79105f/10.0f , 161.867f/10.0f }, 
         { -139.53805f/10.0f , 171.8201f/10.0f }, 
         { -81.88745f/10.0f , 197.6981f/10.0f }, 
         { -67.97175f/10.0f , 216.9407f/10.0f }, 
         { -60.68265f/10.0f , 216.2772f/10.0f }, 
         { -27.55015f/10.0f , 216.2772f/10.0f },{0,0},{0,0}
      },    
      //float leav2_aft_coords[9][2]=     
      {    
         { -7.67055f/10.0f , 219.5949f/10.0f }, 
         { -76.98275f/10.0f , 248.127f/10.0f }, 
         { -142.92465f/10.0f , 194.5054f/10.0f }, 
         { -150.14045f/10.0f , 147.2691f/10.0f }, 
         { -105.10095f/10.0f , 200.3627f/10.0f }, 
         { -65.32115f/10.0f , 210.3053f/10.0f }, 
         { -63.99585f/10.0f , 220.922f/10.0f }, 
         { -39.47785f/10.0f , 207.6512f/10.0f }, 
         { -8.33325f/10.0f , 218.9313f/10.0f },{0,0},{0,0}
      },    
      //float leav2_pts_coords[9][2]=     
      {    
         { -7.67055f/10.0f , 219.5949f/10.0f }, 
         { -52.73085f/10.0f , 248.127f/10.0f }, 
         { -119.65855f/10.0f , 219.5949f/10.0f }, 
         { -164.71875f/10.0f , 128.0265f/10.0f }, 
         { -120.98385f/10.0f , 188.4085f/10.0f }, 
         { -63.33325f/10.0f , 203.6699f/10.0f }, 
         { -69.95975f/10.0f , 226.2303f/10.0f }, 
         { -56.70675f/10.0f , 207.6512f/10.0f }, 
         { -8.33325f/10.0f , 218.9313f/10.0f },{0,0},{0,0}
      },
   },
   {
      //FOLHA3  
      //float leav3_prev_coords[8][2]=     
      {    
         { -8.16705f/10.0f , 220.3322f/10.0f }, 
         { 16.48045f/10.0f , 237.018f/10.0f }, 
         { 50.59765f/10.0f , 262.4407f/10.0f }, 
         { 96.37505f/10.0f , 268.3441f/10.0f }, 
         { 147.43025f/10.0f , 254.9292f/10.0f }, 
         { 162.05905f/10.0f , 250.2719f/10.0f }, 
         { 54.33785f/10.0f , 236.3f/10.0f }, 
         { -0.40935f/10.0f , 222.9935f/10.0f },{0,0},{0,0},{0,0} 
      },    
      //float leav3_aft_coords[8][2]=     
      {    
         { -8.16705f/10.0f , 220.3322f/10.0f }, 
         { 40.42485f/10.0f , 252.1028f/10.0f }, 
         { 79.38165f/10.0f , 269.3528f/10.0f }, 
         { 137.45605f/10.0f , 257.5905f/10.0f }, 
         { 155.40955f/10.0f , 242.288f/10.0f }, 
         { 74.28615f/10.0f , 238.9613f/10.0f }, 
         { 6.63555f/10.0f , 224.6112f/10.0f }, 
         { -7.50205f/10.0f , 221.6629f/10.0f },{0,0},{0,0},{0,0} 
      },    
      //float leav3_pts_coords[8][2]=     
      {    
         { -8.16705f/10.0f , 220.3322f/10.0f }, 
         { 29.06995f/10.0f , 244.9493f/10.0f }, 
         { 63.64705f/10.0f , 265.5744f/10.0f }, 
         { 112.18805f/10.0f , 264.9091f/10.0f }, 
         { 164.71875f/10.0f , 243.6186f/10.0f }, 
         { 110.85825f/10.0f , 238.9613f/10.0f }, 
         { 13.77615f/10.0f , 225.6548f/10.0f }, 
         { -7.50205f/10.0f , 221.6629f/10.0f },{0,0},{0,0},{0,0} 
      },    
   },
   {
      //FOLHA4     
      //float leav4_prev_coords[11][2]=     
      {    
         { 3.80195f/10.0f , 222.9935f/10.0f }, 
         { 60.78945f/10.0f , 227.3315f/10.0f }, 
         { 113.99965f/10.0f , 188.3474f/10.0f }, 
         { 130.14165f/10.0f , 105.2308f/10.0f }, 
         { 122.16225f/10.0f , 103.2348f/10.0f }, 
         { 109.93165f/10.0f , 122.9752f/10.0f }, 
         { 103.26035f/10.0f , 123.2509f/10.0f }, 
         { 82.26555f/10.0f , 156.4609f/10.0f }, 
         { 70.62225f/10.0f , 188.6463f/10.0f }, 
         { 65.31995f/10.0f , 187.1715f/10.0f }, 
         { 29.73485f/10.0f , 208.3563f/10.0f }, 
      },    
      //float leav4_aft_coords[11][2]=     
      {    
         { 3.80195f/10.0f , 222.9935f/10.0f }, 
         { 104.89945f/10.0f , 195.0979f/10.0f }, 
         { 125.73175f/10.0f , 121.67f/10.0f }, 
         { 124.82205f/10.0f , 95.9162f/10.0f }, 
         { 108.55815f/10.0f , 117.6731f/10.0f }, 
         { 106.10545f/10.0f , 125.9109f/10.0f }, 
         { 91.57475f/10.0f , 142.489f/10.0f }, 
         { 67.67655f/10.0f , 187.1715f/10.0f }, 
         { 67.08735f/10.0f , 191.8908f/10.0f }, 
         { 38.66355f/10.0f , 202.9952f/10.0f }, 
         { 3.13705f/10.0f , 222.3282f/10.0f }, 
      },    
      //float leav4_pts_coords[11][2]=     
      {    
         { 3.80195f/10.0f , 222.9935f/10.0f }, 
         { 82.15115f/10.0f , 211.7214f/10.0f }, 
         { 121.07715f/10.0f , 136.3072f/10.0f }, 
         { 136.12615f/10.0f , 89.9283f/10.0f }, 
         { 107.53345f/10.0f , 111.884f/10.0f }, 
         { 111.20705f/10.0f , 128.8286f/10.0f }, 
         { 98.88915f/10.0f , 119.868f/10.0f }, 
         { 66.97175f/10.0f , 178.4167f/10.0f }, 
         { 70.96145f/10.0f , 195.0498f/10.0f }, 
         { 60.60675f/10.0f , 185.6967f/10.0f }, 
         { 3.13705f/10.0f , 222.3282f/10.0f }, 
      },    
   },
   {
      //FOLHA5     
      //float leav5_prev_coords[6][2]=     
      {    
         { 0.39095f/10.0f , 218.4368f/10.0f }, 
         { 24.64685f/10.0f , 193.6396f/10.0f }, 
         { 43.22515f/10.0f , 103.6718f/10.0f }, 
         { 34.82065f/10.0f , 95.7335f/10.0f }, 
         { 29.38935f/10.0f , 139.3238f/10.0f }, 
         { 8.79605f/10.0f , 196.237f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0} 
      },    
      //float leav5_aft_coords[6][2]=     
      {    
         { 8.93365f/10.0f , 210.1781f/10.0f }, 
         { 40.12875f/10.0f , 137.1892f/10.0f }, 
         { 40.57105f/10.0f , 77.6517f/10.0f }, 
         { 26.56365f/10.0f , 122.9364f/10.0f }, 
         { 18.01175f/10.0f , 176.4399f/10.0f }, 
         { -0.19815f/10.0f , 217.8469f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0} 
      },    
      //float leav5_pts_coords[6][2]=     
      {    
         { 0.39095f/10.0f , 218.4368f/10.0f }, 
         { 33.05125f/10.0f , 168.5016f/10.0f }, 
         { 43.66745f/10.0f , 70.5954f/10.0f }, 
         { 29.95495f/10.0f , 107.641f/10.0f }, 
         { 25.08915f/10.0f , 154.389f/10.0f }, 
         { -0.19815f/10.0f , 217.8469f/10.0f },{0,0},{0,0},{0,0},{0,0},{0,0} 
      },    
   },                 
};
//------------------------------------------------------------------------------------------


PalmTree::PalmTree()  
{
   unsigned int i = 0 ;
   unsigned int j = 0 ;

   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      unsigned int n = NUM_BEZIER_POINTS[i] ;

      for( j=0 ; j< n ; j++ )
      {
         Point2d prv( palmtree_beziers[i][0][j][0], palmtree_beziers[i][0][j][1] );
         Point2d aft( palmtree_beziers[i][1][j][0], palmtree_beziers[i][1][j][1] );
         Point2d pnt( palmtree_beziers[i][2][j][0], palmtree_beziers[i][2][j][1] );

         _beziers[i].addPoint( j, pnt);
         _beziers[i].editPointScapes( j, prv, aft );        
      }
   }   

   for( i=0 ; i<NUM_SEGMENTS ; i++ )
   {
      Point2d p0( palm_tree_lines[i][0][0], palm_tree_lines[i][0][1] );
      Point2d p1( palm_tree_lines[i][1][0], palm_tree_lines[i][1][1] );

      _segments[i].addPoint( 0, p0 );
      _segments[i].addPoint( 1, p1 );
   } 
}


PalmTree::~PalmTree()
{
}


const Point2d & PalmTree::scale( ) const
{
   return _scale ;
}


void PalmTree::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
}


const Point2d & PalmTree::position( ) const
{
   return _position ;
}


void PalmTree::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
}


void PalmTree::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   unsigned int i = 0 ;
   unsigned int j = 0 ;

   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      unsigned int n = NUM_BEZIER_POINTS[i] ;

      for( j=0 ; j< n ; j++ )
      {
         Point2d prv( palmtree_beziers[i][0][j][0]*s._x+p._x, palmtree_beziers[i][0][j][1]*s._y+p._y );
         Point2d aft( palmtree_beziers[i][1][j][0]*s._x+p._x, palmtree_beziers[i][1][j][1]*s._y+p._y );
         Point2d pnt( palmtree_beziers[i][2][j][0]*s._x+p._x, palmtree_beziers[i][2][j][1]*s._y+p._y );

         _beziers[i].editPoint( j, pnt);
         _beziers[i].editPointScapes( j, prv, aft );        
      }
   }
   for( i=0 ; i<NUM_SEGMENTS ; i++ )
   {
      Point2d p0( palm_tree_lines[i][0][0]*s._x+p._x, palm_tree_lines[i][0][1]*s._y+p._y );
      Point2d p1( palm_tree_lines[i][1][0]*s._x+p._x, palm_tree_lines[i][1][1]*s._y+p._y );

      _segments[i].editPoint( 0, p0 );
      _segments[i].editPoint( 1, p1 );
   } 

}


void PalmTree::draw( const Point2d & s, const Point2d & p )const 
{
   unsigned int i = 0 ;

   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      _beziers[i].draw( Bezier::FILL ) ;
   }
   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      _beziers[i].draw() ;
   }
   for( i=0 ; i<NUM_SEGMENTS ; i++ )
   {
      _segments[i].draw() ;
   }
} 


void PalmTree::draw( ) const
{
   unsigned int i = 0 ;
   
   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      cdForeground( CD_WHITE );
      _beziers[i].draw( Bezier::FILL ) ;
      cdForeground( color() );
      _beziers[i].draw();
   }
   for( i=0 ; i<NUM_SEGMENTS ; i++ )
   {
      _segments[i].draw() ;
   }

} 


void PalmTree::drawSelectable( )
{
   unsigned int i = 0 ;

   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      _beziers[i].draw();
   }
   for( i=0 ; i<NUM_SEGMENTS ; i++ )
   {
      _segments[i].draw() ;
   }

}


void PalmTree::boundingBox( Point2d& min, Point2d& max ) const 
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   unsigned int i = 0 ;
   unsigned int j = 0 ;

   for( i=0 ; i<NUM_BEZIERS ; i++ )
   {
      unsigned int n = NUM_BEZIER_POINTS[i] ;

      for( j=0 ; j< n ; j++ )
      {
         updateBoundingBox( min, max, (_beziers[i]).pointVal(j) );
      }
   }
}


Object *PalmTree::copy()
{
   return new PalmTree( *this ) ;
}