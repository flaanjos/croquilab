#ifndef _SAVER__
#define _SAVER__ 1

#include <ostream> 
//#include "object.h"

class Object;

class Saver
{
public:
   Saver(  ) {} ;
   virtual ~Saver() {} ;

   virtual void save( std::ostream& stream ) = 0 ;

   virtual Saver* copy() = 0 ;

   virtual Object* object() = 0 ;

   virtual void object( Object* o ) = 0 ;
};

#endif