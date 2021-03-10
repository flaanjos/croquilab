#include "iup.h"
#include "stdio.h"
#include "img_drop_down_list.h"
#include "main_window_class.h"
#include "cd.h"
#include "commands/edit_objects_list_command.h"

enum OrderAction
{
   MOVE_TO_END,
   MOVE_TO_BEGINING,
   MOVE_BACK_ONE,
   MOVE_FOWARD_ONE,
};



static char *img_order[]           = { "move_to_end_bt_img",     "move_back_bt_img",     "move_foward_bt_img",     "move_to_begining_bt_img" } ;
static char *img_orfer_highlight[] = { "move_to_end_hl_bt_img",  "move_back_hl_bt_img",  "move_foward_hl_bt_img",  "move_to_begining_hl_bt_img" } ;
static char *img_order_sel[]       = { "move_to_end_sel_bt_img", "move_back_sel_bt_img", "move_foward_sel_bt_img", "move_to_begining_sel_bt_img" } ;
static OrderAction order_actions[] = { MOVE_TO_END, MOVE_BACK_ONE, MOVE_FOWARD_ONE, MOVE_TO_BEGINING } ;
static char *order_hints[] = { "Mover para tr�s", "Recuar um", "Avan�ar um", "Mover para frente" } ;

static char *img_order_files[]     = { "button_images\\order\\move_to_end_bt_img.led",     "button_images\\order\\move_back_bt_img.led",     "button_images\\order\\move_foward_bt_img.led",     "button_images\\order\\move_to_begining_bt_img.led" } ;
//static char *img_order_sel_files[] = { "button_images\\order\\normal\\move_to_end_sel_bt.led",  "button_images\\order\\normal\\move_back_sel_bt.led",  "button_images\\order\\normal\\move_foward_sel_bt.led",  "button_images\\order\\normal\\move_to_begining_sel_bt.led" } ;



int MainWindow::reorder_cb( Ihandle *button )
{
   OrderAction action = (OrderAction)IupGetInt( button, "ORDER_ACTION" );


   std::vector< Object*> old_order =_project->editor()._objects ;

   if( _selected_obj.size() == 1)
   {


      switch( action )
      {
      case MOVE_TO_END: _project->editor().moveToEnd( _selected_obj[0] ) ;
         repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
         break;
      case MOVE_TO_BEGINING: _project->editor().moveToBegining( _selected_obj[0] ) ;
         repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
         break;
      case MOVE_BACK_ONE: _project->editor().moveBackOne( _selected_obj[0] ) ;
         repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
         break;
      case MOVE_FOWARD_ONE: _project->editor().moveFowardOne( _selected_obj[0] ) ;         
         repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
         break;
      default:
         break;
      }
   }
   else if( _selected_obj.size() > 0 )
   {
      if( action == MOVE_FOWARD_ONE || action == MOVE_TO_END )
      {
         for( unsigned int o = _selected_obj.size() - 1 ; o >= 0; o-- )
         {
            switch( action )
            {
            case MOVE_TO_END: 
               _project->editor().moveToEnd( _selected_obj[o] ) ;          
               break;
            case MOVE_FOWARD_ONE:
               _project->editor().moveFowardOne( _selected_obj[o] ) ;
               break;
            default:
               break;
            }
         }
      }
      else
      {
         for( unsigned int o = 0 ; o < _selected_obj.size() ; o++ )
         {
            switch( action )
            {
            case MOVE_TO_BEGINING: _project->editor().moveToBegining( _selected_obj[o] ) ;
               break;
            case MOVE_BACK_ONE: _project->editor().moveBackOne( _selected_obj[o] ) ;
               break;
            default:
               break;
            }
         }
      }      
   }

   std::vector< Object*> new_order =_project->editor()._objects ;

   Command* command = new EditObjectsListCommand( &_project->editor(), old_order, new_order, _selected_obj );
   CommandStack::insert( command );
   

   repaintMainCanvas_cb( _iupcanvas, 0, 0 ) ;
   return IUP_DEFAULT ;
};

Ihandle * MainWindow::createOrderMenu()
{
   Ihandle *end_bt ;
   Ihandle *order_box = IupHbox( NULL ) ;

   for( int i=0 ; i<4 ; i++ )
   {
      char* error = 0;
      error = IupLoad( img_order_files[i] ) ;
      //error = IupLoad( img_order_sel_files[i] ) ;

      Ihandle *button = IupButton( NULL, NULL );
      IupSetfAttribute( button, "ORDER_ACTION", "%d", (int)order_actions[i] );

      IupSetAttribute( button, IUP_IMAGE, img_order[i] );
     // IupSetAttribute( button, IUP_IMPRESS, img_order_sel[i] );
      IupSetAttribute( button, "FLAT", IUP_YES );
      IupSetAttribute( button, IUP_RASTERSIZE, "28x28" );
      IupSetAttribute( button, IUP_TIP, order_hints[i] );
      IupSetCallback( button, IUP_ACTION, (Icallback)reorder_cb ) ;

      IupAppend( order_box, button ) ; 
   }
   IupSetAttribute( order_box, IUP_MARGIN, "0x0" ) ; 
   IupSetAttribute( order_box, IUP_GAP, "0x0" ) ; 
   return order_box ;
}
