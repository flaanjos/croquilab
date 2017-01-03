#pragma once
#ifndef _TREE_BUILDER__H__
#define _TREE_BUILDER__H__ 1

#include "solid_builder.h"

class TreeBuilder : public SolidBuilder
{
public:
   TreeBuilder() ;
   ~TreeBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif