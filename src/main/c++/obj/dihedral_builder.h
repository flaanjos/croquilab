#pragma once
#ifndef _DIHEDRAL_BUILDER__H__
#define _DIHEDRAL_BUILDER__H__ 1

#include "2point_segmented_builder.h"

class DihedralBuilder : public TwoPointSegmentedBuilder
{
public:
   DihedralBuilder() ;
   ~DihedralBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif