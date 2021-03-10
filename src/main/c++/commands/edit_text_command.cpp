#include "edit_text_command.h"

EditTextCommand::EditTextCommand( Text* text, const std::string& new_t, const std::string& old_t, int new_s, int old_s )
{
   _new_s = new_s;
   _old_s = old_s;
   _text = text;
   _old_t = old_t;
   _new_t = new_t;
}



EditTextCommand::~EditTextCommand()
{
}



void EditTextCommand::redo()
{
   _text->size( _new_s );
   _text->text( _new_t );
}



void EditTextCommand::undo()
{
   _text->size( _old_s );
   _text->text( _old_t );
}
