/*Advanced IupCanvas Example in C 
This example shows how several canvas callbacks are used and how the scrollbar works. */

#include <stdio.h>
#include "iup.h"
#include "cd.h"
#include "cdiup.h"
#include "wd.h"
#include "math.h"
#include "button_images.h"
#include "line_styles_bt.h"
#include "iupcontrols.h"

unsigned char image[640][400];
double max_mundo_x = 2048 ;
double max_mundo_y = 1280 ;
double mundo_x = 2048 ;
double mundo_y = 1280 ;
/*
grampo 15
parada 25
pendulo 15x4
oposicao 10
buraco 20
cristal 15
bloco 25
aresta 10
meio corpo 8
diedro 20
cabo 20
rampa 10
*/
Ihandle* line_menu ;
   cdCanvas *cdcanvas;

void grampoP( int tx, int ty, int s )
{
   wdBegin( CD_OPEN_LINES ) ;
   wdVertex( 16*s+tx, 6*s+ty+.5 ) ;
   wdVertex( 16*s+tx, 4*s+ty ) ;
   wdVertex(  0*s+tx, 4*s+ty ) ;
   wdVertex(  0*s+tx, 0*s+ty ) ;
   wdVertex( 30*s+tx, 0*s+ty ) ;
   wdVertex( 30*s+tx, 4*s+ty ) ;
   wdVertex( 28*s+tx, 4*s+ty ) ;
   wdVertex( 28*s+tx, 6*s+ty+.5 ) ;
   wdEnd() ;

   wdBegin( CD_OPEN_LINES ) ;
   wdVertex( 20*s+tx, 6*s+ty+.5 ) ;
   wdVertex( 20*s+tx, 4*s+ty ) ;
   wdVertex( 24*s+tx, 4*s+ty ) ;
   wdVertex( 24*s+tx, 6*s+ty+.5 ) ;
   wdEnd() ;

   wdArc( 22*s+tx, 6*s+ty, 12*s, 12*s, 0, 180 ) ;
   wdArc( 22*s+tx, 6*s+ty, 4*s, 4*s, 0, 180 ) ;
}


int escapes_pre[256][2] ;
int via[256][2] ;
int escapes_pos[256][2] ;
int n=0 ;


int repaint_cb(Ihandle* self, float sx, float sy)
{
cdActivate( cdcanvas ) ;
   int x, y;
   sx = IupGetFloat(self, IUP_POSX);
   sy = -IupGetFloat(self, IUP_POSY);

   if(cdActiveCanvas())
   {wdWindow(0, mundo_x, 0, mundo_y ); 
   wdViewport( 0, 320, 0, 200); 

   cdClear();
   grampoP(100, 100, 1 ) ;
   }

   for(x=0;x<320;x++)
      for(y=0;y<200;y++)
      {
         if(image[(int)(640.0*sx)+x][(int)(400.0*sy)+y])
         {
            cdMark(x,y);
            printf("---%d %d   %f %f   %d %d\n", (int)(320.0*sx)+x, (int)(200.0*sy)+y, sx, sy, x, y ) ;
         }
      }
      return IUP_DEFAULT; 
}

int mais_zoom_cb( Ihandle *self)
{
   if( mundo_x >= 32 && mundo_y >=32 )
   {
      mundo_x /=1.5 ;
      mundo_y /=1.5 ;
   }
   char d[64] ;
   sprintf( d, "DX=%.5f, DY=%.5f", mundo_x/2048 ) ;
  // IupSetAttributes(iupcanvas, d );

   //repaint_cb( iupcanvas, 0, 0 ) ; 
   return IUP_DEFAULT ;
}
int menos_zoom_cb( Ihandle *self)
{
   mundo_x *=1.5 ;
   mundo_y *=1.5 ;

   if( mundo_x > max_mundo_x || mundo_y >max_mundo_y )
   {
      mundo_x = max_mundo_x ;
      mundo_y = max_mundo_y ;
   }
   char d[64] ;
   sprintf( d, "DX=%.5f, DY=%.5f", mundo_x/2048 ) ;
//   IupSetAttributes(iupcanvas, d );
  // repaint_cb( iupcanvas, 0, 0 ) ; 
   return IUP_DEFAULT ;
}
int menu_linha_cb( Ihandle *self)
{
   IupPopup( line_menu, IUP_MOUSEPOS, IUP_MOUSEPOS ) ;
   return IUP_DEFAULT ;
}
int tam( int a, int b )
{
   return  a*a+b*b  ; 
}
double d1x=100, d1y=100 ;
int button_cb(Ihandle* self, int botao, int estado, int x, int y)
{    
   float sx = IupGetFloat(self, IUP_POSX);
   float sy = -IupGetFloat(self, IUP_POSY);

   cdUpdateYAxis(&y);
   if(botao == IUP_BUTTON1 && estado)
   {
      // image[x][y] = 1;
      cdMark( x, y ) ;
      image[(int)(640.0*sx)+x][(int)(400.0*sy)+y] = 1;
      printf( "%s", IupGetAttribute( self, IUP_SIZE ) );
      //   printf( "% d %d\n", x, y ) ;
      /*
      via[n][0] = x ;
      via[n][1] = y ;
      n++ ; 

      escapes_pos[0][0] = via[0][0] ;//+ (via[1][0]-via[0][0])/2 ; 
      escapes_pos[0][1] = via[0][1] ;//+ (via[1][1]-via[0][1])/2 ;  
      for( int i=1 ; i<n-1 ; i++ )
      {
      escapes_pre[i][0] = (int)(via[i][0] + (via[i-1][0]-via[i+1][0]) * sqrt( (double)tam( via[i-1][0]-via[i][0], via[i-1][1]-via[i][1]) / tam( via[i-1][0]-via[i+1][0], via[i-1][1]-via[i+1][1]) ) / 2) ;
      escapes_pre[i][1] = (int)(via[i][1] + (via[i-1][1]-via[i+1][1]) * sqrt( (double)tam( via[i-1][0]-via[i][0], via[i-1][1]-via[i][1]) / tam( via[i-1][0]-via[i+1][0], via[i-1][1]-via[i+1][1]) ) / 2) ; 

      escapes_pos[i][0] = (int)(via[i][0] + (via[i+1][0]-via[i-1][0]) * sqrt( (double)tam( via[i+1][0]-via[i][0], via[i+1][1]-via[i][1]) / tam( via[i-1][0]-via[i+1][0], via[i-1][1]-via[i+1][1]) ) / 2) ;
      escapes_pos[i][1] = (int)(via[i][1] + (via[i+1][1]-via[i-1][1]) * sqrt( (double)tam( via[i+1][0]-via[i][0], via[i+1][1]-via[i][1])  / tam( via[i-1][0]-via[i+1][0], via[i-1][1]-via[i+1][1])) / 2) ;
      }
      escapes_pre[n-1][0] = via[n-1][0] ;//+ (via[n-2][0]-via[n-1][0])/2 ;
      escapes_pre[n-1][1] = via[n-1][1] ;//+ (via[n-2][1]-via[n-1][1])/2 ; 

      cdClear();

      if( n>2 )
      {
      cdForeground ( CD_RED ) ;
      cdLineStyle( CD_CONTINUOUS ) ; 
      cdBegin( CD_BEZIER ) ;
      cdVertex( via[0][0], via[0][1] ) ;
      cdVertex( escapes_pos[0][0], escapes_pos[0][1] ) ;

      for( int i=1 ; i<n-1 ; i++ )
      {
      cdVertex( escapes_pre[i][0], escapes_pre[i][1] ) ;
      cdVertex(         via[i][0],         via[i][1] ) ;
      cdVertex( escapes_pos[i][0], escapes_pos[i][1] ) ;
      }
      cdVertex( escapes_pre[n-1][0], escapes_pre[n-1][1] ) ;
      cdVertex(         via[n-1][0],         via[n-1][1] ) ;
      cdEnd() ;

      cdForeground ( CD_BLUE ) ;
      cdLineStyle( CD_DOTTED ) ; 
      cdLine( via[0][0], via[0][1], escapes_pos[0][0], escapes_pos[0][1] ) ;

      for( int i=1 ; i<n-1 ; i++ )
      {
      cdLine( escapes_pre[i][0], escapes_pre[i][1], via[i][0],  via[i][1] ) ;
      cdLine( escapes_pos[i][0], escapes_pos[i][1], via[i][0],  via[i][1] ) ;
      }
      cdLine( escapes_pre[n-1][0], escapes_pre[n-1][1], via[n-1][0], via[n-1][1] ) ;

      cdForeground ( CD_BLACK ) ;
      cdLineStyle( CD_CONTINUOUS ) ;
      cdgrampoP( via[0][0], via[0][1],.5 ) ;
      //cdMark( escapes_pos[0][0], escapes_pos[0][1] ) ;

      for( int i=1 ; i<n-1 ; i++ )
      {
      // cdMark( escapes_pre[i][0], escapes_pre[i][1] ) ;
      cdgrampoP(         via[i][0],         via[i][1],.5 ) ;
      // cdMark( escapes_pos[i][0], escapes_ pos[i][1] ) ;
      }
      // cdMark( escapes_pre[n-1][0], escapes_pre[n-1][1] ) ;
      cdgrampoP(         via[n-1][0],         via[n-1][1],.5 ) ;

      }
      }

      cdClear() ;
      //cdCristais( d1x, d1y, x, y ) ;
      cdAderencia( d1x, d1y, x, y ) ;
      //cdBuraco(x, y);
      //cdgrampoP( x+50, y+50,1 ) ;
      //cdCabo(1, 2, 3, 4 );
      d1x = x ;
      d1y = y ;*/
      // cdParada( 3, 100, 100 ) ;
      //  cdParada( 10, 200, 200 ) ;
      //  cdParada( 444, 300, 300 ) ;

      // cdDiedro( d1x, d1y, x, y ) ;
      //      cdOposicao( d1x, d1y, x, y ) ;
   }


   //cdMark(x,y);
   //image[(int)(320.0*sx)+x][(int)(200.0*sy)+y] = 1 ;
   /*
   wdViewport( 0, 640, 0, 400 ) ;

   cdForeground( CD_BLACK );
   wdWindow( 0, 1280, 0, 800 ) ;    
   grampoP( 640, 400,3 ) ; // wdArc( 640, 400, 150, 150, 0, 180 ) ;
   wdBegin(CD_BEZIER) ;
   wdVertex( 0, 0) ;

   wdVertex( 0, 0) ;
   wdVertex( 100, 0) ;

   wdVertex( 100, 100) ;

   wdVertex( 100, 300) ;
   wdVertex( 0, 100) ;

   wdVertex( 0, 300) ;

   wdVertex( 0, 380) ;
   wdVertex( 70, 300) ;

   wdVertex( 70, 380) ;

   wdVertex( 70, 430) ;
   wdVertex( 80, 380) ;

   wdVertex( 80, 430) ;
   wdEnd() ;

   wdMark( 0, 0) ;
   wdMark( 100, 100) ;
   wdMark( 0, 300) ;
   wdMark( 70, 380) ;
   wdMark( 80, 430) ;
   cdForeground( CD_BLUE );
   wdMark( 0, 0) ;
   wdMark( 100, 0) ;
   wdMark( 100, 300) ;
   wdMark( 0, 100) ;
   wdMark( 0, 380) ;
   wdMark( 70, 300) ;
   wdMark( 70, 430) ;
   wdMark( 80, 380) ;




   cdForeground( CD_BLUE );
   wdWindow( 160, 1120, 100, 700 ) ;    
   wdWindow( 160, 1120, 100, 700 ) ;    grampoP( 600, 400,3 ) ;
   //wdArc( 640, 400, 150, 150, 0, 180 ) ;

   cdForeground( CD_RED );
   wdWindow( 480, 800, 300, 500 ) ;    
   //wdArc( 640, 400, 150, 150, 0, 180 ) ;
   grampoP( 640, 300,5 ) ;
   */

   return IUP_DEFAULT;	
}

