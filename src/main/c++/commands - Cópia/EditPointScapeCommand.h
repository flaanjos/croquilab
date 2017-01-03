#ifndef _EDIT_CURVED_POINT_SCAPE_COMMAND__H_ 
#define _EDIT_CURVED_POINT_SCAPE_COMMAND__H_  4

#include "Command.h"
#include "curved_object.h"

class EditPointScapeCommand : public Command
{
public:

   EditPointScapeCommand( Curved* o, int scape_type, int point_index, const Point2d& new_p, const Point2d& old_p ) ;
   ~EditPointScapeCommand() ;

   void redo() ;
   void undo() ;

private:
   Curved* _object ;
   int _scape_type ;
   int _point_index ;
   Point2d _new_p ;
   Point2d _old_p ;
} ;

#endif
