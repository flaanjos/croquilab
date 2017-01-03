#include "main_window_class.h"
#include "stdlib.h"
#include "cddbuf.h"
#include "iup.h"
#include "iupcontrols.h"
#include "cdirgb.h"

#include "scroll_color_bar.h"
#include "projectLoader.h"
#include "image.h"

static unsigned char seta_pix[] =
{
 1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1
,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};










Ihandle *MainWindow::_iupcanvas = NULL ;
cdCanvas *MainWindow::_cdcanvas = NULL ;
Project *MainWindow::_project = 0 ;
Ihandle *MainWindow::_dialog = NULL ;
Builder *MainWindow::_builder = 0 ;
Object *MainWindow::_creation_obj = 0 ;
std::vector<Object*> MainWindow::_selected_obj ;
std::vector<Object*> MainWindow::_clipboard_obj ;

cdCanvas *MainWindow::_dbuffer = NULL ;
cdCanvas *MainWindow::_select_canvas = NULL ;
cdCanvas *MainWindow::_tempcdcanvas = NULL ;
cdImage *MainWindow::_img_canvas = NULL ;
Manipulator *MainWindow::_manipulator = 0 ;
unsigned char *MainWindow::_red = 0 ;
unsigned char *MainWindow::_green = 0 ;
unsigned char *MainWindow::_blue = 0 ;
ImgDropDownList* MainWindow::_list_line_type = NULL ;
ImgDropDownList* MainWindow::_list_line_size = NULL ;
Ihandle* MainWindow::_colorIntensitySlider = 0;
Ihandle* MainWindow::_colorIntensityFrame = 0;
//CommandStack MainWindow::_command_stack;

char *MainWindow::_cursor = IUP_ARROW ;
double MainWindow::_zoom =1.0f;

static int teste( long color )
{
   IupMessage( "titulo", "oi" );
   return 1;
}

static int saveTeste( Ihandle* ih, int c )
{
   printf( "fsdaaaaaaaagfgtrereretr" );
   return IUP_DEFAULT;
}

Ihandle* vSeparator()
{
   Ihandle* label = IupLabel ( NULL );
   IupSetAttribute( label, IUP_SEPARATOR, IUP_VERTICAL ) ;
   return label;
}

Ihandle* hSeparator()
{
   Ihandle* label = IupLabel ( NULL );
   IupSetAttribute( label, IUP_SEPARATOR, IUP_HORIZONTAL ) ;
   return label;
}


MainWindow::MainWindow ( const std::string& fileName )
{  
   // Projeto
   _project = new Project() ;

   // Memória
   _red = new unsigned char[600*601];
   _green = new unsigned char[600*601];
   _blue = new unsigned char[600*601];

   // Menu do topo
   Ihandle*menu = createMenu() ;

   // Seta
   Ihandle* image = IupImage ( 22, 22, seta_pix ) ;
   IupSetHandle( "SETA_SELECT", image ) ;
   IupSetAttribute( image, "0", "0 0 0" ) ;
   IupSetAttribute( image, "1", IUP_BGCOLOR );
   Ihandle *select_bt = IupToggle( "", NULL ) ; 
   IupSetAttribute( select_bt, IUP_IMAGE, "SETA_SELECT" );
   IupSetAttribute( select_bt, "FLAT", IUP_YES );
   IupSetCallback( select_bt, IUP_ACTION, (Icallback)arrowButton_cb) ;
   
   // Outro elementos de interface
   Ihandle* adtional_color_panel = createAdtionalColorOptionsFrame() ;
   Ihandle* obj_buttons_panel = createObjButtons() ;
   _iupcanvas = createCanvas() ;
   
   Ihandle *zooms = createZoomButtons() ;

   createLineSizeMenu();
   Ihandle *line_size_menu = (Ihandle*)(*_list_line_size) ;

   createLineTypeMenu();
   Ihandle *line_type_menu = (Ihandle*)(*_list_line_type) ;

   Ihandle *order_menu = createOrderMenu() ;
   
   ScrollColorBar* scrollcolorbar = new ScrollColorBar( scrollColorBarChange_cb );


   // Composição
   Ihandle *hb_options_zoom = IupHbox( vSeparator(),
                                       zooms, vSeparator(),
                                       order_menu, vSeparator(),
                                       line_size_menu, vSeparator(),
                                       line_type_menu, vSeparator(),
                                       adtional_color_panel, vSeparator(), IupFill(), NULL );

   IupSetAttributes( hb_options_zoom, "MARGIN=5x5, GAP=5" ) ;
   IupSetAttribute( hb_options_zoom, IUP_EXPAND, IUP_NO ) ;

   Ihandle* left_panel_radio = IupVbox( hSeparator(),select_bt, obj_buttons_panel, NULL );
   IupSetAttributes( left_panel_radio, "MARGIN=5x5, GAP=5" ) ;
   IupSetAttribute( left_panel_radio, IUP_EXPAND, IUP_NO );


   Ihandle* central_h_box = IupHbox( IupRadio(left_panel_radio), _iupcanvas, NULL );



   Ihandle* final_vbox = IupVbox( hb_options_zoom, central_h_box, (Ihandle*)(*scrollcolorbar), NULL);



   // Dialogo
   _dialog = IupDialog(final_vbox);
   
   IupSetAttribute( _dialog, "BGCOLOR", "192 192 192");
   IupSetAttributes( _dialog, "TITLE=\"CroquiLab Versão 0.2.1 (Beta 2)\", RESIZE=YES, MAXBOX=YES");
   IupSetAttribute( _dialog, IUP_ICON, "CROQUILAB_ICON");
   IupSetHandle("menu", menu ) ;
   IupSetAttribute ( _dialog, IUP_MENU, "menu" ) ;
   IupSetCallback ( _dialog, "CLOSE_CB", (Icallback)closeTopo ) ;
   IupMap( _dialog ) ;
   cdInitContextPlus();

   int x = cdUseContextPlus(1); 
   _cdcanvas = cdCreateCanvas(CD_IUP, _iupcanvas);
   cdUseContextPlus(1); 
   _dbuffer = cdCreateCanvas(CD_DBUFFER, _cdcanvas);
   cdCanvasClear(_cdcanvas) ; 

   cdUseContextPlus(0); 
   _tempcdcanvas = cdCreateCanvas(CD_IUP, _iupcanvas);
   _img_canvas =  cdCanvasCreateImage(_tempcdcanvas , 600, 600 ); 
   _select_canvas = cdCreateCanvas( CD_IMAGE , _img_canvas ) ;
   cdCanvasClear(_select_canvas) ; 

   _zoom = 1.0f ;
   NoZoomButton_cb( 0 );
   _builder = 0 ;

   _creation_obj = 0 ;
   _selected_obj.clear() ;
   _clipboard_obj.clear() ;
   _manipulator = 0 ;

   IupMap( _dialog ) ;

   if( fileName.size() > 0 )
   {
      clearProject();
     loadProject( _project->editor(), fileName ) ;    
      _project->fileName( fileName );
      _project->centerTopo();
   }  

   IupSetCallback( _dialog, "K_cS", (Icallback)saveTopo ) ;
   IupSetCallback( _dialog, "K_cO", (Icallback)openTopo ) ;
   IupSetCallback( _dialog, "K_cN", (Icallback)newTopo ) ;

   IupShowXY(_dialog,IUP_CENTER,IUP_CENTER);
    repaintMainCanvas_cb( _iupcanvas, 0, 0 );

}



