#ifndef _SEGMENTED_SAVER__
#define _SEGMENTED_SAVER__ 2

#include "segmented_object.h"
#include <ostream> 
#include "saver.h"
#include <string>

class SegmentedSaver : public Saver
{
public:
   SegmentedSaver( Segmented* s );
   SegmentedSaver( Segmented* s, const std::string& type_name );
   SegmentedSaver() ;
   virtual ~SegmentedSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;


private:

   Segmented *_segmented ;
   std::string _type_name ;

};

#endif