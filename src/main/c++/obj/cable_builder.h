#pragma once
#ifndef _CABLE_BUILDER__H__
#define _CABLE_BUILDER__H__ 1

#include "2point_segmented_builder.h"

class CableBuilder : public TwoPointSegmentedBuilder
{
public:
   CableBuilder() ;
   ~CableBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif