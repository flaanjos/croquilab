#ifndef _EDIT_OBJECTS_LIST_COMMAND_H_
#define _EDIT_OBJECTS_LIST_COMMAND_H_ 4

#include "command.h"
#include "object.h"
#include <vector>
#include "../topo_editor.h"



class EditObjectsListCommand : public Command
{
public:
   EditObjectsListCommand( TopoEditor* editor, const std::vector< Object* >& old_list, const std::vector< Object* >& new_list,const std::vector< Object* >& objects );
   ~EditObjectsListCommand();
   void redo();
   void undo();

private:
   std::vector< Object* > _old_list ;
   std::vector< Object* > _new_list ;
   TopoEditor* _editor;
};

#endif
