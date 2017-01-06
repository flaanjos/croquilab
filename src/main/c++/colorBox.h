#pragma once
#ifndef _COLOR_BOX__
#define _COLOR_BOX__ 1
#include "iup.h"

class ColorBox
{
   typedef int (*ColoBoxCallback)( char r, char b, char b );

   ColorBox( char r, char g, char b, ColoBoxCallback cb ) ;
   ~ColorBox() ;

   void selectedColor( char& r, char& g, char& b ) ;
   void selectColor( char r, char g, char b ) ;

   Ihandle *box();

   static int cbButton( Ihandle *button ) ;
   static int cbBrowser( Ihandle *browser, char r, char g, char b ) ;

private:
   char _red, _green, _blue ;
   Ihandle *_box ;
   Ihandle *_browser ;
   Ihandle *_selected_color_bt ;
   Ihandle *_selected_color_bt_img ;

 
   ColoBoxCallback _callback ;
};

#endif
