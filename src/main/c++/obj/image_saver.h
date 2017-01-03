#ifndef _IMAGE_SAVER__
#define _IMAGE_SAVER__ 2

#include "image.h"
#include <ostream> 
#include "saver.h"
#include <string>

class ImageSaver : public Saver
{
public:
   ImageSaver( Image* s );
   ImageSaver( Image* s, const std::string& type_name );
   ImageSaver() ;
   virtual ~ImageSaver() ;

   virtual void save( std::ostream &stream ) ;

   virtual Saver* copy();

   virtual Object* object();

   virtual void object( Object* o ) ;

private:

   Image *_image ;
   std::string _type_name ;

};

#endif