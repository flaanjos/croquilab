#ifndef _OBJECT_SAVER__H_
#define _OBJECT_SAVER__H_

#include <stdio.h>

class ObjectSaver
{
public:
   Saver() {} ;
   ~Saver() {} ;

   virtual void save( FILE *f ) ;

}
#endif