#pragma once
#ifndef _PINE_TREE_BUILDER__H__
#define _PINE_TREE_BUILDER__H__ 1

#include "solid_builder.h"

class PineTreeBuilder : public SolidBuilder
{
public:
   PineTreeBuilder() ;
   ~PineTreeBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif