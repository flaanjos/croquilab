#include "CreateSegmentedPointCommand.h"


CreateSegmentedPointCommand::CreateSegmentedPointCommand( Segmented* o, int point_index, const Point2d& p ) :
   _position( p )
{
   _objects.push_back( o );
   _object = o ;
   _point_index = point_index ;
}


CreateSegmentedPointCommand::~CreateSegmentedPointCommand() 
{
}


void CreateSegmentedPointCommand::redo() 
{
   _object->addPoint( _point_index, _position );
}


void CreateSegmentedPointCommand::undo() 
{
   _object->removePoint( _point_index );
}