////MainWindow::MainWindow ( const std::string& fileName )
////{  
////   // Projeto
////   _project = new Project() ;
////
////   // Memória
////   _red = new unsigned char[600*601];
////   _green = new unsigned char[600*601];
////   _blue = new unsigned char[600*601];
////
////   // Menu do topo
////   Ihandle*menu = createMenu() ;
////
////   // Seta
////   Ihandle* image = IupImage ( 22, 22, seta_pix ) ;
////   IupSetHandle( "SETA_SELECT", image ) ;
////   IupSetAttribute( image, "0", "0 0 0" ) ;
////   IupSetAttribute( image, "1", IUP_BGCOLOR );
////   Ihandle *select_bt = IupToggle( "", NULL ) ; 
////   IupSetAttribute( select_bt, IUP_IMAGE, "SETA_SELECT" );
////   IupSetAttribute( select_bt, "FLAT", IUP_YES );
////   
////   // Outro elementos de interface
////   Ihandle* adtional_color_panel = createAdtionalColorOptionsFrame() ;
////   Ihandle* obj_buttons_panel = createObjButtons() ;
////   _iupcanvas = createCanvas() ;
////   
////   Ihandle *zooms = createZoomButtons() ;
////
////   createLineSizeMenu();
////   Ihandle *line_size_menu = (Ihandle*)(*_list_line_size) ;
////
////   createLineTypeMenu();
////   Ihandle *line_type_menu = (Ihandle*)(*_list_line_type) ;
////
////   Ihandle *order_menu = createOrderMenu() ;
////   
////
////   // Composição
////
////      Ihandle *hb_sel_zoom = IupHbox( select_bt, zooms, NULL );
////   IupSetAttributes( hb_sel_zoom, "MARGIN=0x5, GAP=5" ) ;
////   IupSetCallback( select_bt, IUP_ACTION, (Icallback)arrowButton_cb) ;
////
////
////   Ihandle *separator_lbl = IupLabel("");
////   IupSetAttribute( separator_lbl, IUP_SEPARATOR, IUP_HORIZONTAL ) ;
////
////   Ihandle*fill = IupFill() ;
////   IupSetAttribute( fill, IUP_SIZE, "5" ) ;
////
////   Ihandle* full_color_panel = IupVbox( IupFrame( IupVbox( adtional_color_panel,NULL )), NULL);
////   IupSetAttributes( full_color_panel, "MARGIN=3x3");
////
////   Ihandle *separator_lbl2 = IupLabel("");
////   IupSetAttribute( separator_lbl2, IUP_SEPARATOR, IUP_VERTICAL ) ;
////   Ihandle* size_type_panel = IupHbox( IupFill(), line_size_menu, separator_lbl2, line_type_menu, IupFill(), NULL );
////   IupSetAttribute( size_type_panel, IUP_EXPAND, IUP_HORIZONTAL ) ;
////
////      Ihandle *separator_lbl3 = IupLabel("");
////      IupSetAttribute( separator_lbl3, IUP_SEPARATOR, IUP_HORIZONTAL ) ;
////
////      Ihandle* left_panel_radio = IupVbox( hb_sel_zoom, obj_buttons_panel );
////
////   Ihandle* left_panel_box = IupVbox(IupRadio( left_panel_radio), separator_lbl, IupFill(),size_type_panel,separator_lbl3,  order_menu, full_color_panel, NULL ) ;
////   IupSetAttribute( left_panel_box, IUP_EXPAND, IUP_NO );
////
////   Ihandle* hobx = IupHbox( left_panel_box, _iupcanvas, NULL ) ;
////
////   ScrollColorBar* scrollcolorbar = new ScrollColorBar( scrollColorBarChange_cb );
////   Ihandle* final_vbox = IupVbox( hobx, (Ihandle*)(*scrollcolorbar), NULL);
////
////
////
////   // Dialogo
////   _dialog = IupDialog(final_vbox);
////   
////   IupSetAttribute( _dialog, "BGCOLOR", "192 192 192");
////   IupSetAttributes( _dialog, "TITLE=\"CroquiLab Beta 1\", RESIZE=YES, MAXBOX=YES");
////   IupSetAttribute( _dialog, IUP_ICON, "CROQUILAB_ICON");
////   IupSetHandle("menu", menu ) ;
////   IupSetAttribute ( _dialog, IUP_MENU, "menu" ) ;
////   IupSetCallback ( _dialog, "CLOSE_CB", (Icallback)closeTopo ) ;
////   IupMap( _dialog ) ;
////   cdInitContextPlus();
////
////   int x = cdUseContextPlus(1); 
////   _cdcanvas = cdCreateCanvas(CD_IUP, _iupcanvas);
////   cdUseContextPlus(1); 
////   _dbuffer = cdCreateCanvas(CD_DBUFFER, _cdcanvas);
////   cdCanvasClear(_cdcanvas) ; 
////
////   cdUseContextPlus(0); 
////   _tempcdcanvas = cdCreateCanvas(CD_IUP, _iupcanvas);
////   _img_canvas =  cdCanvasCreateImage(_tempcdcanvas , 600, 600 ); 
////   _select_canvas = cdCreateCanvas( CD_IMAGE , _img_canvas ) ;
////   cdCanvasClear(_select_canvas) ; 
////
////   _zoom = 1.0f ;
////   NoZoomButton_cb( 0 );
////   _builder = 0 ;
////
////   _creation_obj = 0 ;
////   _selected_obj.clear() ;
////   _clipboard_obj.clear() ;
////   _manipulator = 0 ;
////
////   IupMap( _dialog ) ;
////
////   if( fileName.size() > 0 )
////   {
////      clearProject();
////     loadProject( _project->editor(), fileName ) ;    
////      _project->fileName( fileName );
////   }  
////
////   IupSetCallback( _dialog, "K_cS", (Icallback)saveTopo ) ;
////   IupSetCallback( _dialog, "K_cO", (Icallback)openTopo ) ;
////   IupSetCallback( _dialog, "K_cN", (Icallback)newTopo ) ;
////
////   IupShowXY(_dialog,IUP_CENTER,IUP_CENTER);
////    repaintMainCanvas_cb( _iupcanvas, 0, 0 );
////
////}





