#ifndef _SCALABLE_SAVER__
#define _SCALABLE_SAVER__ 2

#include "scalable_object.h"
#include <ostream> 
#include "saver.h"
#include <string>

class ScalableSaver : public Saver
{
public:
   ScalableSaver( Scalable* s );
   ScalableSaver( Scalable* s, const std::string& type_name );
   ScalableSaver() ;
   virtual ~ScalableSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Scalable *_scalable ;
   std::string _type_name ;

};

#endif