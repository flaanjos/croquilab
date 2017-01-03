#ifndef _SCREW_SAVER__
#define _SCREW_SAVER__ 2

#include "screw.h"
#include <ostream> 
#include "saver.h"

class ScrewSaver : public Saver
{
public:
   ScrewSaver( Screw* screw );
   ScrewSaver() ;
   virtual ~ScrewSaver() ;

   virtual void save( std::ostream &stream ) ;

private:

   Screw *_screw ;

};

#endif