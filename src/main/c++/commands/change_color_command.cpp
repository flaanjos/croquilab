#include "change_color_command.h"


ChangeColorCommand::ChangeColorCommand( const std::vector< Object* >& objects, long int new_c, const std::vector< long int >& old_c )
{
    _objects = objects;
   _new_c = new_c;
   _old_c = old_c;
}


ChangeColorCommand::~ChangeColorCommand()
{
}


void ChangeColorCommand::redo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->color( _new_c );
   }
}


void ChangeColorCommand::undo()
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->color( _old_c[o] );
   }
}

