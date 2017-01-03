#pragma once
#ifndef _CRYSTAL_BUILDER__H__
#define _CRYSTAL_BUILDER__H__ 1

#include "solid_builder.h"

class CrystalBuilder : public SolidBuilder
{
public:
   CrystalBuilder() ;
   ~CrystalBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif