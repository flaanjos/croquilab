#ifndef _WIDE_SEGMENTED_SAVER__
#define _WIDE_SEGMENTED_SAVER__ 2

#include "wide_segmented_object.h"
#include <ostream> 
#include "saver.h"
#include <string>

class WideSegmentedSaver : public Saver
{
public:
   WideSegmentedSaver( WideSegmented* s );
   WideSegmentedSaver( WideSegmented* s, const std::string& type_name );
   WideSegmentedSaver() ;
   virtual ~WideSegmentedSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;


private:

   WideSegmented *_segmented ;
   std::string _type_name ;

};

#endif