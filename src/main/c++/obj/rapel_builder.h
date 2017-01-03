#pragma once
#ifndef _RAPEL_BUILDER__H__
#define _RAPEL_BUILDER__H__ 1

#include "solid_builder.h"

class RapelBuilder : public SolidBuilder
{
public:
   RapelBuilder() ;
   ~RapelBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif