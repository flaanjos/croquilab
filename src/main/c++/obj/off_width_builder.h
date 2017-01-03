#pragma once
#ifndef _OFF_WIDTH_BUILDER__H__
#define _OFF_WIDTH_BUILDER__H__ 1

#include "2point_segmented_builder.h"

class OffWidthBuilder : public TwoPointSegmentedBuilder
{
public:
   OffWidthBuilder() ;
   ~OffWidthBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif