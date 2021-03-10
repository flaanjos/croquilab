//#include "iup.h"
//#include "colorBox.h"
//
//   static int cbButton( Ihandle *button ) ;
//   static int cbBrowser( Ihandle *browser, char r, char g, char b ) ;
//
//   typedef int (*ColoBoxCallback)( char r, char b, char b );
//
//   ColorBox::ColorBox( char r, char g, char b, ColoBoxCallback cb )
//   {
//      static int instanceCounter = 0 ;
//
//      _callback = cb;
//      char rgb[16];
//      sprintf( rgb, "%d %d %d", r, g, b );
//
//      char* error = NULL;
//      error = IupLoad( "..\\misc\\button_images\\color\\selected_color_bt_img.led" ) ;
//      _selected_color_bt_img = IupGetHandle( "selected_color_bt_img" ) ;
//      char new_handler[128];
//      sprintf( new_handler,  "selected_color_bt_img_%d", instanceCounter );
//      instanceCounter++;
//      IupSetHandle( new_handler, _selected_color_bt_img );
//      IupSetAttribute( _selected_color_bt_img, "0", rgb );
//
//      _selected_color_bt = IupButton( NULL, NULL );
//      IupSetAttribute( _selected_color_bt, IUP_IMAGE, "selected_color_bt_img" );
//      IupSetAttribute( _selected_color_bt, IUP_IMPRESS, "selected_color_bt_img" );
//      IupSetAttribute( _selected_color_bt, "FLAT", IUP_YES );
//      IupSetAttribute( _selected_color_bt, "ColorBoxImp", *this );
//      IupSetCallback( _selected_color_bt, IUP_ACTION, (Icallback)cbButton ) ;
//
//      _browser = IupColorBrowser() ;
//      IupSetAttribute( _browser, "EXPAND", "NO");
//      IupSetAttribute( _browser, "RGB", rgb );
//      IupSetAttribute( _browser, "BGCOLOR", "0 0 0");
//      IupSetAttribute( _browser, "ColorBoxImp", *this );
//      IupSetCallback( _browser, "CHANGE_CB", (Icallback)cbBrowser );
//
//
//       _box = IupVbox( button, colors, NULL );
//      IupSetAttribute( _box, IUP_MARGIN, "5x1");
//   };
//
//   ~ColorFrame()
//   {
//   };
//
//   void ColorBox::selectedColor( char& r, char& g, char& b )
//   {
//      r = _red ;
//      g = _green ;
//      b = _blue ;
//   };
//
//   void ColorBox::selectColor( char r, char g, char b ) ;
//   {
//      _red = r;
//      _green = g;
//      _blue = b;
//
//      char rgb[16];
//      sprintf( rgb, "%d %d %d", r, g, b );
//      IupSetAttribute( _selected_color_bt_img, "0", rgb );
//      IupSetAttribute( _browser, "RGB", rgb );
//   };
//
//   Ihandle *box();
//
//private:
//   Ihanlde *_box;
//   Ihandle *_browser;
//   Ihandle *_selected_color_bt;
//};
//
