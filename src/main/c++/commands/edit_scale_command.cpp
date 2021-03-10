#include "edit_scale_command.h"


EditScaleCommand::EditScaleCommand( const std::vector< Object* >& objects, const Point2d& new_p, const Point2d& old_p, const Point2d& new_s, const Point2d& old_s ) :
   _new_p( new_p ),
   _old_p( old_p ),
   _new_s( new_s ),
   _old_s( old_s )
{
   _objects = objects ;
}


EditScaleCommand::~EditScaleCommand() 
{
}


void EditScaleCommand::redo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->scale( _new_s );
      _objects[o]->position( _new_p );
   }
}


void EditScaleCommand::undo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->scale( _old_s );
      _objects[o]->position( _old_p );
   }
}
