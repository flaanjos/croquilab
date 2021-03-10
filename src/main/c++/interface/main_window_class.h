#ifndef _MAIN_WINDOW_CLASS_H__
#define _MAIN_WINDOW_CLASS_H__ 1

#include "iup.h"
#include "cd.h"
#include "cdiup.h"
#include "project.h"
#include "builder.h"
#include "cdimage.h"
#include "manipulator.h"
#include "img_drop_down_list.h"
#include "group.h"
#include <string>
#include "commands\command_stack.h"
void createLineSizeMenu() ;
void createLineTypeMenu() ;

class MainWindow
{
private:
public:
   MainWindow( const std::string& fileName ) ;
   ~MainWindow() ;

private:
   MainWindow( const MainWindow &mw ) ;
   const MainWindow &operator=( const MainWindow &mw ) ;

public:

   /** Calbacks **/
   static int saveTopo( Ihandle* self ) ;
   static int saveTopoAs( Ihandle* self ) ;
   static int newTopo( Ihandle* self ) ;
   static int openTopo( Ihandle* self ) ;
   static int closeTopo( Ihandle* self ) ;
   static int printTopo( Ihandle* self ) ;

   static void clearProject() ;

   static int objectButton_cb(Ihandle* button);
   static int arrowButton_cb(Ihandle*button) ;
   // static int backGroundImageButton_cb (Ihandle*button) ;
   static int backGroundColorToggle_cb (Ihandle*togle) ;
   static int lightSlider_cb (Ihandle*slider, double value) ;

   static int colorPaletteCell_cb( Ihandle* palette, int cell, int type) ;
   static int colorBrowserChange_cb( Ihandle *browser, unsigned char r, unsigned char g, unsigned char b); 
   static int scrollColorBarChange_cb( long color ); 

   static int repaintMainCanvas_cb(Ihandle* iupcanvas, float sx, float sy);
   static int buttonMainCanvas_cb(Ihandle* ih, int button, int pressed, int x, int y, char* status); 
   static int motionMainCanvas_cb(Ihandle* iupcanvas, int x, int y, char *status);
   static int scrollMainCanvas_cb(Ihandle *iupcanvas, int op, float posx, float posy); ;
   static int enterMainCanvas_cb(Ihandle* iupcanvas);
   static int leaveMainCanvas_cb(Ihandle* iupcanvas);
   static int resizeMainCanvas_cb(Ihandle *iupcanvas, int width, int height ) ;
   static int keypressMainCanvas_cb(Ihandle *iupcanvas, int c, int press);
   static int ZoomOutButton_cb( Ihandle* bt ); 
   static int ZoomInButton_cb( Ihandle* bt );
   static int NoZoomButton_cb( Ihandle* bt );
   static int listLineSize_cb( int i );
   static int listLineType_cb( int i );
   static int reorder_cb( Ihandle *button ) ;
   static int undo_cb( Ihandle *button ) ;
   static int redo_cb( Ihandle *button ) ;
   static int selectAll_cb( Ihandle *button ) ;

   static Ihandle *createMenu() ;
   static int export_topo_image_cb(Ihandle* self) ;
   static int export_topo_pdf_cb(Ihandle* self) ;

   static int editCommandsCopy_cb( Ihandle* ih );
   static int editCommandsPaste_cb( Ihandle* ih );
   static int editCommandsCut_cb( Ihandle* ih );
   static int editCommandsDelete_cb( Ihandle* ih );


   static void syncMenus( );

   static void createLineSizeMenu() ;
   static void createLineTypeMenu() ;
   static Ihandle* createZoomButtons() ;
   static Ihandle* createAdtionalColorOptionsFrame() ;
   static Ihandle* createObjButtons() ;
   static Ihandle* createCanvas() ;
   static Ihandle* createOrderMenu() ;

   static Ihandle *_iupcanvas ;
   static cdCanvas *_cdcanvas ;
   static Project *_project ;
   static Ihandle *_dialog ;
   static Builder *_builder ;
   static Object *_creation_obj ;
   static std::vector< Object * > _selected_obj ;
   static std::vector< Object * > _clipboard_obj ;

   static ImgDropDownList* _list_line_type ;
   static ImgDropDownList* _list_line_size ;
   static Ihandle *_colorIntensitySlider;
   static Ihandle* _colorIntensityFrame;

   static cdCanvas *_dbuffer ;
   static cdCanvas* _tempcdcanvas ; 
   static cdImage* _img_canvas ; 
   static cdCanvas* _select_canvas ; 
   static Manipulator *_manipulator ;


   static char *_cursor ;

   static unsigned char *_red ;
   static unsigned char *_green ;
   static unsigned char *_blue ;

   static double _zoom ;
} ;

#endif