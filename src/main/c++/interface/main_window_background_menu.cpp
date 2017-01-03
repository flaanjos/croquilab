#include "main_window_class.h"
#include <stdlib.h>
#include "iupcontrols.h"
#include "fundo_bt16.h"
#include "bg_color_toggles.h"
#include "im.h"
#include "image.h"
#include "cd.h"
#include "wd.h"
#include "image_saver.h"
//unsigned char sun_pix[16*16] = 
//{
//   1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
//      ,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
//      ,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
//      ,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1
//      ,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1
//      ,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1
//      ,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1
//      ,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0
//      ,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1
//      ,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1
//      ,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1
//      ,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1
//      ,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1
//      ,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1
//      ,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1
//      ,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1
//} ;

//int MainWindow::backGroundImageButton_cb (Ihandle*button)
//{
//   char nome[5000]  ;
//   if( IupGetFile( nome ) != 0 )
//   {
//      return IUP_DEFAULT ;
//   }
//
//
//   int error =IM_ERR_NONE ;
//   imFile* ifile = imFileOpen(nome, &error);
//   if (error != IM_ERR_NONE) 
//   {
//      if (error == IM_ERR_OPEN) { IupMessage( "Erro", "O aplicativo encontrou um erro ao abrir o arquivo." ) ; }      /**< Error while opening the file (read or write). */
//      else if (error ==  IM_ERR_ACCESS) { IupMessage( "Erro", "O aplicativo não tem permissão para ler este arquivo." ) ;  }    /**< Error while accessing the file (read or write). */
//      else if (error ==  IM_ERR_FORMAT) { IupMessage( "Erro", "O aplicativo não reconhece o formato deste arquivo." ) ;  }    /**< Invalid or unrecognized file format. */
//      else if (error ==  IM_ERR_DATA) { IupMessage( "Erro", "O aplicativo não dá suporte para o formato de armazenamento de dados nesta imagem." ) ;  }      /**< Invalid or unsupported data. */
//      else if (error ==  IM_ERR_COMPRESS) { IupMessage( "Erro", "O aplicativo não dá suporte para o formato de compressão desta imagem." ) ;  }  /**< Invalid or unsupported compression. */
//      else if (error ==  IM_ERR_MEM) { IupMessage( "Erro", "O aplicativo não conseguiu memória suficiente para trabalhar com esta imagem." ) ;  }       /**< Insuficient memory */
//      else if (error ==  IM_ERR_COUNTER) { IupMessage( "Erro", "O aplicativo não conseguiu interpretar o tamanho desta imagem." ) ;  }    /**< Interrupted by the counter */
//      else{ IupMessage( "Erro", "O aplicativo não conseguiu interpretar esta imagem." ) ;  }
//      return IUP_DEFAULT ;
//   }
//   // Deleting old background
///*   Object *o = _project->editor().getBackground() ;
//   _project->editor().removeBackground() ;  */ 
//   delete o ;
//
//   // Creating new background
//   Image* img = new Image( ifile ) ;
//
//   // setting the new file's position
//   double xmin=0, xmax=0, ymin=0, ymax=0 ;
//   wdCanvasGetWindow( _dbuffer, &xmin, &xmax, &ymin, &ymax) ;
//   img->position( Point2d( (xmin+xmax)/2, (ymin+ymax)/2 ) ) ;
//    
//   // Seting the new background to the project
//   _project->editor().setBackground( img ) ;
//   _manipulator = img->manipulator() ;
//
//   ImageSaver *image_saver = new ImageSaver( img );
//   img->saver( image_saver );
//
//   return IUP_DEFAULT ;
//}
//
//int MainWindow::backGroundColorToggle_cb (Ihandle*togle, int v)
//{
//   if( !v ) 
//      return IUP_DEFAULT ;
//
//   Image*img = (Image* )_project->editor().getBackground() ;
//
//   if( !img )
//      return IUP_DEFAULT ;
//
//   int r, g, b ;
//   sscanf( IupGetAttribute( togle, "COLOR VALUE"), "%d %d %d", &r, &g, &b ) ; 
//   img->color( imEncodeColor( r, g, b ) );
//
//   if( r ==-1 && b==-1 &&g==-1 )
//      img->setColored();
//
//   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
//
//   return IUP_DEFAULT ;
//}

