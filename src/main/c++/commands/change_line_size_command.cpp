#include "ChangeLineSizeCommand.h"


ChangeLineSizeCommand::ChangeLineSizeCommand( const std::vector< Object* >& objects, long int new_ls, const std::vector< long int >& old_ls )
{
    _objects = objects;
   _new_ls = new_ls;
   _old_ls = old_ls;
}


ChangeLineSizeCommand::~ChangeLineSizeCommand()
{
}


void ChangeLineSizeCommand::redo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->lineSize( _new_ls );
   }
}


void ChangeLineSizeCommand::undo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->lineSize( _old_ls[o] );
   }
}

