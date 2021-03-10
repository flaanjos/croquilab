#ifndef _CHANGE_WIDE_SEGMENTED_WIDTH_COMMAND_H_
#define _CHANGE_WIDE_SEGMENTED_WIDTH_COMMAND_H_ 4

#include "Command.h"
#include "wide_segmented_object.h"

class EditWideSegmentedWidth : public Command
{
public:

   EditWideSegmentedWidth( WideSegmented* o, float new_w, float old_w ) ;
   ~EditWideSegmentedWidth() ;

   void redo() ;
   void undo() ;

private:

   WideSegmented* _object ;
   float _new_w ;
   float _old_w ;
};


#endif