#ifndef _EDIT_CURVED_POINT_COMMAND__H_ 
#define _EDIT_CURVED_POINT_COMMAND__H_  4

#include "command.h"
#include "curved_object.h"

class EditCurvedPointCommand : public Command
{
public:

   EditCurvedPointCommand( Curved* o, int point_index, const Point2d& new_p, const Point2d& old_p ) ;
   ~EditCurvedPointCommand() ;

   void redo() ;
   void undo() ;

private:
   Curved* _object ;
   int _point_index ;
   Point2d _new_p ;
   Point2d _old_p ;
} ;

#endif