int motion_cb(Ihandle* self, int x, int y)
{
   Ihandle* label;
   static char buffer[40];	
   float sx = IupGetFloat(self, IUP_POSX);

   float sy = -IupGetFloat(self, IUP_POSY);

   sprintf(buffer,"(%d, %d)",(int)(320.0*sx)+x,(int)(200.0*sy)+y) ;

   label = IupGetHandle("label");
   IupStoreAttribute(label,IUP_TITLE,buffer);  

   return IUP_DEFAULT;
}

int scroll_cb(Ihandle* self)
{
   // repaint_cb(self,0.0,0.0);

   return IUP_DEFAULT;	
}

int enter_cb(Ihandle* self)
{
   cdBackground(CD_WHITE);	
   repaint_cb(self,0.0,0.0);

   return IUP_DEFAULT;
}

int leave_cb(Ihandle* self)
{
   Ihandle *label;	
   cdBackground(CD_GRAY);	
   repaint_cb(self,0.0,0.0);
   label = IupGetHandle("label");
   IupSetAttribute(label,IUP_TITLE,"IupCanvas");  

   return IUP_DEFAULT;
}
static int clrbrwsr_drag_cb(Ihandle *self, unsigned char r, unsigned char g, unsigned char b)
{
   return IUP_DEFAULT;
}

