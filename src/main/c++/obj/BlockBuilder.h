#pragma once
#ifndef _BLOCK_BUILDER__H__
#define _BLOCK_BUILDER__H__ 1

#include "solid_builder.h"

class BlockBuilder : public SolidBuilder
{
public:
   BlockBuilder() ;
   ~BlockBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif