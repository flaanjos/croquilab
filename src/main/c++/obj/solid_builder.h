#pragma once
#ifndef _SOLID_BUILDER__H__
#define _SOLID_BUILDER__H__ 1

#include "builder.h"

class SolidBuilder : public Builder
{
public:
   SolidBuilder() ;
   ~SolidBuilder() ; 

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 

protected:
   virtual Object *newObject( double x, double y ) =0 ;
} ;

#endif