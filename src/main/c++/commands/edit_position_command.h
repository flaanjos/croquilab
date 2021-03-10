#ifndef _EDIT_POSITION_COMMAND__H_ 
#define _EDIT_POSITION_COMMAND__H_ 4

#include "Command.h"
#include "object.h"


class EditPositionCommand : public Command
{
public:

   EditPositionCommand( const std::vector< Object* >& objects, const Point2d& new_p, const Point2d& old_p ) ;
   ~EditPositionCommand() ;

   void redo() ;
   void undo() ;

private:

   Point2d _new_p ;
   Point2d _old_p ;
};


#endif
