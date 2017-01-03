#ifndef _CHANGE_LINE_TYPE_COMMAND_H_
#define _CHANGE_LINE_TYPE_COMMAND_H_ 4

#include "Command.h"


class ChangeLineTypeCommand : public Command
{
public:
   ChangeLineTypeCommand( const std::vector< Object* >& objects, long int new_lt,  const std::vector< long int >& old_lt );
   ~ChangeLineTypeCommand();

   void redo();
   void undo();

private:

   long int _new_lt;
   std::vector< long int > _old_lt;
};

#endif