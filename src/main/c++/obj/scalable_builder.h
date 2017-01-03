#pragma once
#ifndef _SCALABLE_BUILDER__H__
#define _SCALABLE_BUILDER__H__ 1

#include "builder.h"
#include "point2d.h"
class ScalableBuilder : public Builder
{
public:
   ScalableBuilder() ;
   ~ScalableBuilder() ; 

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual void motion( double x, double y, bool shift, bool control ) ;
   virtual void draw() ;
   virtual bool cancel() ;

protected:
   virtual Object *newObject( double x, double y ) =0;

   Point2d _ini ;
   Object *_obj ;
} ;

#endif