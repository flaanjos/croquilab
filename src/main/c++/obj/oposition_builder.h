#pragma once
#ifndef _OPOSITION_BUILDER__H__
#define _OPOSITION_BUILDER__H__ 1

#include "two_point_segmented_builder.h"

class OpositionBuilder : public TwoPointSegmentedBuilder
{
public:
   OpositionBuilder() ;
   ~OpositionBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif