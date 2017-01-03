#pragma once
#ifndef _BOX_BUILDER__H__
#define _BOX_BUILDER__H__ 1

#include "scalable_builder.h"

class BoxBuilder : public ScalableBuilder
{
public:
   BoxBuilder() ;
   ~BoxBuilder() ; 

protected:
   virtual Object *newObject( double x, double y ) ;
} ;

#endif