#include "main_window_class.h"

#include "iup.h"
#include "button_images.h"

int MainWindow::objectButton_cb(Ihandle* button)
{
   if( _builder )
      _builder->cancel() ;
   repaintMainCanvas_cb( _iupcanvas, 0,0 ) ;
   _builder = (Builder*)IupGetAttribute( button, "BUILDER" ) ;
   _cursor = IUP_CROSS ;
   return IUP_DEFAULT ;
};
int MainWindow::arrowButton_cb(Ihandle* button)
{
   if( _builder )
      _builder->cancel() ;
   _builder = NULL ;
   _cursor = IUP_ARROW ;
   return IUP_DEFAULT ;
};
Ihandle * MainWindow::createObjButtons()
{
   Ihandle *v_box = IupVbox( NULL ) ;

   int b=0;
   for( int i=0 ; i<8 ; i++ )
   {
      Ihandle *h_box = IupHbox( NULL ) ;
      for( int j=0 ; j<4 ; j++ )
      {          
         if( !(i==1&&j==3) )
         {
            Ihandle *image  = IupImage ( 24, 24, button_images[b]   ) ;
            Ihandle *button = IupButton( "", NULL ) ; //callbacks[i] ) ;
            IupSetHandle( image_names[b], image ) ;
            IupSetAttribute( button, IUP_IMAGE, image_names[b] );
            //IupSetAttribute( button, "FLAT", IUP_YES );
            IupSetAttribute( button, IUP_TIP, button_hints[b] );
            IupSetAttribute( button, "BUILDER", (char*)button_builders[b] );
            IupSetAttribute( image, "15", IUP_BGCOLOR ) ;
            IupAppend( h_box, button ) ; 
            IupSetCallback( button, IUP_ACTION, (Icallback)objectButton_cb ) ;
            if( !button_builders[b] )
            {
            IupSetAttribute( button, IUP_ACTIVE, IUP_NO );
            }
            b++;
         }    
         
      }
      IupAppend( v_box, h_box ) ; 
   }

   return v_box ;
}