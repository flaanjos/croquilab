#pragma once
#ifndef _CHAINS_BUILDER__H__
#define _CHAINS_BUILDER__H__ 1

#include "solid_builder.h"

class ChainsBuilder : public SolidBuilder
{
public:
   ChainsBuilder() ;
   ~ChainsBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif