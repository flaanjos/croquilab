#include "commandStack.h"


 std::vector< Command* > CommandStack::_undo_stack;   
 std::vector< Command* > CommandStack::_redo_stack;   

CommandStack::CommandStack()
{
}


CommandStack::~CommandStack()
{
}



Command* CommandStack::getUndoCommand()
{
   int last = ((int)(_undo_stack.size())) - 1 ;
   if(  last >= 0 )
   {
      return _undo_stack[last] ;
   }
   return 0;
}


Command* CommandStack::getRedoCommand()
{
   int last = ((int)(_redo_stack.size())) - 1 ;
   if(  last >= 0 )
   {
      return _redo_stack[last] ;
   }
   return 0;
}


bool CommandStack::undoss()
{
   int last = ((int)(_undo_stack.size())) - 1 ;
   if(  last >= 0 )
   {
      Command* command = 0 ;
      command = _undo_stack[last] ;
      _undo_stack.pop_back();
      _redo_stack.push_back( command );
      command->undo();
      return true;
   }

   return false;
}


bool CommandStack::redoss()
{
   int last = ((int)(_redo_stack.size())) - 1 ;
   if(  last >= 0 )
   {
      Command* command = 0 ;
      command = _redo_stack[last] ;
      _redo_stack.pop_back();
      _undo_stack.push_back( command );
      command->redo();
      return true;
   }

   return false;
}


void CommandStack::insert(  Command* command )
{
   for ( unsigned int i = 0 ; i < _redo_stack.size() ; i++ )
   {
      delete _redo_stack[i];
   }
   _redo_stack.clear() ;

   _undo_stack.push_back( command );
}


void CommandStack::clear()
{
   for ( unsigned int i = 0 ; i < _redo_stack.size() ; i++ )
   {
      delete _redo_stack[i];
   }
   _redo_stack.clear() ;

   for ( unsigned int i = 0 ; i < _undo_stack.size() ; i++ )
   {
      delete _undo_stack[i];
   }
   _undo_stack.clear() ;
}



