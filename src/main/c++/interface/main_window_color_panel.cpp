#include "main_window_class.h"
#include "iupcontrols.h"
#include "stdio.h"
#include "color_box.h"
#include "image.h"

#include <stdlib.h>
#include "iupcontrols.h"
#include "fundo_bt16.h"
#include "bg_color_toggles.h"
#include "im.h"
#include "image.h"
#include "cd.h"
#include "wd.h"
#include "image_saver.h"

#include "commands\change_color_command.h"



int MainWindow::scrollColorBarChange_cb( long color )
{
   if( _selected_obj.size() > 0)
   {
      std::vector< long int > old_colors;
      for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
      {
         old_colors.push_back( _selected_obj[o]->color() ) ;        
         _selected_obj[o]->color(color ) ;        
      } 


      ChangeColorCommand* command = new ChangeColorCommand( _selected_obj, color, old_colors );
      CommandStack::insert( command );

      repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
   }
   else
      _project->color( color ) ;



  
   return IUP_DEFAULT ;
}

//
//
//
//
//
//
//
//
//
//
unsigned char sun_pix[16*16] = 
{
   1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
      ,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
      ,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
      ,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1
      ,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1
      ,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1
      ,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1
      ,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0
      ,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1
      ,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1
      ,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1
      ,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1
      ,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1
      ,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1
      ,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1
      ,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1
} ;
//static char * main_colors[] =
//{
//   "192 192 192", "255 255 255", "255 160 160", "160 255 160", "160 160 255","192 255 255", "255 192 255", "255 255 192",  
//      "128 128 128",  "160 160 160",   "255 0 0",     "0 255 0",     "0 0 255",    "0 255 255",   "255 0 255",   "255 255 0",
//      "64 64 64", "96 96 96",  "128 0 0",      "0 128 0",     "0 0 128",    "0 128 128",   "128 0 128",   "128 128 0",
//      "0 0 0", "32 32 32",        "64 0 0",      "0 64 0",      "0 0 64",     "0 64 64",     "64 0 64",     "64 64 0" 
//};
int MainWindow::backGroundColorToggle_cb (Ihandle*togle)
{
   for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
   {
      Image* img = 0;
      img = dynamic_cast<Image*>( _selected_obj[o] );

      if( img )
      {
         img->setColored();
         
      }
   }
   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;

   return IUP_DEFAULT ;
}
//int MainWindow::colorPaletteCell_cb(Ihandle* palette, int cell, int type) 
//{
//   if( type != -1 )
//      return IUP_IGNORE ;
//
//   char cellstr[9] ;
//   sprintf( cellstr, "CELL%d", cell ) ;
//   std::string new_color_value = IupGetAttribute( palette, cellstr ) ;
//   int r, g, b ;
//   sscanf( new_color_value.c_str(), "%d %d %d", &r, &g, &b ) ;
//   _project->color( cdEncodeColor( r, g, b ) ) ;
//
//
//
//   /** remover daqui **/   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;   /** remover daqui **/
//
//   return IUP_DEFAULT ;
//};
//
//int MainWindow::colorBrowserChange_cb( Ihandle *browser, unsigned char r, unsigned char g, unsigned char b)
//{
//   if( _selected_obj.size() > 0)
//   {
//      for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
//      {
//         _selected_obj[o]->color( cdEncodeColor(r, g, b ) ) ;        
//      } 
//      repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
//   }
//   else
//      _project->color( cdEncodeColor( r, g, b ) ) ;
//
//   return IUP_DEFAULT ;
//}
//
//
//
//
//
//
//Ihandle* MainWindow::createColorPanel()
//{
//   //ColorBox *box = new ColorBox( 255, 0, 0, (ColorBox::ColorBoxCallback) colorBrowserChange_cb );
//   //return box->box();
//
//
//   //char* error = 0;
//   //error = IupLoad( "..\\misc\\button_images\\color\\selected_color_bt_img.led" ) ;
//   ////      error = IupLoad( img_order_sel_files[i] ) ;
//
//
//   Ihandle* colors = IupColorBrowser() ;
//   IupSetAttribute(colors, "EXPAND", "NO");
//   IupSetAttribute(colors, "RGB", "0 0 0");
//   IupSetAttribute(colors, "BGCOLOR", "0 0 0");
//   IupSetCallback(colors, "CHANGE_CB", (Icallback)colorBrowserChange_cb);
//
//
//   //Ihandle* vbox = IupVbox( button, colors, NULL );
//   //IupSetAttribute(vbox, IUP_MARGIN, "5x1");
//
//   //Ihandle* colors = IupColorbar( ) ; 
//
//   //IupSetfAttribute(colors, "NUM_CELLS", "%d", 32 );
//   //IupSetAttribute(colors, "NUM_PARTS", "4" );
//   //IupSetAttribute(colors, "RASTERSIZE", "100x200");
//
//   //IupSetAttribute(colors, "ORIENTATION", "HORIZONTAL");
//   //IupSetCallback(colors, "SELECT_CB", (Icallback)colorPaletteCell_cb);
//
//   //for( int i=0 ; i<32 ; i++ )
//   //{
//   //   char atrib[64];
//   //   sprintf( atrib, "CELL%d", i );
//   //   IupSetAttribute(colors, atrib,main_colors[i]);
//   //}
//   return colors ;
//} 
//
int MainWindow::lightSlider_cb (Ihandle*slider, double value)
{
   for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
   {
      Image* img = 0;
      img = dynamic_cast<Image*>( _selected_obj[o] );

      if( img )
      {
         img->setIntensity(value) ;
         repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
      }
   }

   return IUP_DEFAULT ;
}

