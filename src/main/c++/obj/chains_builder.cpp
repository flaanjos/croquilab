#include "chains_builder.h"
#include "chains.h"
#include "solid_saver.h"

ChainsBuilder::ChainsBuilder()
{
}
ChainsBuilder::~ChainsBuilder()
{
}

Object *ChainsBuilder::newObject( double x, double y )
{
   Point2d p( x, y ) ;
   Chains *sb = new Chains() ;
   sb->position( p ) ;

   SolidSaver *ss = new SolidSaver( sb, "Chains" );
   sb->saver( ss );


   return sb ;
}
