#include "main_window.h"

#include <stdio.h>
#include "iup.h"
#include "cd.h"
#include "cdiup.h"

#include "wd.h"
#include "math.h"
#include "button_images.h"
#include "line_styles_bt.h"
#include "iupcontrols.h"
#include "object.h"
#include "ARVOREPOINTS.h"
#include "tree.h"
#include "hole.h"
#include "block.h"
#include "project.h"
#include "crystal.h"
#include "round_bolt.h"
#include "sharp_bolt.h"
#include "cable.h"
#include "dihedral.h"
#include "oposition.h"
#include "chimney.h"
#include "crack.h"
#include "arete.h"
#include "fundo_bt16.h"
#include "bg_color_toggles.h"
#include "menu.h"
char sun_pix[16*16] = 
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


cdCanvas *_cdcanvas ;
static Project _project ;
// botoes devem ter
//button_function
//drag_function
//end_function
typedef Object *(*OBJ_BT_FUNC)( int button, int state, float wx, float wy );

Object *(*objectButtonFunction)( int button, int state, float wx, float wy );
Object *(*objectMotionFunction)( float wx, float wy );

Object *in_edition = NULL ;

void setObjectButtonFunction( OBJ_BT_FUNC function )
{
   objectButtonFunction = function ;
}
void setObjectMotionFunction( Object *(*function)( int button, int state, float wx, float wy ) )
{
   objectButtonFunction = function ;
}

