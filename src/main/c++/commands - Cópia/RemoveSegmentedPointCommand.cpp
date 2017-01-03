#include "RemoveSegmentedPointCommand.h"


RemoveSegmentedPointCommand::RemoveSegmentedPointCommand( Segmented* o, int point_index, const Point2d& p ) :
   _position( p )
{
   _objects.push_back( o );
   _object = o ;
   _point_index = point_index ;
}


RemoveSegmentedPointCommand::~RemoveSegmentedPointCommand() 
{
}


void RemoveSegmentedPointCommand::redo() 
{
   _object->removePoint( _point_index );
}


void RemoveSegmentedPointCommand::undo() 
{
   _object->addPoint( _point_index, _position );
}