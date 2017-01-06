#pragma once
#ifndef _TWOPOINTSEGMENT_BUILDER__H__
#define _TWOPOINTSEGMENT_BUILDER__H__ 1

#include "../builder.h"

class TwoPointSegmentedBuilder : public Builder
{
public:
   TwoPointSegmentedBuilder() ;
  virtual ~TwoPointSegmentedBuilder() ;

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ;
   virtual void motion( double x, double y, bool shift, bool control ) ;
   virtual void draw() ;
   virtual bool cancel() ;

protected:
   virtual Object *newObject( double x, double y ) =0 ;

   Object *_obj ;
} ;

#endif
