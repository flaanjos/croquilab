#pragma once
#ifndef _BRACE_BUILDER__H__
#define _BRACE_BUILDER__H__ 1

#include "solid_builder.h"

class BraceBuilder : public SolidBuilder
{
public:
   BraceBuilder() ;
   ~BraceBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif