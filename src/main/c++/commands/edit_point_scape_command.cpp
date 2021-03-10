#include "edit_point_scape_command.h


EditPointScapeCommand::EditPointScapeCommand( Curved* o, int scape_type, int point_index, const Point2d& new_p, const Point2d& old_p ) :
   _new_p( new_p ),
   _old_p( old_p )
{
   _objects.push_back( o );
   _scape_type = scape_type ;
   _object = o ;
   _point_index = point_index ;
}


EditPointScapeCommand::~EditPointScapeCommand() 
{
}


void EditPointScapeCommand::redo() 
{
   if( _scape_type == 0 )
   {
      _object->positionPrevScape( _point_index, _new_p );
   }
   else
   {
      _object->positionAftScape( _point_index, _new_p );
   }
}


void EditPointScapeCommand::undo() 
{
   if( _scape_type == 0 )
   {
      _object->positionPrevScape( _point_index, _old_p );
   }
   else
   {
      _object->positionAftScape( _point_index, _old_p );
   }
}
