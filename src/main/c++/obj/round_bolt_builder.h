#pragma once
#ifndef _ROUND_BOLT_BUILDER__H__
#define _ROUND_BOLT_BUILDER__H__ 1

#include "solid_builder.h"

class RoundBoltBuilder : public SolidBuilder
{
public:
   RoundBoltBuilder() ;
   ~RoundBoltBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif