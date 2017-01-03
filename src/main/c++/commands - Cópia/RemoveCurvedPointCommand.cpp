#include "RemoveCurvedPointCommand.h"


RemoveCurvedPointCommand::RemoveCurvedPointCommand( Curved* o, int point_index, const Point2d& p ) :
   _position( p )
{
   _objects.push_back( o );
   _object = o ;
   _point_index = point_index ;
}


RemoveCurvedPointCommand::~RemoveCurvedPointCommand() 
{
}


void RemoveCurvedPointCommand::redo() 
{
   _object->removePoint( _point_index );
}


void RemoveCurvedPointCommand::undo() 
{
   _object->addPoint( _point_index, _position );
}
