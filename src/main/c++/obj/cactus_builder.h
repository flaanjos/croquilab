#pragma once
#ifndef _CACTUS_BUILDER__H__
#define _CACTUS_BUILDER__H__ 1

#include "solid_builder.h"

class CactusBuilder : public SolidBuilder
{
public:
   CactusBuilder() ;
   ~CactusBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif