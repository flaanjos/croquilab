#pragma once
#ifndef _SHARP_BOLT_WITH_RING_BUILDER__H__
#define _SHARP_BOLT_WITH_RING_BUILDER__H__ 1

#include "solid_builder.h"

class SharpBoltWithRingBuilder : public SolidBuilder
{
public:
   SharpBoltWithRingBuilder() ;
   ~SharpBoltWithRingBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif