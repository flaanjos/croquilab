#ifndef _COMMAND__H_ 
#define _COMMAND__H_ 4

#include "object.h"
#include <vector>

class Command
{
public:

   Command(){};
   virtual ~Command(){};

   virtual std::vector< Object* > getObjects() { return _objects ; };

   virtual void redo() = 0;
   virtual void undo() = 0;

protected:
   std::vector< Object* > _objects;
};

#endif

