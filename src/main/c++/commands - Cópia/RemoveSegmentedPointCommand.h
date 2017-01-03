#ifndef _REMOVE_SEGMENTED_POINT_COMMAND__H_ 
#define _REMOVE_SEGMENTED_POINT_COMMAND__H_ 4

#include "Command.h"
#include "segmented_object.h"


class RemoveSegmentedPointCommand : public Command
{
public:
   RemoveSegmentedPointCommand( Segmented* o, int point_index, const Point2d& position );
   ~RemoveSegmentedPointCommand();
   void redo();
   void undo();

private:
   Segmented* _object;
   int _point_index;
   Point2d _position;
};

#endif