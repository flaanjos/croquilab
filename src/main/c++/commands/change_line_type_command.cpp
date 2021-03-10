#include "change_line_type_command.h"


ChangeLineTypeCommand::ChangeLineTypeCommand( const std::vector< Object* >& objects, long int new_lt, const std::vector< long int >& old_lt )
{
    _objects = objects;
   _new_lt = new_lt;
   _old_lt = old_lt;
}


ChangeLineTypeCommand::~ChangeLineTypeCommand()
{
}


void ChangeLineTypeCommand::redo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->lineType( _new_lt );
   }
}


void ChangeLineTypeCommand::undo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->lineType( _old_lt[o] );
   }
}

