#ifndef _COMMAND_STACK_H_
#define _COMMAND_STACK_H_ 4

#include "object.h"
#include "command.h"
#include <vector>

class CommandStack
{
public:
   CommandStack();
   ~CommandStack();

public:
   Command* getUndoCommand();
   Command* getRedoCommand();

   void insert(  Command* command );

   void clear();

   bool undoss();
   bool redoss();

private:

   std::vector< Command* > _undo_stack;   
   std::vector< Command* > _redo_stack;   
};

#endif