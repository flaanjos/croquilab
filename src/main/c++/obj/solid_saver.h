#ifndef _SOLID_SAVER__
#define _SOLID_SAVER__ 2

#include "solid_object.h"
#include <ostream> 
#include "saver.h"
#include <string>

class SolidSaver : public Saver
{
public:
   SolidSaver( Solid* s );
   SolidSaver( Solid* s, const std::string& type_name );
   SolidSaver() ;
   virtual ~SolidSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Solid *_solid ;
   std::string _type_name ;

};

#endif