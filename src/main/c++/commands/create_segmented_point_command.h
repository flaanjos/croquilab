#ifndef _CREATE_SEGMENTED_POINT_COMMAND__H_ 
#define _CREATE_SEGMENTED_POINT_COMMAND__H_ 4

#include "command.h"
#include "segmented_object.h"

class CreateSegmentedPointCommand : public Command
{
public:
   CreateSegmentedPointCommand( Segmented* o, int point_index, const Point2d& position );
   ~CreateSegmentedPointCommand();
   void redo();
   void undo();

private:
   Segmented* _object;
   int _point_index;
   Point2d _position;
};

#endif