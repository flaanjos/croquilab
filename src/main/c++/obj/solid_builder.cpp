#include "solid_builder.h"
#include "solid_object.h"

SolidBuilder::SolidBuilder()
{
}
SolidBuilder::~SolidBuilder()
{
}

Object * SolidBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 && !d_click ) 
   {
     return newObject( x, y ) ;
   }
   return 0 ;
}; 