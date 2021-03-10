#ifndef _ADD_OBJECTS_TO_END_COMMAND_H_
#define _ADD_OBJECTS_TO_END_COMMAND_H_ 4

#include "command.h"
#include "object.h"
#include <vector>
#include "../topo_editor.h"



class AddObjectsToEndCommand : public Command
{
public:
   AddObjectsToEndCommand( TopoEditor* editor, const std::vector< Object* >& objects );
   ~AddObjectsToEndCommand();
   void redo();
   void undo();

private:
   TopoEditor* _editor;
};

#endif
