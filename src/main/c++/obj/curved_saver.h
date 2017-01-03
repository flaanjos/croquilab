#ifndef _CURVED_SAVER__
#define _CURVED_SAVER__ 2

#include "curved_object.h"
#include <ostream> 
#include "saver.h"
#include <string>

class CurvedSaver : public Saver
{
public:
   CurvedSaver( Curved* s );
   CurvedSaver( Curved* s, const std::string& type_name );
   CurvedSaver() ;
   virtual ~CurvedSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Curved *_curved ;
   std::string _type_name ;

};

#endif