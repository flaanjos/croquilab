#include "bg_image_builder.h"
#include "bg_image.h"
#include "image_saver.h"

BgImageBuilder::BgImageBuilder( imFile *file )
{
}
BgImageBuilder::~BgImageBuilder()
{
}

Object *BgImageBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   BgImage *b = new BgImage() ;
   b->position( p ) ;
   return b ;
}

bool BgImageBuilder::finished( Object *o )
{
   return true ;
}
bool BgImageBuilder::addPoint( Object *o, double x, double y )
{
   return false ;
}
bool BgImageBuilder::moveLastPoint( Object *o, double x, double y )
{
   Point2d p( x, y ) ;
   BgImage *b = (BgImage*)o ;
   b->position( p ) ;
   return true ;
}



