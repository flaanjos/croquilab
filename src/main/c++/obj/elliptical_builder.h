#pragma once
#ifndef _ELLIPTICAL_BUILDER__H__
#define _ELLIPTICAL_BUILDER__H__ 1

#include "scalable_builder.h"


class EllipticalBuilder : public ScalableBuilder
{
public:
   EllipticalBuilder() ;
   ~EllipticalBuilder() ; 


protected:
   virtual Object *newObject( double x, double y ) ;


} ;

#endif