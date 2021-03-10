#ifndef _EDIT_TEXT_COMMAND_H_
#define _EDIT_TEXT_COMMAND_H_ 4

#include "command.h"
#include "text.h"

class EditTextCommand : public Command
{
public:
   EditTextCommand( Text* text, const std::string& new_t, const std::string& old_t, int new_size, int old_size );
   ~EditTextCommand();

   void redo();
   void undo();

private:

   int _new_s;
   int _old_s;
   std::string _new_t;
   std::string _old_t;
   Text* _text;
};

#endif