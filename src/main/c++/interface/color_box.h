
#include "iup.h"

class ColorBox
{
public:
   typedef int (*ColorBoxCallback)( unsigned char r, unsigned char g, unsigned char b );

   ColorBox( unsigned char r, unsigned char g, unsigned char b, ColorBoxCallback cb ) ;
   ~ColorBox() ;

   void selectedColor( unsigned char& r, unsigned char& g, unsigned char& b ) ;
   void selectColor( unsigned char r, unsigned char g, unsigned char b ) ;

   Ihandle *box();

   static int cbButton( Ihandle *button ) ;
   static int cbBrowser( Ihandle *browser, unsigned char r, unsigned char g, unsigned char b ) ;

private:

   Ihandle *_box ;
   Ihandle *_browser ;
   Ihandle *_selected_color_bt ;
public:

   Ihandle *_selected_color_bt_img ;
   unsigned char _red ;
   unsigned char _green ;
   unsigned char _blue ;
   ColorBoxCallback _callback ;
   char _img_handle[128] ;
};