/******************************************************************************
* Function:                                                                  *
* ColorBrowser drag callback                                                 *
*                                                                            *
* Description:                                                               *
* This callback is associated to a definitive color change                   *
*                                                                            *
* Parameters received:                                                       *
* self - Element identifier                                                  *
* r    - red color component                                                 * 
* g    - green color component                                               *
* b    - blue color component                                                *
*                                                                            *
* Value returned:                                                            *
* IUP_DEFAULT                                                                *
******************************************************************************/
static int clrbrwsr_change_cb(Ihandle *self, unsigned char r, unsigned char g, unsigned char b)
{

   return IUP_DEFAULT;
}


int n_botoes_linhas = 7 ;
Ihandle* botoes()
{
   int b=0  ;
   Ihandle *button_box = IupVbox( NULL ) ;
   for( int i=0 ; i<n_botoes_linhas ; i++ )
   { 
      Ihandle *hbox = IupHbox( NULL ) ;
      for( int j=0 ; j<4 ; j++ )
      {
         if( !(i==1&&j==3) && !(i==6&&j==3))
         {
            Ihandle *image  = IupImage ( 32, 32, button_images[b]   ) ;
            //setImageColors( image ) ;
            Ihandle *button = IupButton( "", NULL ) ; //callbacks[i] ) ;
            IupSetHandle( image_names[b], image ) ;
            IupSetAttribute( button, IUP_IMAGE, image_names[b] );
            IupSetAttribute( button, "FLAT", IUP_YES );
            IupSetAttribute( button, IUP_TIP, button_hints[b] );
            IupSetAttribute( image, "15", IUP_BGCOLOR ) ;
            IupAppend( hbox, button ) ; 
            b++;
         }       
      }
      IupAppend( button_box, hbox ) ;     
   }
   return button_box ;
}

char *corestabela[] =
{
   "192 192 192", "255 255 255", "255 160 160", "160 255 160", "160 160 255","192 255 255", "255 192 255", "255 255 192",  
   "128 128 128",  "160 160 160",   "255 0 0",     "0 255 0",     "0 0 255",    "0 255 255",   "255 0 255",   "255 255 0",
   "64 64 64", "96 96 96",  "128 0 0",     "0 128 0",     "0 0 128",    "0 128 128",   "128 0 128",   "128 128 0",
   "0 0 0", "32 32 32",        "64 0 0",      "0 64 0",      "0 0 64",     "0 64 64",     "64 0 64",     "64 64 0" 
};

char* cell_cb(Ihandle* self, int cell)
{
  unsigned char r, g, b;
  int ri, gi, bi;
  static char str[30];
  sprintf(str, "CELL%d", cell);
  sscanf(IupGetAttribute(self, str), "%d %d %d", &ri, &gi, &bi);
  r = (unsigned char)ri; g = (unsigned char)gi; b = (unsigned char)bi;
  if (IupGetColor(IUP_MOUSEPOS, IUP_MOUSEPOS, &r, &g, &b))
  {
    sprintf(str, "%d %d %d", (int)r, (int)g, (int)b);
   // cdActivate( cdcanvas ) ;
   // cdForeground(cdEncodeColor(r, g, b));
   // repaint_cb(cnvs);
    return str;
  }
}

int select_cb(Ihandle* self, int cell, int type)
{


  return IUP_DEFAULT;
}
int switch_cb(Ihandle* self, int primcell, int seccell)
{

  return IUP_DEFAULT;
}

//******************************************************************

