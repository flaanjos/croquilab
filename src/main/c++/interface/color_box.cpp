#include "stdlib.h"
#include "color_box.h"
#include "stdio.h"

#include "iup.h"
#include "iupcontrols.h"



int ColorBox::cbButton( Ihandle *button )
{
   ColorBox* box = (ColorBox*)IupGetAttribute( button, "ColorBoxImp" ) ;
   if( box->_callback )
   {
      box->_callback( box->_red, box->_green, box->_blue ) ;
   }

   return IUP_DEFAULT ;
}



int ColorBox::cbBrowser( Ihandle *browser, unsigned char r, unsigned char g, unsigned char b )
{
   ColorBox* box = (ColorBox*)IupGetAttribute( browser, "ColorBoxImp" ) ;

   box->selectColor( r, g, b );
   if( box->_callback )
   {
      box->_callback( box->_red, box->_green, box->_blue ) ;
   }

   return IUP_DEFAULT ;
}



ColorBox::ColorBox( unsigned char r, unsigned char g, unsigned char b, ColorBoxCallback cb ) 
{
   static int instance_counter = 0 ;

   _red = r;
   _green = g;
   _blue = b;
   char rgb[16];
   sprintf( rgb, "%d %d %d", r, g, b );

   _callback = cb;

   char* error = NULL;
   error = IupLoad( "..\\misc\\button_images\\color\\selected_color_bt_img.led" ) ;
   _selected_color_bt_img = IupGetHandle( "selected_color_bt_img" ) ;
   sprintf( _img_handle,  "selected_color_bt_img_%d", instance_counter );
   instance_counter++;
   IupSetHandle( _img_handle, _selected_color_bt_img );

   IupStoreAttribute( _selected_color_bt_img, "0", rgb );
   _selected_color_bt = IupButton( NULL, NULL );
   IupSetAttribute( _selected_color_bt, IUP_IMAGE, _img_handle );
   IupSetAttribute( _selected_color_bt, IUP_IMPRESS, _img_handle );
   IupSetAttribute( _selected_color_bt, "FLAT", IUP_YES );
   IupSetAttribute( _selected_color_bt, "ColorBoxImp", (char*)this );
   IupSetCallback( _selected_color_bt, IUP_ACTION, (Icallback)cbButton ) ;

   _browser = IupColorBrowser() ;
   IupSetAttribute( _browser, "EXPAND", "NO");
   IupSetAttribute( _browser, "RGB", rgb );
   IupSetAttribute( _browser, "BGCOLOR", "0 0 0");
   IupSetAttribute( _browser, "ColorBoxImp", (char*)this );
   IupSetCallback( _browser, "CHANGE_CB", (Icallback)cbBrowser );


   _box = IupVbox( _selected_color_bt, _browser, NULL );
   IupSetAttribute( _box, IUP_MARGIN, "5x1");
};

ColorBox::~ColorBox()
{
};

void ColorBox::selectedColor( unsigned char& r, unsigned char& g, unsigned char& b ) 
{
   r = _red ;
   g = _green ;
   b = _blue ;
};

void ColorBox::selectColor( unsigned char r, unsigned char g, unsigned char b ) 
{
   _red = r;
   _green = g;
   _blue = b;

   char rgb[16];
   sprintf( rgb, "%d %d %d", r, g, b );

   IupSetAttribute( _selected_color_bt, IUP_IMAGE, "" );
   IupSetAttribute( _selected_color_bt, IUP_IMPRESS, "" );
   IupDestroy ( _selected_color_bt_img) ;

   char* error = NULL;
   error = IupLoad( "..\\misc\\button_images\\color\\selected_color_bt_img.led" ) ;
   _selected_color_bt_img = IupGetHandle( "selected_color_bt_img" ) ;
   IupSetHandle( _img_handle, _selected_color_bt_img );
   IupStoreAttribute( _selected_color_bt_img, "0", rgb );

   IupSetAttribute( _selected_color_bt, IUP_IMAGE, _img_handle);
   IupSetAttribute( _selected_color_bt, IUP_IMPRESS, _img_handle );


   IupSetAttribute( _browser, "RGB", rgb );
};

Ihandle *ColorBox::box()
{
   return _box ;
};

