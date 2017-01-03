#pragma once
#ifndef _SHARP_BOLT_BUILDER__H__
#define _SHARP_BOLT_BUILDER__H__ 1

#include "solid_builder.h"

class SharpBoltBuilder : public SolidBuilder
{
public:
   SharpBoltBuilder() ;
   ~SharpBoltBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif