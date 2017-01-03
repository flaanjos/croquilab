#include "main_window_class.h"
#include "location_window.h"
#include <stdlib.h>
#include "string.h"
#include "iup.h"
#include "iupcontrols.h"
#include "iupcontrols.h"
#include "page.h"
#include "cd.h"
#include "cdirgb.h"
#include "wd.h"
#include "cdpdf.h"
#include "im.h"
#include "im_image.h"
#include "im_file.h"
#include <fstream>
#include "projectLoader.h"
#include "FileDialog.h"
#include "cdprint.h"
#include "list_manipulator.h"

int about_cb( Ihandle* item );

int MainWindow::newTopo(Ihandle *self)
{
   if( _project->editor().numObjects() > 0 )
   {
      int i = IupAlarm( "Fechar Croqui", "Salvar antes de iniciar novo?", "Sim", "Não", "Cancelar" );
      if( i == 1 )
      {
         int saving_status = saveTopo( self );
         if(  saving_status == IUP_IGNORE )
            return IUP_IGNORE;
      }
      else if( i == 3 )
         return IUP_IGNORE;
   }

   clearProject();   
   repaintMainCanvas_cb( _iupcanvas, 0, 0 );
   _project->fileName( "" );
   return IUP_DEFAULT;
}

int MainWindow::openTopo(Ihandle *self)
{
   std::string file_name;

   FileDialog f_dialog;
   int file_selected = f_dialog.promptForOpening( "Abrir croqui", "", "*.crq", "arquivo de croqui" );

   if( file_selected == -1 )
      return IUP_DEFAULT;

   file_name = f_dialog.getFileName();

   if( _project->editor().numObjects() > 0 )
   {
      int i = IupAlarm( "Fechar Croqui", "Salvar antes de abrir outro?", "Sim", "Não", "Cancelar" );
      if( i == 1 )
      {
         int saving_status = saveTopo( self );
         if(  saving_status == IUP_IGNORE )
            return IUP_IGNORE;
      }
      else if( i == 3 )
         return IUP_IGNORE;
   }

   clearProject();
   loadProject( _project->editor(), file_name ) ;
   repaintMainCanvas_cb( _iupcanvas, 0, 0 );
   _project->fileName( file_name );

   return IUP_DEFAULT;
}

int MainWindow::closeTopo(Ihandle *self)
{
   if( _project->editor().numObjects() > 0 )
   {
      int i = IupAlarm( "Fechar Croqui", "Salvar antes de fechar?", "Sim", "Não", "Cancelar" );
      if( i == 1 )
      {
         int saving_status = saveTopo( self );
         if(  saving_status == IUP_IGNORE )
            return IUP_IGNORE;
      }
      else if( i == 3 )
         return IUP_IGNORE;
   }

   clearProject();
   repaintMainCanvas_cb( _iupcanvas, 0, 0 );
   return IUP_CLOSE;
}

static int new_topo_cb(Ihandle* self)
{
   clearLocationDialog() ;
   showLocationDialog() ;

   return IUP_DEFAULT ; 
}



static int current_topo_cb(Ihandle* self)
{
   // if current => save current option
   showLocationDialog() ;
   return IUP_DEFAULT ; 
}

