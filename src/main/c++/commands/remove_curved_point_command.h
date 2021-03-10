#ifndef _REMOVE_CURVED_POINT_COMMAND__H_ 
#define _REMOVE_CURVED_POINT_COMMAND__H_  4

#include "command.h"
#include "curved_object.h"

class RemoveCurvedPointCommand : public Command
{
public:

   RemoveCurvedPointCommand( Curved* o, int point_index ) ;
   ~RemoveCurvedPointCommand() ;

   void redo() ;
   void undo() ;

private:
   Curved* _object ;
   int _point_index ;
   Point2d _position_main ;
   Point2d _position_prev ;
   Point2d _position_aft ;
} ;

#endif
