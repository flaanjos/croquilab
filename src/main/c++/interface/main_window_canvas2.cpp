#include "main_window_class.h"
#include "iup.h"
#include "cd.h"
#include "wd.h"
#include "cdiup.h"
#include "stdlib.h"
#include "cdpdf.h"
#include "number_spliter.h"
#include "image.h"
#include "group.h"

static bool _dragging = false ;
static int _dragging_start_x ;
static int _dragging_start_y ;

static void exportToPDF( Project *p ) ;


static void selectByBoundingBox( Group* group, TopoEditor* editor, double xmin, double xmax, double ymin, double ymax )
{
   group->clear();

   for( int o = 0; o < editor->numObjects(); o++ )
   {
      Point2d o_min(0,0), o_max( 0, 0 );
      editor->_objects[o]->boundingBox( o_min, o_max );

      if( o_min._x >= xmin && o_min._y >= ymin && o_max._x <= xmax && o_max._y <= ymax )
      {
         group->addObject( editor->_objects[o] );
      }
   }
}


int MainWindow::repaintMainCanvas_cb(Ihandle* iupcanvas, float sx, float sy)
{
   if( !_dbuffer )
      return IUP_DEFAULT ;

   cdCanvasActivate( _dbuffer ) ;
   //wdWindow( 0, width,0, height );
   //wdViewport(0, width,0, height );
   cdBackground( CD_WHITE );
   cdForeground( _project->color() );

   cdCanvasClear(_dbuffer) ;
   //printf( "-------------------------\n");
   _project->editor().draw() ;
   //printf( "\n+++++++++++++++++++\n\n");

   cdLineWidth(1);
   cdLineStyle(CD_CONTINUOUS);
   cdForeground( CD_BLUE );
   if( _selected_obj )
   {
      cdCanvasInteriorStyle( _cdcanvas, CD_HOLLOW ) ;
      if( _manipulator )
         _manipulator->draw() ;
   }
   cdForeground( _project->color() );
   if( _builder )
   {
      cdLineWidth(_project->lineSize());
      cdForeground( _project->color() );
      cdLineStyle(_project->lineType());
      _builder->draw() ;
   }

   cdCanvasFlush(_dbuffer) ;

   // Para melhor performance
   if( !_builder )
   {
      cdActivate( _select_canvas ) ;
      //wdWindow( 0, width,0, height );
      //wdViewport(0, width,0, height );
      cdBackground( CD_RED ) ;//Object::noId() );
      cdClear() ;
      _project->editor().drawSelectable() ;
   }

   cdActivate( _dbuffer ) ;
   return IUP_DEFAULT ;
}


int MainWindow::buttonMainCanvas_cb( Ihandle* ih, int button, int pressed, int x, int y, char* status ) 
{ 
   y = cdUpdateYAxis( &y ) ;
   double xf = 0;
   double yf = 0;
   wdCanvas2World( x, y, &xf, &yf ) ;

   if( _builder )
   {
      Object *new_obj = NULL ;
      int bt = (button==IUP_BUTTON3) ? 3 : (button==IUP_BUTTON2) ? 2 : 1 ;
      // printf( "%d %s\n", pressed, status ) ;
      if( pressed==1 )
      {
         new_obj = _builder->pressButton( bt, xf, yf, isshift(status), iscontrol(status), isdouble(status) ); 
      }
      else
      {
         new_obj = _builder->releaseButton( bt, xf, yf, isshift(status), iscontrol(status), isdouble(status) ); 
      }
      if( new_obj )
      {
         new_obj->lineSize( _project->lineSize() ) ;
         new_obj->lineType( _project->lineType() ) ;
         Image* image = dynamic_cast<Image*>( new_obj );
         if( !image )
         {
            new_obj->color( _project->color() ) ;
         }
         _project->editor().addObject( new_obj ) ;
      }
      repaintMainCanvas_cb( ih, 0, 0 ) ;
      if( pressed == 0 )
      {
         _dragging = false;
      }
      return IUP_DEFAULT ;
   }

   if( _manipulator )
   {
      printf( "manipulador\n\n" );
      bool retorno = false ;
      int bt = (button==IUP_BUTTON3) ? 3 : (button==IUP_BUTTON2) ? 2 : 1 ;
      if( pressed==1 )
      {
         retorno = _manipulator->pressButton( bt, xf, yf, isshift(status), iscontrol(status), isdouble(status) ); 
         if( pressed == 0 )
         {
            _dragging = false;
         }
         return IUP_DEFAULT ;
      }
      else
      {
         retorno = _manipulator->releaseButton( bt, xf, yf, isshift(status), iscontrol(status), isdouble(status) ); 
      }        
   }

   if( button == IUP_BUTTON1 )
   {
      if( pressed == 1 )
      {
         _dragging = true;
         printf( "pressed" );
         return IUP_DEFAULT;

      }
      printf( "relesed" );


      //printf( "selecao\n\n" );
      //unsigned char r[600*601], g[600*601], b[600*601] ;
      int w=0, h=0 ;
      sscanf( IupGetAttribute( ih, "DRAWSIZE" ), "%dx%d", &w, &h ) ;
      cdCanvasGetImageRGB( _select_canvas, _red, _green , _blue, 0, 0, w, h ) ;

      unsigned char r = _red[y*w+x];
      unsigned char g = _green[y*w+x];
      unsigned char b = _blue[y*w+x];
      unsigned int id = 0 ;
      mergeNumber( id, r, g, b );

      Object * sel = _project->editor().selectId( id );
      if( sel &&_selected_obj != sel )
      {
         _selected_obj = sel ;
         if( _selected_obj )
         {
            _manipulator = _selected_obj->manipulator() ;
         }
      }   
      else
      {
         _selected_obj = NULL ;
         _manipulator = NULL ;
      }
   }
   syncMenus() ;
   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
   if( pressed == 0 )
   {
      _dragging = false;
   }
   return IUP_DEFAULT ;
}

int MainWindow::motionMainCanvas_cb(Ihandle* iupcanvas, int x, int y, char *status)
{
   printf( "motion\n" );
   IupSetAttribute( _iupcanvas, "CURSOR", _cursor ) ;
   y = cdUpdateYAxis( &y ) ;
   double xf = 0;
   double yf = 0;
   wdCanvas2World( x, y, &xf, &yf ) ;


   if( _builder )
   {
      _builder->motion( xf, yf, isshift(status), iscontrol(status) ) ;
      repaintMainCanvas_cb( iupcanvas, 1, 1 ) ;
   }
   else if( _selected_obj )
   {
      if( _manipulator )
      {      
         Manipulator::Type tp = _manipulator->motion(xf, yf, isshift(status), iscontrol(status) );
         if( tp != Manipulator::NONE )
         {
            switch( tp )
            {
            case Manipulator::MOVE_ALL: IupSetAttribute( _iupcanvas, "CURSOR", "MOVE" ) ; break ;
            case Manipulator::MOVE_POINT: IupSetAttribute( _iupcanvas, "CURSOR", "MOVE_POINT_CRS" ) ; break ;
            case Manipulator::RESIZE_N: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_N" ) ; break ;
            case Manipulator::RESIZE_S: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_S" ) ; break ;
            case Manipulator::RESIZE_NS: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_NS" ) ; break ;
            case Manipulator::RESIZE_W: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_W" ) ; break ;
            case Manipulator::RESIZE_E: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_E" ) ; break ;
            case Manipulator::RESIZE_WE: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_WE" ) ; break ;
            case Manipulator::RESIZE_NE: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_NE" ) ; break ;
            case Manipulator::RESIZE_SW: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_SW" ) ; break ;
            case Manipulator::RESIZE_NW: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_NW" ) ; break ;
            case Manipulator::RESIZE_SE: IupSetAttribute( _iupcanvas, "CURSOR", "RESIZE_SE" ) ; break ;
               //case ROTATE: IupSetAttribute( _iupcanvas, "CURSOR", "MOVE" ) ; break ;
            default: break; 
            }
         }
         if( _manipulator->manipulating() )
         {
            repaintMainCanvas_cb( _iupcanvas, 0, 0 )
               ;
         }
      }

   }
   else
   {
      if( _dragging )
      {
         Point2d min( _dragging_start_x, _dragging_start_y) ; 
         Point2d max( _dragging_start_x, _dragging_start_y) ; 
         updateBoundingBox( min, max, Point2d( xf, yf ) );
         printf( "dragging" );
         selectByBoundingBox( _selected_group, &(_project->editor()), min._x, max._x, min._y, max._y );
         _manipulator = _selected_group->manipulator();
      }
   }

   return IUP_DEFAULT ;
}
int MainWindow::scrollMainCanvas_cb(Ihandle *iupcanvas, int op, float posx, float posy)
{
   // float zoom = 1.0f ;

   int w = 581 ;
   int h = 581 ;

   sscanf( IupGetAttribute( iupcanvas, "DRAWSIZE" ), "%dx%d", &w, &h ) ;

   double wf = _zoom*w ;
   double hf = _zoom*h ;
   posy = 5999-posy ;

   wdCanvasWindow( _dbuffer, posx-wf/2, posx+wf/2-1, posy-hf/2, posy+hf/2-1 ) ;
   wdCanvasWindow( _select_canvas, posx-wf/2, posx+wf/2-1, posy-hf/2, posy+hf/2-1 ) ;
   cdActivate( _dbuffer ) ;
   repaintMainCanvas_cb( iupcanvas, posx, posy ) ;

   return IUP_DEFAULT ;
}
int MainWindow::enterMainCanvas_cb(Ihandle* iupcanvas)
{
   return IUP_DEFAULT ;
}
int MainWindow::leaveMainCanvas_cb(Ihandle* iupcanvas)
{
   return IUP_DEFAULT ;
}
int MainWindow::resizeMainCanvas_cb(Ihandle *iupcanvas, int width, int height ) 
{
   if( !_cdcanvas )
      return IUP_DEFAULT ;

   delete[] _red ;
   delete[] _green ;
   delete[] _blue ;
   _red = new unsigned char[width*height+100] ;
   _green = new unsigned char[width*height+100] ;
   _blue = new unsigned char[width*height+100] ;

   float posx=IupGetFloat( iupcanvas, "POSX" ) ;
   float posy=IupGetFloat( iupcanvas, "POSY" ) ;
   posy=5999-posy ;

   cdActivate( _dbuffer ) ;
   wdWindow( posx-width/2, posx+width/2-1, posy-height/2, posy+height/2-1 ) ;
   wdViewport(0, width, 0, height );

   cdKillCanvas( _select_canvas ) ;
   cdKillImage( _img_canvas ) ;
   cdUseContextPlus(0); 
   _img_canvas =  cdCanvasCreateImage(_tempcdcanvas , width, height ); 
   _select_canvas = cdCreateCanvas( CD_IMAGE , _img_canvas ) ;
   cdActivate( _select_canvas ) ;
   wdWindow( posx-width/2, posx+width/2-1, posy-height/2, posy+height/2-1 ) ;
   wdViewport(0, width, 0, height );
   cdActivate( _dbuffer ) ;




   //{
   //int w = 581 ;
   //int h = 581 ;

   //sscanf( IupGetAttribute( _iupcanvas, "DRAWSIZE" ), "%dx%d", &w, &h ) ;

   //w = _zoom*w ;
   //h = _zoom*h ;
   //posy = 5999-posy ;

   //wdCanvasWindow( _dbuffer, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   //wdCanvasWindow( _select_canvas, posx-w/2, posx+w/2-1, posy-h/2, posy+h/2-1 ) ;
   //cdActivate( _dbuffer ) ;
   //repaintMainCanvas_cb( _iupcanvas, posx, posy ) ;
   //}



   return IUP_DEFAULT ;
}

int MainWindow::keypressMainCanvas_cb(Ihandle *iupcanvas, int c, int press)
{
   if( !press )
      return IUP_DEFAULT ;

   if( _selected_obj )
   {
      if( _manipulator && _manipulator->manipulating() )
      {
         // if( press )
         if( _manipulator->pressKey( c ) )
            repaintMainCanvas_cb(iupcanvas, 0, 0 ) ;
         // else
         //   _manipulator->releaseKey( c ) ;

         return IUP_DEFAULT ;
      }
      else
      { 
         if( c == K_DEL )
         {
            editCommandsDelete_cb( iupcanvas ) ;
         }
         else if( c == K_cX )
         {
            editCommandsCut_cb( iupcanvas ) ;
         }
         else if( c == K_cC )
         {
            editCommandsCopy_cb( iupcanvas ) ;
         }
      }
   }
   if( c == K_cV )
   {
      editCommandsPaste_cb( iupcanvas ) ;
   }
   return IUP_DEFAULT ;
}
Ihandle* MainWindow::createCanvas( )
{
   //   /** remover daqui **/cria_arvore() ;   /** remover daqui **/
   Ihandle* iupcanvas = IupCanvas(NULL);


   IupSetAttributes(iupcanvas, "CURSOR=CROSS, RASTERSIZE=600x400, EXPAND=YES, SCROLLBAR=YES, XMAX=5999, YMAX=5999, POSX=3000, POSY=3000, DX=20, DY=20");

   IupSetCallback(iupcanvas, "ACTION",(Icallback)repaintMainCanvas_cb);
   IupSetCallback(iupcanvas, "BUTTON_CB",(Icallback)buttonMainCanvas_cb);
   IupSetCallback(iupcanvas, "SCROLL_CB",(Icallback)scrollMainCanvas_cb);
   IupSetCallback(iupcanvas, "MOTION_CB",(Icallback)motionMainCanvas_cb);
   IupSetCallback(iupcanvas, "ENTERWINDOW_CB",(Icallback)enterMainCanvas_cb);
   IupSetCallback(iupcanvas, "LEAVEWINDOW_CB",(Icallback)leaveMainCanvas_cb);
   IupSetCallback(iupcanvas, "RESIZE_CB",(Icallback)resizeMainCanvas_cb);
   IupSetCallback(iupcanvas, "KEYPRESS_CB",(Icallback)keypressMainCanvas_cb);



   return iupcanvas ;
} ;

//void multiSelect(Ihandle* ih, int button, int pressed, int x, int y, char* status)  
//{
//   static bool dragging = false ;
//   static int start_x = x ;
//   static int start_y = y ;
//
//   if( !pressed )
//      dragging = false;
//   else
//   {
//      if( !dragging )
//      {
//         clearSelection() ;
//         dragging = true ;
//         start_x = x ;
//         start_y = y ;
//
//         _manipulator = groupManipulator() ;
//      }
//   }  
//
//   for each object
//      if( object->boundingBox() < boundingBox( start_x, start_y, x, y )
//         select->addObject( object ) ;
//
//}