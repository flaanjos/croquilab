#pragma once
#ifndef _POLYGONAL_BUILDER__H__
#define _POLYGONAL_BUILDER__H__ 1

#include "npoint_segmented_builder.h"

class PolygonalBuilder : public NPointSegmentedBuilder
{
public:
   PolygonalBuilder() ;
   ~PolygonalBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif