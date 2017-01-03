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
   Point2d diff = _new_p - _object->position( _point_index );
   _object->position( _point_index, _new_p );

   Point2d new_aft = _object->positionAftScape( _point_index ) + diff;
   _object->positionAftScape( _point_index, new_aft );

   Point2d new_prev = _object->positionPrevScape( _point_index ) + diff;
   _object->positionPrevScape( _point_index, new_prev );

}


void EditCurvedPointCommand::undo() 
{
   Point2d diff = _old_p - _object->position( _point_index );
   _object->position( _point_index, _old_p );

   Point2d new_aft = _object->positionAftScape( _point_index ) + diff;
   _object->positionAftScape( _point_index, new_aft );

   Point2d new_prev = _object->positionPrevScape( _point_index ) + diff;
   _object->positionPrevScape( _point_index, new_prev );
}
