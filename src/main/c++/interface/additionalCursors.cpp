#include "iup.h"

static unsigned char cursor_move_point_pix2[]=
{ 
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,
   0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,
   0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,
   0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,
   0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,
   0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,
   0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,
   0,0,0,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,
   0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,    
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
} ;

static unsigned char cursor_move_point_pix[]=
{ 
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   ,0,0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0
   ,0,0,0,2,1,1,1,1,2,0,2,1,1,1,1,2,0,0,0
   ,0,0,0,2,1,1,1,2,0,0,0,2,1,1,1,2,0,0,0
   ,0,0,0,2,1,1,1,3,4,0,4,3,1,1,1,2,0,0,0
   ,0,0,0,2,1,2,3,1,3,4,3,1,3,2,1,2,0,0,0
   ,0,0,0,2,2,0,4,3,1,3,1,3,4,0,2,2,0,0,0
   ,0,0,0,0,0,0,0,4,3,1,3,4,0,0,0,0,0,0,0
   ,0,0,0,2,2,0,4,3,1,3,1,3,4,0,2,2,0,0,0
   ,0,0,0,2,1,2,3,1,3,4,3,1,3,2,1,2,0,0,0
   ,0,0,0,2,1,1,1,3,4,0,4,3,1,1,1,2,0,0,0
   ,0,0,0,2,1,1,1,2,0,0,0,2,1,1,1,2,0,0,0
   ,0,0,0,2,1,1,1,1,2,0,2,1,1,1,1,2,0,0,0
   ,0,0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
} ;

void LoadAdditionalCursors()
{
   Ihandle* img = IupImage( 19, 19, cursor_move_point_pix ) ;
   IupSetAttribute( img, "HOTSPOT", "9:9" ) ; 
   IupSetAttribute( img, "4", "128 128 128"  ) ;
   IupSetAttribute( img, "3", "0 0 0"  ) ;
   IupSetAttribute( img, "2", "0 0 0"  ) ;
   IupSetAttribute( img, "1", "255 255 255" ) ;
   IupSetHandle( "MOVE_POINT_CRS", img ) ;
}