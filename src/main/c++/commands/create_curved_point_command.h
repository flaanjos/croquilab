#ifndef _CREATE_CURVED_POINT_COMMAND__H_ 
#define _CREATE_CURVED_POINT_COMMAND__H_  4

#include "Command.h"
#include "curved_object.h"

class CreateCurvedPointCommand : public Command
{
public:

   CreateCurvedPointCommand( Curved* o, int point_index, const Point2d& p ) ;
   ~CreateCurvedPointCommand() ;

   void redo() ;
   void undo() ;

private:
   Curved* _object ;
   int _point_index ;
   Point2d _position ;
} ;

#endif
