#ifndef _CHANGE_COLOR_COMMAND_H_
#define _CHANGE_COLOR_COMMAND_H_ 4

#include "Command.h"

class ChangeColorCommand : public Command
{
public:
   ChangeColorCommand( const std::vector< Object* >& objects, long int new_c, const std::vector< long int >& old_c );
   ~ChangeColorCommand();

   void redo();
   void undo();

private:

   long int _new_c;
   std::vector< long int > _old_c;
};

#endif
