#include "commandStack.h"

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
   _redo_stack.clear() ;
   _undo_stack.push_back( command );
}


void CommandStack::clear()
{
   _redo_stack.clear() ;
   _undo_stack.clear() ;
}



