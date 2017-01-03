#include "EditPositionCommand.h"


EditPositionCommand::EditPositionCommand( const std::vector< Object* >& objects, const Point2d& new_p, const Point2d& old_p ) :
   _new_p( new_p ),
   _old_p( old_p )
{
   _objects = objects ;
}


EditPositionCommand::~EditPositionCommand() 
{
}


void EditPositionCommand::redo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->position( _new_p );
   }
}


void EditPositionCommand::undo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->position( _old_p );
   }
}


