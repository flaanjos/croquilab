#include "EditCurvedPointCommand.h"


EditCurvedPointCommand::EditCurvedPointCommand( Curved* o, int point_index, const Point2d& new_p, const Point2d& old_p ) :
   _new_p( new_p ),
   _old_p( old_p )
{
   _objects.push_back( o );
   _object = o ;
   _point_index = point_index ;
}


EditCurvedPointCommand::~EditCurvedPointCommand() 
{
}


void EditCurvedPointCommand::redo() 
{
   _object->position( _point_index, _new_p );
}


void EditCurvedPointCommand::undo() 
{
   _object->position( _point_index, _old_p );
}