int MainWindow::export_topo_image_cb(Ihandle* self)
{
   Point2d pmin(0,0), pmax(0,0) ;
   _project->editor().boundingBox( pmin, pmax) ;

   int paper_size = 1 ;
   int width = 1.5*(pmax._x-pmin._x)+0.505;//800 ;
   int height = 1.5*(pmax._y-pmin._y)+0.505;//1200 ;
   int image_h_alignment =0 ;
   int image_v_alignment =0 ;
   int image_resolution =96 ;
   char file_name[2048] = "croqui.png" ;

   if (!IupGetParam("Expotar como imagem .png", NULL, 0,
      "Imagem %t\n"
      "Largura %i\n"
      "Altura %i\n"
      "Alinhamento horizontal %l|centro|esquerda|direita|\n"
      "Alinhamento vertical %l|centro|topo|base|\n"
      "Resolução (DPI) %i[2,,10]\n"
      "Arquivo %t\n"
      "Nome %f[SAVE|*.png|CURRENT|NO|NO]\n",
      &width,
      &height,
      &image_h_alignment,
      &image_v_alignment,
      &image_resolution,
      file_name, NULL ) )
      return IUP_DEFAULT ;

   Page::H_Alignment halignmes[] = { Page::HCENTER, Page::HLEFT, Page::HRIGHT } ;
   Page::V_Alignment valignmes[] = { Page::VCENTER, Page::VTOP, Page::VBOTTOM } ;

   Page p ;
   p.setDimenisions( (float)width, (float)height ) ; ;
   p.paper_left_margin = 0 ;
   p.paper_right_margin = 0 ;
   p.paper_top_margin = 0 ;
   p.paper_bottom_margin = 0 ;
   p.image_h_alignment = halignmes[image_h_alignment];
   p.image_v_alignment = valignmes[image_v_alignment];
   p.image_resolution = image_resolution ;

   double img_w, img_h ;
   int xmin, xmax, ymin, ymax  ;
   img_w = pmax._x-pmin._x+1;
   img_h = pmax._y-pmin._y+1;
   p.fitImageInCm( img_w, img_h, xmin, xmax, ymin, ymax ) ;

   char data[1024+2048] ;
   unsigned char *buffer = new unsigned char[5*(width*height)] ;

   sprintf( data, "%dx%d %p %p %p -r%g", width, height, buffer, buffer+(width*height), buffer+2*(width*height), p.image_resolution ) ;
   cdCanvas *canvas = cdCreateCanvas( CD_IMAGERGB, data ) ;
   cdActivate( canvas ) ;
   cdBackground( CD_WHITE );
   cdClear( );
   wdViewport( xmin, xmax, ymin, ymax ) ;
   wdWindow( pmin._x, pmax._x, pmin._y, pmax._y ) ;
   _project->editor().draw() ;

   imImage *image = imImageInit(width, height, IM_RGB, IM_BYTE, buffer, NULL, 0) ;
   imFileImageSave(file_name, "PNG", image);

   cdKillCanvas(canvas); 
   delete[] buffer;
   image->data[0] = NULL ;
   imImageDestroy(image);

   return IUP_DEFAULT;


   //   sprintf( data, "%dx%d", width, height );
   //   Ihandle* temp_iup_canvas = IupCanvas( NULL );
   //   IupSetAttribute( temp_iup_canvas, "DRAWSIZE", data ); 
   ////   IupMap( temp_iup_canvas );
   //   cdCanvas* native_canvas = cdCreateCanvas( CD_IUP, temp_iup_canvas );
   //   cdCanvasActivate( native_canvas );
   //   cdUseContextPlus( 1 ); 
   //   cdImage* server_image = cdCanvasCreateImage( native_canvas, width, height );
   //   cdCanvas* server_image_canvas = cdCreateCanvas( CD_IMAGE, server_image );   
   //   cdCanvasActivate( native_canvas );
   //   cdUseContextPlus( 1 );
   //
   //   cdBackground( CD_WHITE );
   //   cdClear( );
   //   wdViewport( xmin, xmax, ymin, ymax ) ;
   //   wdWindow( pmin._x, pmax._x, pmin._y, pmax._y ) ;
   //   _project->editor().draw() ;
   //
   //   cdCanvasGetImageRGB( server_image_canvas, buffer, buffer+(width*height), buffer+2*(width*height), 0, 0, width, height ) ;
   //   imImage *image = imImageInit(width, height, IM_RGB, IM_BYTE, buffer, NULL, 0) ;
   //   imFileImageSave(file_name, "PNG", image);
   //
   //   cdKillCanvas( server_image_canvas ); 
   //   cdKillImage( server_image ); 
   //   cdKillCanvas( native_canvas );
   //   IupDestroy( temp_iup_canvas );
   //
   //   image->data[0] = NULL ;
   //   imImageDestroy(image);
   //
   //   delete[] buffer;
}


int MainWindow::export_topo_pdf_cb(Ihandle* self)
{
   int paper_size = 1 ;
   int paper_orientation = 0;
   float paper_left_margin = 2;
   float paper_right_margin =2;
   float paper_top_margin =2;
   float paper_bottom_margin = 2;
   int image_h_alignment =0;
   int image_v_alignment =0;
   int image_resolution =300;
   char file_name[2048] = "croqui.pdf";

   if (!IupGetParam("Expotar para PDF", NULL, 0,
      "Papel %t\n"
      "Tamanho %l|A5|A4|A3|A2|A1|A0|Carta|Ofício|\n"
      "Orientacão %l|retrato|paisagem|\n"
      "Margem esquerda (cm) %r\n"
      "Margem direita (cm) %r\n"
      "Margem superior (cm) %r\n"
      "Margem inferior (cm) %r\n"
      "Imagem %t\n"
      "Alinhamento horizontal %l|centro|esquerda|direita|\n"
      "Alinhamento vertical %l|centro|topo|base|\n"
      "Resolução (DPI) %i[2,,10]\n"
      "Arquivo %t\n"
      "Nome %f[SAVE|*.pdf|CURRENT|NO|NO]\n",
      &paper_size,
      &paper_orientation,
      &paper_left_margin,
      &paper_right_margin,
      &paper_top_margin,
      &paper_bottom_margin,
      &image_h_alignment,
      &image_v_alignment,
      &image_resolution,
      file_name, NULL ) )
      return IUP_DEFAULT;

   Page::DefaultSizes sizes[] = { Page::A5, Page::A4, Page::A3, Page::A2, Page::A1, Page::A0, Page::LETTER, Page::LEGAL } ;
   bool orientations[] = { false, true } ;
   Page::H_Alignment halignmes[] = { Page::HCENTER, Page::HLEFT, Page::HRIGHT } ;
   Page::V_Alignment valignmes[] = { Page::VCENTER, Page::VTOP, Page::VBOTTOM } ;

   Page p ;
   p.setDimenisions( sizes[paper_size], orientations[paper_orientation] ) ; ;
   p.paper_left_margin = paper_left_margin ;
   p.paper_right_margin = paper_right_margin ;
   p.paper_top_margin = paper_top_margin ;
   p.paper_bottom_margin = paper_bottom_margin ;
   p.image_h_alignment = halignmes[image_h_alignment];
   p.image_v_alignment = valignmes[image_v_alignment];
   p.image_resolution = image_resolution ;

   double img_w, img_h ;
   int xmin, xmax, ymin, ymax  ;
   Point2d pmin(0,0), pmax(0,0) ;
   _project->editor().boundingBox( pmin, pmax) ;
   img_w = pmax._x-pmin._x+1;
   img_h = pmax._y-pmin._y+1;
   p.fitImageInDots( img_w, img_h, xmin, xmax, ymin, ymax ) ;

   char data[1024+2048] ;
   sprintf( data, "\"%s\" -w%d -h%d -s%d", file_name, (int)(10*p.paper_w), (int)(10*p.paper_h), p.image_resolution ) ;

   cdCanvas *canvas = cdCreateCanvas( CD_PDF, data) ;
   cdActivate( canvas ) ;
   wdViewport( xmin, xmax, ymin, ymax ) ;
   wdWindow( pmin._x, pmax._x, pmin._y, pmax._y ) ;
   _project->editor().draw() ;
   cdKillCanvas(canvas); 

   return IUP_DEFAULT; 
}



int MainWindow::printTopo( Ihandle* self )
{
   Point2d pmin(0,0), pmax(0,0) ;
   _project->editor().boundingBox( pmin, pmax) ;


   cdCanvas *canvas = cdCreateCanvas( CD_PRINTER, "croquiLab -d") ;
   cdActivate( canvas ) ;
   // wdViewport( xmin, xmax, ymin, ymax ) ;
   wdWindow( pmin._x, pmax._x, pmin._y, pmax._y ) ;
   _project->editor().draw() ;
   cdKillCanvas(canvas); 

   return IUP_DEFAULT; 
}





int MainWindow::saveTopoAs( Ihandle* self )
{
   std::string file_name = _project->fileName();
   if( file_name.size() == 0 )
   {
      file_name = "*.crq" ;
   }

   FileDialog f_dialog;
   f_dialog.setExtensionMandatory( true, ".crq" );
   int file_selected = f_dialog.promptForSaving( "Salvar croqui como...", ".crq", file_name.c_str(), "arquivo de croqui" );

   if( file_selected == -1 )
      return IUP_IGNORE ;

   file_name = f_dialog.getFileName();

   std::ofstream ofs( file_name.c_str() ) ;
   _project->editor().save( ofs ) ;
   ofs.close() ;

   _project->fileName( file_name );

   return IUP_DEFAULT ;
}


int MainWindow::saveTopo( Ihandle* self )
{
   std::string file_name = _project->fileName();
   if( file_name.size() == 0 )
   {
      return saveTopoAs( self );
   }

   std::ofstream ofs( file_name.c_str() ) ;
   _project->editor().save( ofs ) ;
   ofs.close() ;

   _project->fileName( file_name );

   return IUP_DEFAULT ;
}


Ihandle *MainWindow::createMenu()
{
   createLocationDialog() ;
   Ihandle* menu = 
      IupMenu(
      IupSubmenu( "Arquivo", IupMenu(
      IupItem( "Novo croqui\tCtrl+N", "new_topo_action" ) ,
      IupItem( "Abrir croqui\tCtrl+O", "load_topo_action" ) ,
      IupItem( "Salvar croqui\tCtrl+S", "save_topo_action" ) ,
      IupItem( "Salvar croqui como...", "save_topo_as_action" ) ,
      IupSeparator(),

      IupSubmenu( "Exportar como...",  IupMenu(
      IupItem( ".pdf", "export_topo_pdf_action" ),
      IupItem( ".png", "export_topo_image_action" ),NULL)),


      IupSeparator(),
      IupSetAttributes( IupItem( "Imprimir...\tCtrl+P", "MENU_PRINT_ACTION" ), "ACTIVE=YES" ),
      IupSeparator(),
      IupSetAttributes( IupItem( "Sair", "MENU_CLOSE_ACTION" ),"ACTIVE=YES" ),
      NULL )),

      IupSubmenu( "Editar",  IupMenu(
      IupSetAttributes( IupItem( "Desfazer\tCtrl+Z", "MENU_UNDO_ACTION" ),"ACTIVE=YES" ),
      IupSetAttributes( IupItem( "Repetir\tCtrl+Y", "MENU_REDO_ACTION" ),"ACTIVE=YES" ),
      IupSeparator( ),
      IupSetAttributes( IupItem( "Recortar\tCtrl+X", "MENU_CUT_ACTION" ),"ACTIVE=YES" ),
      IupSetAttributes( IupItem( "Copiar\tCtrl+C", "MENU_COPY_ACTION" ),"ACTIVE=YES" ),
      IupSetAttributes( IupItem( "Colar\tCtrl+V", "MENU_PASTE_ACTION" ),"ACTIVE=YES" ),
      IupSetAttributes( IupItem( "Apagar\tDel", "MENU_DEL_ACTION" ),"ACTIVE=YES" ),
      IupSeparator( ),
      IupSetAttributes( IupItem( "Selecionar Tudo\tCtrl+A", "MENU_SELECT_ALL" ),"ACTIVE=YES" ),
      NULL)),
      //      IupItem( "Croqui",  "current_topo_action" ),
      IupItem( "Sobre", "MENU_ABOUT_ACTION" ),
      NULL);



   IupSetFunction( "MENU_CUT_ACTION", (Icallback)editCommandsCut_cb ) ;
   IupSetFunction( "MENU_COPY_ACTION", (Icallback)editCommandsCopy_cb ) ;
   IupSetFunction( "MENU_PASTE_ACTION", (Icallback)editCommandsPaste_cb ) ;
   IupSetFunction( "MENU_DEL_ACTION", (Icallback)editCommandsDelete_cb ) ;

   IupSetFunction( "export_topo_pdf_action", (Icallback)export_topo_pdf_cb ) ;
   IupSetFunction( "export_topo_image_action", (Icallback)export_topo_image_cb ) ;
   IupSetFunction( "new_topo_action", (Icallback)newTopo ) ;
   IupSetFunction( "current_topo_action", (Icallback)current_topo_cb ) ; 
   IupSetFunction( "load_topo_action", (Icallback)openTopo ) ;
   IupSetFunction( "save_topo_action", (Icallback)saveTopo ) ;
   IupSetFunction( "save_topo_as_action", (Icallback)saveTopoAs ) ;
   IupSetFunction( "MENU_PRINT_ACTION", (Icallback)printTopo ) ;
   IupSetFunction( "MENU_CLOSE_ACTION", (Icallback)closeTopo ) ;

   IupSetFunction( "MENU_UNDO_ACTION", (Icallback)undo_cb ) ;
   IupSetFunction( "MENU_REDO_ACTION", (Icallback)redo_cb ) ;

   IupSetFunction( "MENU_SELECT_ALL", (Icallback)selectAll_cb ) ;
   IupSetFunction( "MENU_ABOUT_ACTION", (Icallback)about_cb ) ;
   return menu ;
}



int MainWindow::redo_cb( Ihandle *item )
{
   if( _builder )
   {
      _builder->cancel() ;
   }

   if( CommandStack::getRedoCommand() )
   { 
      _selected_obj = CommandStack::getRedoCommand()->getObjects();
      CommandStack::redoss();       

      _manipulator = 0;
      if( _selected_obj.size() > 0 )
      {
         if( _project->editor().selectId( _selected_obj[0]->id() ) )
         {

            if( _selected_obj.size() == 1 )
            {
               _manipulator = _selected_obj[0]->manipulator();
            }
            else
            {
               _manipulator = ListManipulator::instance( _selected_obj );
            }
         }
      }


      syncMenus() ;
      repaintMainCanvas_cb( _iupcanvas, 0, 0 );
   }


   return IUP_DEFAULT;
}


int MainWindow::undo_cb( Ihandle *item )
{
   if( _builder )
   {
      _builder->cancel() ;
   }

   if( CommandStack::getUndoCommand() )
   {
      _selected_obj = CommandStack::getUndoCommand()->getObjects(); 
      CommandStack::undoss();   

      _manipulator = 0;
      if( _selected_obj.size() > 0 )
      {
         if( _project->editor().selectId( _selected_obj[0]->id() ) )
         {
            if( _selected_obj.size() == 1 )
            {
               _manipulator = _selected_obj[0]->manipulator();
            }
            else
            {
               _manipulator = ListManipulator::instance( _selected_obj );
            }
         }
      }

      syncMenus() ;
      repaintMainCanvas_cb( _iupcanvas, 0, 0 );
   }


   return IUP_DEFAULT;
}



int MainWindow::selectAll_cb( Ihandle *item )
{
   _selected_obj.clear();

   int n = _project->editor().numObjects();

   for( int i=0 ; i<n ; i++)
   {
      _selected_obj.push_back( _project->editor().select(i) );
   }

   _manipulator = 0;
   if( _selected_obj.size() > 0 )
   {
      if( _selected_obj.size() == 1 )
      {
         _manipulator = _selected_obj[0]->manipulator();
      }
      else
      {
         _manipulator = ListManipulator::instance( _selected_obj );
      }
   }

   syncMenus() ;
   repaintMainCanvas_cb( _iupcanvas, 0, 0 );

   return IUP_DEFAULT;
}

int about_cb( Ihandle* item )
{
   char* msg = 
      "CroquiLab\n"
      "Versão 0.2.1 (Beta 2)\n\n"
      "2006-2013 Flavia do Anjos\n"
      "todos os direitos reservados\n";

   IupMessage( "Sobre o CroquiLab", msg );
   return IUP_DEFAULT;
}