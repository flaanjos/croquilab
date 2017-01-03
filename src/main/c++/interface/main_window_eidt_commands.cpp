#include "main_window_class.h"
#include "iup.h"
#include "list_manipulator.h"
#include "commands\EditObjectsListCommand.h"
#include "commands\AddObjectsToEndCommand.h"


int MainWindow::editCommandsCopy_cb( Ihandle* ih )
{
   _clipboard_obj = _selected_obj ;
   return IUP_DEFAULT ;
}



int MainWindow::editCommandsPaste_cb( Ihandle* ih )
{
   if( _clipboard_obj.size() > 0 )
   {
      _selected_obj.clear();

      for( unsigned int o = 0 ; o < _clipboard_obj.size() ; o ++)
      {
         Object* object = _clipboard_obj[o]->copy() ;
         Saver* saver = (_clipboard_obj[o]->saver())->copy();

         saver->object( object );
         object->saver( saver );

         _selected_obj.push_back( object );
         _project->editor().addObject( object ) ;
      }

      if( _selected_obj.size() > 1 )
      {
         _manipulator = ListManipulator::instance( _selected_obj );
      }
      else
      {
         _manipulator = _selected_obj[0]->manipulator();
      }

      AddObjectsToEndCommand* command = new AddObjectsToEndCommand( &_project->editor(), _selected_obj );
      CommandStack::insert( command );

      repaintMainCanvas_cb(_iupcanvas, 0, 0 ) ;
   }
   return IUP_DEFAULT ;
}


int MainWindow::editCommandsCut_cb( Ihandle* ih )
{
   if( _selected_obj.size() > 0 )
   {
      _clipboard_obj = _selected_obj ;

      std::vector< Object*> old_list = _project->editor()._objects;

      for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
      {
         _project->editor().removeObject( _selected_obj[o] ) ;
      }

      std::vector< Object*> new_list = _project->editor()._objects;
      EditObjectsListCommand* command = new EditObjectsListCommand( &_project->editor(), old_list, new_list, _selected_obj );
      CommandStack::insert( command );

      _selected_obj.clear();
      _manipulator = 0;

      repaintMainCanvas_cb(_iupcanvas, 0, 0 ) ;
   }
   return IUP_DEFAULT ;
}


int MainWindow::editCommandsDelete_cb( Ihandle* ih )
{
   if( _selected_obj.size() > 0 )
   {
      std::vector< Object*> old_list = _project->editor()._objects;

      for( unsigned int o = 0 ; o < _selected_obj.size() ; o ++)
      {
         _project->editor().removeObject( _selected_obj[o] ) ;
      }
      std::vector< Object*> new_list = _project->editor()._objects;
      EditObjectsListCommand* command = new EditObjectsListCommand( &_project->editor(), old_list, new_list, _selected_obj );
      CommandStack::insert( command );

      _selected_obj.clear();
      _manipulator = 0;

      repaintMainCanvas_cb(_iupcanvas, 0, 0 ) ;
   }
   return IUP_DEFAULT ;
}


