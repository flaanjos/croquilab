#pragma once
#ifndef _SCREW_BUILDER__H__
#define _SCREW_BUILDER__H__ 1

#include "solid_builder.h"

class ScrewBuilder : public SolidBuilder
{
public:
   ScrewBuilder() ;
   ~ScrewBuilder() ;

protected:
   virtual Object *newObject( double x, double y );
};

#endif