//int MainWindow::backGroundLightSlider_cb (Ihandle*slider, double value)
//{
//   Image*img = (Image* )_project->editor().getBackground() ;
//
//   if( !img )
//      return IUP_DEFAULT ;
//
//   img->setIntensity(value) ;
//   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
//
//   return IUP_DEFAULT ;
//}

//Ihandle * MainWindow::createBackgroundFrame()
//{
//   /** Button to chose an image **/
//   Ihandle *imgbg = IupImage(  24, 24, img_fundo_pix ) ;
//   IupSetAttribute( imgbg, "0", "0 0 0" ) ;
//   IupSetAttribute( imgbg, "1", "255 255 255" ) ;
//   Ihandle *button = IupButton( "", NULL ) ;
//   IupSetHandle( "background", imgbg ) ;
//   IupSetAttribute( button, IUP_IMAGE, "background" );
//   IupSetCallback( button, IUP_ACTION, (Icallback)backGroundImageButton_cb );
//
//   /** Slider to fade in/out **/
//   Ihandle *label = IupLabel("") ;
//   Ihandle *imglbl = IupImage(  16, 16, sun_pix ) ;
//   IupSetAttribute( imglbl, "0", "0 0 0" ) ;
//   IupSetAttribute( imglbl, "1", IUP_BGCOLOR ) ;
//   IupSetHandle( "SUNLBL", imglbl ) ;
//   IupSetAttribute( label, IUP_IMAGE, "SUNLBL" ) ;
//   Ihandle *slider = IupVal( IUP_HORIZONTAL ) ;
//   IupSetAttribute( slider, IUP_EXPAND, IUP_HORIZONTAL );
//  // IupSetAttribute( slider, IUP_RASTERSIZE, "50x" );
//   IupSetCallback( slider, "MOUSEMOVE_CB", (Icallback)backGroundLightSlider_cb );
//
//   //IupSetAttribute( slider, "HANDLER_IMAGE", "SUNLBL" ) ;
//
//   /** Toggles to give pseudo-colors to the image **/
//   Ihandle *h_box = IupHbox( NULL ) ;
//   for( int i=0 ; i<8 ; i++ )
//   {
//      Ihandle *imageu  = IupImage ( 10, 16, color_image ) ;
//      Ihandle *imagep  = IupImage ( 10, 16, color_image_press ) ;
//      for( int c=0 ; c<16 ; c++ )
//      {
//         IupSetAttribute( imageu, index_str[c], bt_color_values[i][c] ) ;
//         IupSetAttribute( imagep, index_str[c], bt_color_values[i][c] ) ;
//      }
//      IupSetAttribute( imagep, "0", "0 0 0 " ) ;
//      Ihandle *toggle = IupToggle( "", NULL ) ; 
//      IupSetHandle( color_names[i], imageu   ) ;
//      IupSetHandle( color_names_p[i], imagep ) ;
//      IupSetAttribute( toggle, IUP_IMAGE, color_names[i] );
//      IupSetAttribute( toggle, IUP_IMPRESS, color_names_p[i] );
//      IupSetAttribute( toggle, IUP_TIP, color_names[i] );
//      IupSetAttribute( toggle, "COLOR VALUE", color_values[i] ) ;
//      IupSetCallback( toggle, IUP_ACTION, (Icallback)backGroundColorToggle_cb );
//      IupAppend( h_box, toggle ) ; 
//   }   
//   Ihandle* radio = IupRadio( h_box ) ;
//
//   /** Composing the frame **/
//   Ihandle * hboxtop = IupHbox( button, slider,label, NULL ) ;
//   IupSetAttribute( hboxtop, IUP_ALIGNMENT, IUP_ACENTER ) ;
//   IupSetAttribute( hboxtop, IUP_EXPAND, IUP_YES ) ;
//   Ihandle *vbox = IupVbox( hboxtop, radio, NULL ) ;
//   IupSetAttribute( vbox, IUP_EXPAND, IUP_NO ); 
//   Ihandle *frame = IupFrame( vbox ) ;
//   return frame ;
//}