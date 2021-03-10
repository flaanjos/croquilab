#ifndef _CHANGE_LINE_SIZE_COMMAND_H_
#define _CHANGE_LINE_SIZE_COMMAND_H_ 4

#include "Command.h"


class ChangeLineSizeCommand : public Command
{
public:
   ChangeLineSizeCommand( const std::vector< Object* >& objects, long int new_ls, const std::vector< long int >& old_ls );
   ~ChangeLineSizeCommand();

   void redo();
   void undo();

private:

   long int _new_ls;
   std::vector< long int > _old_ls;
};

#endif