Ihandle *line_styles_menu()
{
   Ihandle *menu = IupMenu( NULL ) ;

   for( int i=0 ; i<5 ; i++ )
   { Ihandle *item = IupItem(line_styles_names[i], NULL );
           Ihandle *image  = IupImage ( 16, 16, line_style_images[i]   ) ;
           IupSetHandle( line_styles_names[i], image ) ;
            IupSetAttribute( item, IUP_IMAGE, line_styles_names[i] );
            IupSetAttribute( image, "15", IUP_BGCOLOR ) ;


     
      IupAppend( menu, item ) ;
   }
   return menu ;
}







//******************************************************************

int main()
{Ihandle *iupcanvas;
   Ihandle* dlg,  *label;	

   int x,y;

   for(x=0;x<640;x++)
      for(y=0;y<400;y++)
         image[x][y]=0;	    

   IupOpen();
   IupControlsOpen () ;

   label = IupLabel("IupCanvas");
   IupSetHandle("label", label);

   iupcanvas = IupCanvas(NULL);

   Ihandle* mais_zoom = IupButton( "+", "mais_zoom" ) ;
   Ihandle* menos_zoom = IupButton( "-", "menos_zoom" ) ;

   IupSetFunction( "menos_zoom",(Icallback)menos_zoom_cb ) ;
   IupSetFunction( "mais_zoom",(Icallback)mais_zoom_cb ) ;

   IupSetAttributes(iupcanvas, "CURSOR=CROSS, RASTERSIZE=400x500, EXPAND=NO, SCROLLBAR=YES, DX=0.5, DY=0.5");

   IupSetCallback(iupcanvas, "ACTION",(Icallback)repaint_cb);
   IupSetCallback(iupcanvas, "BUTTON_CB",(Icallback)button_cb);
   IupSetCallback(iupcanvas, "SCROLL_CB",(Icallback)scroll_cb);
   IupSetCallback(iupcanvas, "MOTION_cb",(Icallback)motion_cb);
   IupSetCallback(iupcanvas, "ENTERWINDOW_CB",(Icallback)enter_cb);
   IupSetCallback(iupcanvas, "LEAVEWINDOW_CB",(Icallback)leave_cb);

   Ihandle* cores = IupColorbar( ) ; 
 // IupSetCallback(cores, "SELECT_CB", (Icallback)select_cb);
  //IupSetCallback(cores, "CELL_CB", (Icallback)cell_cb);
  //IupSetCallback(cores, "SWITCH_CB", (Icallback)switch_cb);


   IupSetAttribute(cores, "NUM_CELLS", "32" );
   IupSetAttribute(cores, "NUM_PARTS", "4" );
   IupSetAttribute(cores, "RASTERSIZE", "100x200");
   IupSetAttribute(cores, "EXPAND", "HORIZONTAL");
   IupSetAttribute(cores, "ORIENTATION", "HORIZONTAL");
   for( int xx=0 ; xx<32 ; xx++ )
   {
      char  atrib[64];
      sprintf( atrib, "CELL%d", xx );
      IupSetAttribute(cores, atrib,corestabela[xx]);
  }

   Ihandle* but_menu = IupButton( "linha", "linha_Cb" ) ;
   IupSetFunction( "linha_Cb",(Icallback)menu_linha_cb ) ;
   line_menu = line_styles_menu();

   Ihandle* hobx = IupHbox( IupVbox( botoes(), but_menu, IupHbox(cores, NULL), NULL ),
      IupVbox( iupcanvas,
      IupHbox(IupFill(),label,IupFill(), NULL),
      IupHbox( mais_zoom, menos_zoom, NULL ),
      NULL ),
      NULL ) ;



   dlg = IupDialog(hobx);

   IupSetAttributes(dlg, "TITLE=IupCanvas, RESIZE=NO, MAXBOX=NO");

   IupShowXY(dlg,IUP_CENTER,IUP_CENTER);


   cdcanvas = cdCreateCanvas(CD_IUP, iupcanvas);
   if(!cdcanvas)
   {
      IupMessage("IupCanvas","Error creating canvas");
      IupDestroy(dlg);
      IupClose();
      return 0 ;
   }

   if(cdActivate(cdcanvas) == CD_ERROR)
   {
      IupMessage("IupCanvas","Error creating canvas");
      IupDestroy(dlg);
      IupClose();
      return 0 ;
   }

   cdClear();
   IupMainLoop();
   IupDestroy(dlg);
   IupControlsClose () ;
   IupClose();
   return 0;
}