Ihandle * MainWindow::createAdtionalColorOptionsFrame()
{
   /** Slider to fade in/out **/
   Ihandle *label = IupLabel("") ;
   Ihandle *imglbl = IupImage(  16, 16, sun_pix ) ;
   IupSetAttribute( imglbl, "0", "0 0 0" ) ;
   IupSetAttribute( imglbl, "1", IUP_BGCOLOR ) ;
   IupSetHandle( "SUNLBL", imglbl ) ;
   IupSetAttribute( label, IUP_IMAGE, "SUNLBL" ) ;
   _colorIntensitySlider = IupVal( IUP_HORIZONTAL ) ;
   IupSetAttribute( _colorIntensitySlider, IUP_EXPAND, IUP_YES );
   IupSetAttribute( _colorIntensitySlider, "SHOWTICKS", "3" );
  // IupSetAttribute( _colorIntensitySlider, IUP_RASTERSIZE, "50x" );
   IupSetCallback( _colorIntensitySlider, "MOUSEMOVE_CB", (Icallback)lightSlider_cb );


   //IupSetAttribute( slider, "HANDLER_IMAGE", "SUNLBL" ) ;


   Ihandle *imageu  = IupImage ( 10, 16, color_image ) ;
   Ihandle *imagep  = IupImage ( 10, 16, color_image_press ) ;
   for( int c=0 ; c<16 ; c++ )
   {
      IupSetAttribute( imageu, index_str[c], bt_color_values[0][c] ) ;
      IupSetAttribute( imagep, index_str[c], bt_color_values[0][c] ) ;
   }
   IupSetAttribute( imagep, "0", "0 0 0 " ) ;
   Ihandle *toggle = IupButton( "", NULL ) ; 
   IupSetHandle( color_names[0], imageu   ) ;
   IupSetHandle( color_names_p[0], imagep ) ;
   IupSetAttribute( toggle, IUP_IMAGE, color_names[0] );
   IupSetAttribute( toggle, IUP_IMPRESS, color_names_p[0] );
   IupSetAttribute( toggle, IUP_TIP, color_names[0] );
   IupSetAttribute( toggle, "COLOR VALUE", color_values[0] ) ;
   IupSetCallback( toggle, IUP_ACTION, (Icallback)backGroundColorToggle_cb );
   IupSetAttribute( toggle, IUP_EXPAND, IUP_NO );


   /** Composing the frame **/
   Ihandle * hboxslider = IupHbox( _colorIntensitySlider,label, NULL ) ;
   IupSetAttribute( hboxslider, IUP_ALIGNMENT, IUP_ACENTER ) ;
   IupSetAttributes( hboxslider, "MARGIN=0x0, GAP=0x0" ) ;
   IupSetAttribute( hboxslider, IUP_EXPAND, IUP_YES ) ;

   Ihandle * hboxdefaultdlor = IupHbox( toggle,NULL ) ;
   IupSetAttributes( hboxdefaultdlor, "MARGIN=0x0, GAP=0x0" ) ;
   IupSetAttribute( hboxdefaultdlor, IUP_ALIGNMENT, IUP_ACENTER ) ;
   IupSetAttribute( hboxdefaultdlor, IUP_EXPAND, IUP_VERTICAL ) ;

   Ihandle * hboxtop = IupHbox( hboxdefaultdlor,hboxslider, NULL ) ;
   IupSetAttributes( hboxtop, "MARGIN=0x0, GAP=22x0" ) ;
   IupSetAttribute( hboxtop, IUP_ALIGNMENT, IUP_ACENTER ) ;
   IupSetAttribute( hboxtop, IUP_EXPAND, IUP_YES ) ;

   _colorIntensityFrame = hboxslider;
   return hboxslider ;
}