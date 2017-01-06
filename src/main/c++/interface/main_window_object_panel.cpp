#include "../buttonImages.h"
#include "main_window_class.h"

#include "iup.h"

int MainWindow::objectButton_cb(Ihandle* button)
{
   if( _builder )
      _builder->cancel() ;
   _selected_obj.clear();
   _manipulator = 0 ;
   repaintMainCanvas_cb( _iupcanvas, 0,0 ) ;
   char img_name[100] ;
   sprintf( img_name, "p%s", IupGetAttribute( button, IUP_IMAGE ) ) ;
   // IupStoreAttribute( button, IUP_IMAGE, img_name )  ;
   _builder = (Builder*)IupGetAttribute( button, "BUILDER" ) ;
   _cursor = IUP_CROSS ;
   syncMenus() ;
   return IUP_DEFAULT ;
};


int MainWindow::arrowButton_cb(Ihandle* button)
{
   if( _builder )
      _builder->cancel() ;
   _builder = 0 ;
   _cursor = IUP_ARROW ;
   syncMenus() ;
   return IUP_DEFAULT ;
}


Ihandle * MainWindow::createObjButtons()
{
   int buttons_per_line[7] = {1, 6, 5, 5, 6, 6, 6 };
   Ihandle *v_box = IupVbox( NULL ) ;

   int b=0;
   for( int i=0 ; i<7 ; i++ )
   {
      Ihandle *h_box = IupHbox( NULL ) ;
      int n =buttons_per_line[i] ;
      for( int j=0 ; j<n ; j++ )
      {    
         char* error = 0;
         error = IupLoad( pressed_button_image_files[b] ) ;
         error = IupLoad( button_image_files[b] ) ;
         Ihandle *button = IupToggle( "", NULL ) ; 
         IupSetAttribute( button, IUP_IMAGE, image_names[b] );
         IupSetAttribute( button, "FLAT", IUP_YES );
         IupSetAttribute( button, IUP_TIP, button_hints[b] );
         IupSetAttribute( button, "BUILDER", (char*)button_builders[b] );
         IupSetAttribute( button, "PADDING", "0x0" ) ;
         IupAppend( h_box, button ) ; 
         IupSetCallback( button, IUP_ACTION, (Icallback)objectButton_cb ) ;
         b++;  
      }
      IupSetAttributes( h_box, "MARGIN=0x0, GAP=0" );
      IupAppend( v_box, h_box ) ; 
   }
   IupSetAttributes( v_box, "MARGIN=5x5, GAP=0" );
   return v_box ;
}