MainWindow::~MainWindow() 
{
}


void MainWindow::syncMenus() 
{
   if( _selected_obj.size() > 0 )
   {
      _list_line_size->selectedItem( _selected_obj[0]->lineSize()-1 ) ;
      _list_line_type->selectedItem( _selected_obj[0]->lineType()-CD_CONTINUOUS ) ;

      if( _selected_obj.size() == 1 )
      {
         Image* image = dynamic_cast<Image*>( _selected_obj[0] ) ;
         if( image )
         {
            double i = image->intensity();
            IupSetAttribute( _colorIntensityFrame, IUP_ACTIVE, IUP_YES );          
            IupSetfAttribute( _colorIntensitySlider, IUP_VALUE, "%f", i );            
         }
         else
         {
           IupSetAttribute( _colorIntensityFrame, IUP_ACTIVE, IUP_NO );          
         }
      }

   }
   else if (_builder) 
   {
      _list_line_size->selectedItem( _project->lineType()-CD_CONTINUOUS  ) ;
      _list_line_type->selectedItem( _project->lineType()-CD_CONTINUOUS ) ;
      IupSetAttribute( _colorIntensityFrame, IUP_ACTIVE, IUP_NO );          
   }
}

void MainWindow::clearProject() 
{
   _manipulator = 0 ;
   _selected_obj.clear();
   //if( _builder )
   //{
   //   _builder->finish() ;
   //}
   _builder = 0;

   _project->editor().deleteObjects();
   CommandStack::clear();
}

