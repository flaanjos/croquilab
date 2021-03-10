#include "CreateCurvedPointCommand.h"


CreateCurvedPointCommand::CreateCurvedPointCommand( Curved* o, int point_index, const Point2d& p ) :
   _position( p )
{
   _objects.push_back( o );
   _object = o ;
   _point_index = point_index ;
}


CreateCurvedPointCommand::~CreateCurvedPointCommand() 
{
}


void CreateCurvedPointCommand::redo() 
{
   _object->addPoint( _point_index, _position );  
}


void CreateCurvedPointCommand::undo() 
{
   _object->removePoint( _point_index );
}
