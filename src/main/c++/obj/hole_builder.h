#pragma once
#ifndef _HOLE_BUILDER__H__
#define _HOLE_BUILDER__H__ 1

#include "solid_builder.h"

class HoleBuilder : public SolidBuilder
{
public:
   HoleBuilder() ;
   ~HoleBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif