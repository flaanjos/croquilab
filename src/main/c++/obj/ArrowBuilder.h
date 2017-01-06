#pragma once
#ifndef _ARROW_BUILDER__H__
#define _ARROW_BUILDER__H__ 1

#include "twopoint_segmented_builder.h"

class ArrowBuilder : public TwoPointSegmentedBuilder
{
public:
   ArrowBuilder() ;
   ~ArrowBuilder() ;

protected:
   virtual Object *newObject( double x, double y ) ;
};

#endif