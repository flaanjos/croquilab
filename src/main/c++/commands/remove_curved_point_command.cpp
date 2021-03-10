#include "remove_curved_point_command.h"


RemoveCurvedPointCommand::RemoveCurvedPointCommand( Curved* o, int point_index ) :
   _position_main( o->position( point_index ) ), 
   _position_prev( o->positionPrevScape( point_index ) ), 
   _position_aft( o->positionAftScape( point_index ) )  
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
   _object->addPoint( _point_index, _position_main );
   _object->positionPrevScape( _point_index, _position_prev ) ; 
   _object->positionAftScape( _point_index, _position_aft ) ;  
}
