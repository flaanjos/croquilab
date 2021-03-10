#include "EditListCommand.h"


EditListCommand::EditListCommand( const std::vector< Object* >& objects, 
   const std::vector< Point2d >& new_ps, 
   const std::vector< Point2d >& old_ps,
   const std::vector< Point2d >& new_ss,
   const std::vector< Point2d >& old_ss )
{
   _objects = objects;
   _new_ps = new_ps;
   _old_ps = old_ps;
   _new_ss = new_ss;
   _old_ss = old_ss;
}


EditListCommand::~EditListCommand() 
{
}


void EditListCommand::redo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->scale( _new_ss[o] );
      _objects[o]->position( _new_ps[o] );    
   }
}


void EditListCommand::undo() 
{
   for( unsigned int o = 0; o < _objects.size(); o++)
   {
      _objects[o]->scale( _old_ss[o] );
      _objects[o]->position( _old_ps[o] );    
   }
}


