#ifndef _EDIT_LIST_COMMAND__H_ 
#define _EDIT_LIST_COMMAND__H_ 4

#include "Command.h"


class EditListCommand : public Command
{
public:

   EditListCommand( const std::vector< Object* >& objects, 
      const std::vector< Point2d >& new_ps,
      const std::vector< Point2d >& old_ps,
      const std::vector< Point2d >& new_ss,
      const std::vector< Point2d >& old_ss ) ;
   ~EditListCommand() ;

   void redo() ;
   void undo() ;

private:

   std::vector< Point2d > _new_ps ;
   std::vector< Point2d > _old_ps ;
   std::vector< Point2d > _new_ss ;
   std::vector< Point2d > _old_ss ;
};


#endif