Object *canvasMotionArete( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Arete *c = (Arete*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonArete( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Arete *c = new Arete( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Arete *c = (Arete*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}

Object *canvasMotionCrack( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Crack *c = (Crack*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonCrack( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Crack *c = new Crack( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Crack *c = (Crack*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}

Object *canvasMotionChimney( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Chimney *c = (Chimney*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonChimney( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Chimney *c = new Chimney( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Chimney *c = (Chimney*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}


Object *canvasMotionCable( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Cable *c = (Cable*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonCable( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Cable *c = new Cable( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Cable *c = (Cable*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasMotionOposition( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Oposition *c = (Oposition*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonOposition( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Oposition *c = new Oposition( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Oposition *c = (Oposition*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}

Object *canvasMotionDihedral( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Dihedral *c = (Dihedral*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonDihedral( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Dihedral *c = new Dihedral( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Dihedral *c = (Dihedral*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}

Object *canvasButtonRoundBolt( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   RoundBolt* rb = new RoundBolt() ;
   rb->position( p ) ;
   return rb ;
}
Object *canvasButtonSharpBolt( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   SharpBolt* tree = new SharpBolt() ;
   tree->position( p ) ;
   return tree ;
}

Object *canvasButtonTree( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Tree* tree = new Tree() ;
   tree->position( p ) ;
   return tree ;
}
Object *canvasButtonHole( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Hole* hole = new Hole() ;
   hole->position( p ) ;
   return hole ;
}
Object *canvasButtonBlock( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Block* block = new Block() ;
   block->position( p ) ;
   return block ;
}
Object *canvasButtonLine( int button, int state, float wx, float wy )
{
//   Line* line = new Line() ;
//   line->addPoint( 0, wx, wy ) ;
//   return Line ;
   return NULL ;
}
Object *canvasButtonCrystal( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Crystal* c = new Crystal() ;
   c->position( p ) ;
   return c ;
}



int buttonArete_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonArete ;
  objectMotionFunction = canvasMotionArete ;
  return IUP_DEFAULT; 
}
int buttonCrack_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonCrack ;
  objectMotionFunction = canvasMotionCrack ;
  return IUP_DEFAULT; 
}
int buttonChimney_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonChimney ;
  objectMotionFunction = canvasMotionChimney ;
  return IUP_DEFAULT; 
}
int buttonCable_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonCable ;
  objectMotionFunction = canvasMotionCable ;
  return IUP_DEFAULT; 
}
int buttonOposition_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonOposition ;
  objectMotionFunction = canvasMotionOposition ;
  return IUP_DEFAULT; 
}
int buttonDihedral_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonDihedral ;
  objectMotionFunction = canvasMotionDihedral ;
  return IUP_DEFAULT; 
}
int buttonCrystal_cb( Ihandle* self )
{
   // call current end function
   //define new buttonfunction
  objectButtonFunction = canvasButtonCrystal ;
  objectMotionFunction = NULL ;
  //define new drag function
  //define new end functio
  return IUP_DEFAULT; 
}
int buttonHole_cb( Ihandle* self )
{
   // call current end function
   //define new buttonfunction
  objectButtonFunction = canvasButtonHole ;
  objectMotionFunction = NULL ;
  //define new drag function
  //define new end functio
  return IUP_DEFAULT; 
}
int buttonBlock_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonBlock ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
int buttonTree_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonTree ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
int buttonRoundBolt_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonRoundBolt ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
int buttonSharpBolt_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonSharpBolt ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}

Icallback obj_button_calbacks[] =
{
   (Icallback)buttonRoundBolt_cb, (Icallback)buttonSharpBolt_cb, NULL, NULL,
   (Icallback)buttonCrystal_cb, (Icallback)buttonHole_cb, (Icallback)buttonBlock_cb,
   (Icallback)buttonCable_cb, (Icallback)buttonChimney_cb,  (Icallback)buttonDihedral_cb, (Icallback)buttonArete_cb,
   (Icallback)buttonCrack_cb, NULL, (Icallback)buttonOposition_cb, NULL,
   (Icallback)buttonTree_cb, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL
} ;

int repaint_main_canvas_cb(Ihandle* self, float sx, float sy)
{
   if (_cdcanvas )
   {
   cdActivate( _cdcanvas ) ;
        cdLineWidth( 1 ); 
     cdForeground( CD_BLACK ) ;
      wdWindow( 0, 600, 0, 600); 
   cdClear() ;

   _project._editor.draw() ;
      if( in_edition )
         in_edition->draw() ;

   }

//   desenha_arvore() ;
   return IUP_DEFAULT ; 
}

int button_main_canvas_cb(Ihandle* self, int button, int state, int x, int y)
{
   if( state )
   {
      if( objectButtonFunction )
      {
         Object * o = objectButtonFunction( button, state, (float)x, 600-(float)y ) ;
         if( o )
         {
            _project._editor.addObject( o ) ;
         }
      }
      repaint_main_canvas_cb( self, 0, 0) ;
  }
  return IUP_DEFAULT;	
}

int motion_main_canvas_cb(Ihandle* self, int x, int y)
{
   if( in_edition && objectMotionFunction )
   {
      in_edition = objectMotionFunction( (float)x, 600-(float)y ) ;
      repaint_main_canvas_cb( self, 0, 0) ;
   }      
  return IUP_DEFAULT;
}



int scroll_main_canvas_cb(Ihandle* self)
{
  return IUP_DEFAULT;	
}

int enter_main_canvas_cb(Ihandle* self)
{
  return IUP_DEFAULT;
}

int leave_main_canvas_cb(Ihandle* self)
{
  return IUP_DEFAULT;
}




static char * corestabela[] =
{
   "192 192 192", "255 255 255", "255 160 160", "160 255 160", "160 160 255","192 255 255", "255 192 255", "255 255 192",  
   "128 128 128",  "160 160 160",   "255 0 0",     "0 255 0",     "0 0 255",    "0 255 255",   "255 0 255",   "255 255 0",
   "64 64 64", "96 96 96",  "128 0 0",      "0 128 0",     "0 0 128",    "0 128 128",   "128 0 128",   "128 128 0",
   "0 0 0", "32 32 32",        "64 0 0",      "0 64 0",      "0 0 64",     "0 64 64",     "64 0 64",     "64 64 0" 
};

Ihandle * createBackgroundFrame()
{
   Ihandle *label = IupLabel("") ;
   Ihandle *imglbl = IupImage(  16, 16, sun_pix ) ;
   IupSetAttribute( imglbl, "0", "0 0 0" ) ;
   IupSetAttribute( imglbl, "1", IUP_BGCOLOR ) ;
   IupSetHandle( "SUNLBL", imglbl ) ;
   IupSetAttribute( label, IUP_IMAGE, "SUNLBL" ) ;


   Ihandle *imgbg = IupImage(  24, 24, img_fundo_pix ) ;
   IupSetAttribute( imgbg, "0", "0 0 0" ) ;
   IupSetAttribute( imgbg, "1", IUP_BGCOLOR ) ;
   Ihandle *button = IupButton( "", NULL ) ;
   IupSetHandle( "background", imgbg ) ;

   Ihandle *val = IupVal( IUP_HORIZONTAL ) ;
IupSetAttribute( val, IUP_EXPAND, IUP_HORIZONTAL );
IupSetAttribute( val, IUP_RASTERSIZE, "50x" );
   IupSetAttribute( button, IUP_IMAGE, "background" );

   Ihandle *h_box = IupHbox( NULL ) ;
   for( int i=0 ; i<8 ; i++ )
   {
      Ihandle *imageu  = IupImage ( 10, 16, color_image ) ;
      Ihandle *imagep  = IupImage ( 10, 16, color_image_press ) ;
      for( int c=0 ; c<16 ; c++ )
      {
         IupSetAttribute( imageu, index_str[c], color_values[i][c] ) ;
         IupSetAttribute( imagep, index_str[c], color_values[i][c] ) ;
      }
      IupSetAttribute( imagep, "0", "0 0 0 " ) ;
      Ihandle *toggle = IupToggle( "", NULL ) ; 
      IupSetHandle( color_names[i], imageu ) ;
      IupSetHandle( color_names_p[i], imagep ) ;
      IupSetAttribute( toggle, IUP_IMAGE, color_names[i] );
      IupSetAttribute( toggle, IUP_IMPRESS, color_names_p[i] );
      IupSetAttribute( toggle, IUP_TIP, color_names[i] );
      IupAppend( h_box, toggle ) ; 
/*      if( color_button_calbacks[i] )
      {
         IupSetCallback( button, IUP_ACTION, obj_button_calbacks[b] ) ;
      }
      else
      {
         IupSetAttribute( button, IUP_ACTIVE, IUP_NO );
      }   */
   }   
   Ihandle* radio = IupRadio( h_box ) ;

   Ihandle * hboxtop = IupHbox( button, val,label, NULL ) ;
  IupSetAttribute( hboxtop, IUP_ALIGNMENT, IUP_ACENTER ) ;
   Ihandle *vbox = IupVbox( hboxtop, radio, NULL ) ;
   Ihandle *frame = IupFrame( vbox ) ;
   return frame ;
}

Ihandle * createObjButtons()
{
   Ihandle *v_box = IupVbox( NULL ) ;

   int b=0;
   for( int i=0 ; i<7 ; i++ )
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
            IupSetAttribute( image, "15", IUP_BGCOLOR ) ;
            IupAppend( h_box, button ) ; 
            if( obj_button_calbacks[b] )
            {
               IupSetCallback( button, IUP_ACTION, obj_button_calbacks[b] ) ;
            }
            else
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

Ihandle * createEditButtons() 
{
   return NULL ;
}
Ihandle* createCanvas ()
{
   Ihandle* iupcanvas = IupCanvas(NULL);

   IupSetAttributes(iupcanvas, "CURSOR=CROSS, RASTERSIZE=600x600, EXPAND=NO, SCROLLBAR=NO, DX=0.5, DY=0.5");

   IupSetCallback(iupcanvas, "ACTION",(Icallback)repaint_main_canvas_cb);
   IupSetCallback(iupcanvas, "BUTTON_CB",(Icallback)button_main_canvas_cb);
   IupSetCallback(iupcanvas, "SCROLL_CB",(Icallback)scroll_main_canvas_cb);
   IupSetCallback(iupcanvas, "MOTION_CB",(Icallback)motion_main_canvas_cb);
   IupSetCallback(iupcanvas, "ENTERWINDOW_CB",(Icallback)enter_main_canvas_cb);
   IupSetCallback(iupcanvas, "LEAVEWINDOW_CB",(Icallback)leave_main_canvas_cb);
   

   return iupcanvas ;
}

Ihandle* createColorPanel()
{
   Ihandle* colors = IupColorbar( ) ; 
 // IupSetCallback(cores, "SELECT_CB", (Icallback)select_cb);
  //IupSetCallback(cores, "CELL_CB", (Icallback)cell_cb);
  //IupSetCallback(cores, "SWITCH_CB", (Icallback)switch_cb);


   IupSetAttribute(colors, "NUM_CELLS", "32" );
   IupSetAttribute(colors, "NUM_PARTS", "4" );
   IupSetAttribute(colors, "RASTERSIZE", "100x200");
   IupSetAttribute(colors, "EXPAND", "HORIZONTAL");
   IupSetAttribute(colors, "ORIENTATION", "HORIZONTAL");
   for( int i=0 ; i<32 ; i++ )
   {
      char atrib[64];
      sprintf( atrib, "CELL%d", i );
      IupSetAttribute(colors, atrib,corestabela[i]);
  }
   return colors ;
} 



MainWindow::MainWindow ()
{
   Ihandle* dlg ;	

   Ihandle*background_panel = createBackgroundFrame() ;
   Ihandle*obj_buttons_panel = createObjButtons() ;
   Ihandle*edit_buttons_panel = createEditButtons() ;
   Ihandle*canvas_panel = createCanvas () ;
   Ihandle*colorPanel = createColorPanel() ; 
   Ihandle*menu = Menu::createMenu() ;

   Ihandle*fill = IupFill() ;
   IupSetAttribute( fill, IUP_SIZE, "5" ) ;

   Ihandle* hobx = IupHbox( IupVbox( background_panel,fill, obj_buttons_panel, /*edit_buttons_panel,*/ colorPanel, NULL ),
                            canvas_panel,
                             NULL ) ;


   dlg = IupDialog(hobx);

   IupSetAttributes( dlg, "TITLE=Editor de Croqui, RESIZE=NO, MAXBOX=NO");
   IupSetHandle("menu", menu ) ;
   IupSetAttribute ( dlg, IUP_MENU, "menu" ) ;


   IupShowXY(dlg,IUP_CENTER,IUP_CENTER);
_cdcanvas = cdCreateCanvas(CD_IUP, canvas_panel);
   if(cdActivate(_cdcanvas) == CD_ERROR)
   {
      IupMessage("IupCanvas","Error creating canvas");
      IupDestroy(dlg);
      IupClose();
   }


  cria_arvore() ;
  desenha_arvore();

}

MainWindow::~MainWindow() 
{
   //_project._editor._objects.
}


