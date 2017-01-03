#include "main_window_class.h"

#include "iup.h"
#include "cd.h"
#include "wd.h"

static unsigned char zoom_out_pix[] =
{
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 2, 3, 3, 3, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 2, 0, 3, 3, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1, 2, 1, 0, 2, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 2, 1, 1, 1, 2, 2, 1, 2, 0, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 0, 0, 0, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      -1 
};

static unsigned char zoom_in_pix[] =
{
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 2, 3, 3, 3, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 2, 0, 3, 3, 1, 0, 0, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 3, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 2, 0, 1, 1, 1, 0, 0, 1, 2, 1, 0, 2, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 2, 1, 1, 1, 2, 2, 1, 2, 0, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 0, 0, 0, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      -1 
};

static unsigned char no_zoom_pix[] =
{
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
      1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      -1
};

int MainWindow::ZoomOutButton_cb( Ihandle* bt )
{
  _zoom *= 1.5f ;

   int w = 581 ;
   int h = 581 ;
   float posx = 3000 ;
   float posy = 5999 ; 

   sscanf( IupGetAttribute( _iupcanvas, "DRAWSIZE" ), "%dx%d", &w, &h ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSX" ), "%f", &posx ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSY" ), "%f", &posy ) ;

   w = _zoom*w ;
   h = _zoom*h ;
   posy = 5999-posy ;

   wdCanvasWindow( _dbuffer, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   wdCanvasWindow( _select_canvas, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   cdActivate( _dbuffer ) ;
   repaintMainCanvas_cb( _iupcanvas, posx, posy ) ;



   //double xmin=0; double xmax=1; double ymin=0; double ymax=1 ;
   //wdCanvasGetWindow( _dbuffer, &xmin, &xmax, &ymin, &ymax );
   //double xmid = (xmin+xmax)/2;
   //double ymid = (ymin+ymax)/2;
   //wdCanvasWindow( _dbuffer, xmid-xmax+xmin-1, xmid+xmax-xmin+1, ymid-ymax+ymin-1, ymid+ymax-ymin+1 ) ;
   //wdCanvasWindow( _select_canvas, xmid-xmax+xmin-1, xmid+xmax-xmin+1, ymid-ymax+ymin-1, ymid+ymax-ymin+1 ) ;
   //repaintMainCanvas_cb(_iupcanvas, 0, 0);
   return IUP_DEFAULT ;
}
int MainWindow::ZoomInButton_cb( Ihandle* bt )
{
  _zoom /= 1.5f ;

   int w = 581 ;
   int h = 581 ;
   float posx = 3000 ;
   float posy = 5999 ; 

   sscanf( IupGetAttribute( _iupcanvas, "DRAWSIZE" ), "%dx%d", &w, &h ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSX" ), "%f", &posx ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSY" ), "%f", &posy ) ;

   w = _zoom*w ;
   h = _zoom*h ;
   posy = 5999-posy ;

   wdCanvasWindow( _dbuffer, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   wdCanvasWindow( _select_canvas, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   cdActivate( _dbuffer ) ;
   repaintMainCanvas_cb( _iupcanvas, posx, posy ) ;
   return IUP_DEFAULT ;
}
int MainWindow::NoZoomButton_cb( Ihandle* bt )
{
  _zoom = 1.0f ;

   int w = 581 ;
   int h = 581 ;
   float posx = 3000 ;
   float posy = 5999 ; 

   sscanf( IupGetAttribute( _iupcanvas, "DRAWSIZE" ), "%dx%d", &w, &h ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSX" ), "%f", &posx ) ;
   sscanf( IupGetAttribute( _iupcanvas, "POSY" ), "%f", &posy ) ;

   w = _zoom*w ;
   h = _zoom*h ;
   posy = 5999-posy ;

   wdCanvasWindow( _dbuffer, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   wdCanvasWindow( _select_canvas, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   cdActivate( _dbuffer ) ;
   repaintMainCanvas_cb( _iupcanvas, posx, posy ) ;
   return IUP_DEFAULT ;
}


Ihandle * MainWindow::createZoomButtons()
{
   Ihandle *image  = NULL ;
   Ihandle *button = NULL ;

   image = IupImage ( 20, 20, zoom_out_pix ) ;
   IupSetHandle( "IMG_ZOOMOUT", image ) ;
   IupSetAttribute( image, "0", "0 0 0" ) ;
   IupSetAttribute( image, "1", IUP_BGCOLOR ) ;
   IupSetAttribute( image, "2", "128 128 128" ) ;
   IupSetAttribute( image, "3", "255 255 255" ) ;

   Ihandle *bt_zo = IupButton( "", NULL ) ; 
   IupSetAttribute( bt_zo, IUP_IMAGE, "IMG_ZOOMOUT" );
   IupSetAttribute( bt_zo, "FLAT", IUP_YES );
   IupSetAttribute( bt_zo, IUP_TIP, "afastar" );
   IupSetCallback( bt_zo, IUP_ACTION, (Icallback)ZoomOutButton_cb ) ;

   image = IupImage ( 20, 20, zoom_in_pix ) ;
   IupSetHandle( "IMG_ZOOMIN", image ) ;
   IupSetAttribute( image, "0", "0 0 0" ) ;
   IupSetAttribute( image, "1", IUP_BGCOLOR ) ;
   IupSetAttribute( image, "2", "128 128 128" ) ;
   IupSetAttribute( image, "3", "255 255 255" ) ;

   Ihandle *bt_zi = IupButton( "", NULL ) ; 
   IupSetAttribute( bt_zi, IUP_IMAGE, "IMG_ZOOMIN" );
   IupSetAttribute( bt_zi, "FLAT", IUP_YES );
   IupSetAttribute( bt_zi, IUP_TIP, "aproximar" );
   IupSetCallback( bt_zi, IUP_ACTION, (Icallback)ZoomInButton_cb ) ;


   image = IupImage ( 20, 20, no_zoom_pix ) ;
   IupSetHandle( "IMG_NOZOOM", image ) ;
   IupSetAttribute( image, "0", "0 0 0" ) ;
   IupSetAttribute( image, "1", IUP_BGCOLOR ) ;
   IupSetAttribute( image, "2", "128 128 128" ) ;
   IupSetAttribute( image, "3", "255 255 255" ) ;

   Ihandle *bt_nz = IupButton( "", NULL ) ; 
   IupSetAttribute( bt_nz, IUP_IMAGE, "IMG_NOZOOM" );
   IupSetAttribute( bt_zi, "FLAT", IUP_YES );
   IupSetAttribute( bt_nz, IUP_TIP, "distância padrão" );
   IupSetCallback( bt_nz, IUP_ACTION, (Icallback)NoZoomButton_cb ) ;

   Ihandle* hbox = IupHbox( bt_zi, bt_zo, bt_nz, NULL );
   IupSetAttributes( hbox, "MARGIN=0x0, GAP=0" ) ;

   return hbox ;
}

