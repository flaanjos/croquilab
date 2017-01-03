#ifndef _GROUP_SAVER__
#define _GROUP_SAVER__ 2

#include "group.h"
#include <ostream> 
#include "saver.h"
#include <string>

class GroupSaver : public Saver
{
public:
   GroupSaver( Group* g );
   GroupSaver( Group* g, const std::string& type_name );
   GroupSaver() ;
   virtual ~GroupSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Group *_group ;
   std::string _type_name ;

};

#endif