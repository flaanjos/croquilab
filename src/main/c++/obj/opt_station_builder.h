#pragma once
#ifndef _OPT_STATION_BUILDER__H__
#define _OPT_STATION_BUILDER__H__ 1

#include "solid_builder.h"

class OptStationBuilder : public SolidBuilder
{
public:
   OptStationBuilder() ;
   ~OptStationBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif