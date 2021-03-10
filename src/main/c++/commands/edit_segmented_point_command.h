#ifndef _EDIT_SEGMENTED_POINT_COMMAND__H_ 
#define _EDIT_SEGMENTED_POINT_COMMAND__H_  4

#include "Command.h"
#include "segmented_object.h"

class EditSegmentedPointCommand : public Command
{
public:

   EditSegmentedPointCommand( Segmented* o, int point_index, const Point2d& new_p, const Point2d& old_p ) ;
   ~EditSegmentedPointCommand() ;

   void redo() ;
   void undo() ;

private:
   Segmented* _object ;
   int _point_index ;
   Point2d _new_p ;
   Point2d _old_p ;
} ;

#endif
