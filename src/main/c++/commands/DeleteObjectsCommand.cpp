#include "EditObjectsListCommand.h"


DeleteObjectsCommand::DeleteObjectsCommand( TopoEditor* editor, const std::vector< Object* >& old_list, const std::vector< Object* >& new_list, const std::vector< Object* >& objects )
{
   _objects = objects;
   _old_list = old_list ;
   _new_list = new_list ;
   _editor = editor;
}



DeleteObjectsCommand::~DeleteObjectsCommand()
{
}



void DeleteObjectsCommand::redo()
{
   _editor->clear();
   for( unsigned int i = 0; i < _new_list.size(); i++ )
   {
      _editor->addObject( _new_list[i] );
   }
}



void DeleteObjectsCommand::undo()
{
   _editor->clear();
   for( unsigned int i = 0; i < _old_list.size(); i++ )
   {
      _editor->addObject( _old_list[i] );
   }
}
