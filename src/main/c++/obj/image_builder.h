#pragma once
#ifndef _IMAGE_BUILDER__H__
#define _IMAGE_BUILDER__H__ 1

#include "solid_builder.h"

class ImageBuilder : public SolidBuilder
{
public:
   ImageBuilder() ;
   ~ImageBuilder() ;

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 

protected:
   virtual Object *newObject( double x, double y )  ;
};

#endif