#ifndef _TEXT_SAVER__
#define _TEXT_SAVER__ 2

#include "text.h"
#include <ostream> 
#include "saver.h"
#include <string>

class TextSaver : public Saver
{
public:
   TextSaver( Text* t );
   TextSaver() ;
   virtual ~TextSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Text *_text ;
};

#endif