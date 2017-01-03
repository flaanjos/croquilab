#pragma once
#ifndef _BUSH_BUILDER__H__
#define _BUSH_BUILDER__H__ 1

#include "solid_builder.h"

class BushBuilder : public SolidBuilder
{
public:
   BushBuilder() ;
   ~BushBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif