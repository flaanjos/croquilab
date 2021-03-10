#ifndef _EDIT_SCALE_COMMAND__H_ 
#define _EDIT_SCALE_COMMAND__H_ 4

#include "command.h"



class EditScaleCommand : public Command
{
public:

   EditScaleCommand( const std::vector< Object* >& objects, const Point2d& new_p, const Point2d& old_p, const Point2d& new_s, const Point2d& old_s ) ;
   ~EditScaleCommand() ;

   void redo() ;
   void undo() ;

private:


   Point2d _new_p ;
   Point2d _old_p ;
   Point2d _new_s ;
   Point2d _old_s ;
} ;

#endif