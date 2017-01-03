#ifndef _COMMAND_STACK_H_
#define _COMMAND_STACK_H_ 4

#include "object.h"
#include "command.h"
#include <vector>

class CommandStack
{
private:
   CommandStack();
   ~CommandStack();

public:
   static Command* getUndoCommand();
   static Command* getRedoCommand();

   static void insert(  Command* command );

   static void clear();

   static bool undoss();
   static bool redoss();

private:

   static std::vector< Command* > _undo_stack;   
   static std::vector< Command* > _redo_stack;   
};

#endif