#include "dihedral_builder.h"
#include "dihedral.h"
#include "wide_segmented_saver.h"

DihedralBuilder::DihedralBuilder()
{
}
DihedralBuilder::~DihedralBuilder()
{
}

Object *DihedralBuilder::newObject( double x, double y )
{
   Dihedral *d = new Dihedral( Point2d(x, y), Point2d(x, y) ) ;
   WideSegmentedSaver *ss = new WideSegmentedSaver( d, "Dihedral" );
   d->saver( ss );
   return d ;
}

