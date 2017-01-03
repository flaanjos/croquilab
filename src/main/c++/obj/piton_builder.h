#pragma once
#ifndef _PITON_BUILDER__H__
#define _PITON_BUILDER__H__ 1

#include "solid_builder.h"

class PitonBuilder : public SolidBuilder
{
public:
   PitonBuilder() ;
   ~PitonBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif