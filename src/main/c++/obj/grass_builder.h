#pragma once
#ifndef _GRASS_BUILDER__H__
#define _GRASS_BUILDER__H__ 1

#include "solid_builder.h"

class GrassBuilder : public SolidBuilder
{
public:
   GrassBuilder() ;
   ~GrassBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif