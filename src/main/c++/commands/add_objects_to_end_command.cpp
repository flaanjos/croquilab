#include "add_objects_to_end_command.h"

AddObjectsToEndCommand::AddObjectsToEndCommand( TopoEditor* editor, const std::vector< Object* >& objects )
{
   _objects = objects;
   _editor = editor;

}


AddObjectsToEndCommand::~AddObjectsToEndCommand()
{
}


void AddObjectsToEndCommand::redo()
{
   for( unsigned int i = 0; i < _objects.size(); i++ )
   {
      _editor->addObject( _objects[i] );
   }
}


void AddObjectsToEndCommand::undo()
{
   for( unsigned int i = 0; i < _objects.size(); i++ )
   {
      _editor->removeObject( _objects[i] );
   }
}
