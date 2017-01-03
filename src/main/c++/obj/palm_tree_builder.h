#pragma once
#ifndef _PALM_TREE_BUILDER__H__
#define _PALM_TREE_BUILDER__H__ 1

#include "solid_builder.h"

class PalmTreeBuilder : public SolidBuilder
{
public:
   PalmTreeBuilder() ;
   ~PalmTreeBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif