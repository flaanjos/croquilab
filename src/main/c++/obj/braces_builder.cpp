#include "braces_builder.h"
#include "braces.h"
#include "scalable_saver.h"


BraceBuilder::BraceBuilder()
{
}
BraceBuilder::~BraceBuilder()
{
}

Object *BraceBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Brace *t = new Brace() ;   
   t->position( p ) ;

   ScalableSaver *ss = new ScalableSaver( t, "Brace" );
   t->saver( ss );

   return t ;
}
