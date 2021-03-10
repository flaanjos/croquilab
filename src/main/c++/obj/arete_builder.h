#pragma once
#ifndef _ARETE_BUILDER__H__
#define _ARETE_BUILDER__H__ 1

#include "twopoint_segmented_builder.h"

class AreteBuilder : public TwoPointSegmentedBuilder
{
public:
   AreteBuilder() ;
   ~AreteBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif