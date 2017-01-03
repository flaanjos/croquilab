#pragma once
#ifndef _EXPO_BUILDER__H__
#define _EXPO_BUILDER__H__ 1

#include "solid_builder.h"

class ExpoBuilder : public SolidBuilder
{
public:
   ExpoBuilder() ;
   ~ExpoBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif 