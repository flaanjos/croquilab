#pragma once
#ifndef _CHIMNEY_BUILDER__H__
#define _CHIMNEY_BUILDER__H__ 1

#include "two_point_segmented_builder.h"

class ChimneyBuilder : public TwoPointSegmentedBuilder
{
public:
   ChimneyBuilder() ;
   ~ChimneyBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif