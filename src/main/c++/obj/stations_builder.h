#pragma once
#ifndef _STATIONS_BUILDER__H__
#define _STATIONS_BUILDER__H__ 1

#include "npoint_segmented_builder.h"

class StationsBuilder : public NPointSegmentedBuilder
{
public:
   StationsBuilder() ;
   ~StationsBuilder() ;

   virtual void draw()  ;

protected:
   virtual Object *newObject( double x, double y ) ;
};

#endif