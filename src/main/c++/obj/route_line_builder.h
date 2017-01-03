#pragma once
#ifndef _ROUTE_LINE_BUILDER__H__
#define _ROUTE_LINE_BUILDER__H__ 1

#include "builder.h"

class RouteLineBuilder : public Builder
{
public:
   RouteLineBuilder() ;
   ~RouteLineBuilder() ;

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual void motion( double x, double y, bool shift, bool control ) ;
   virtual void draw() ;
   virtual bool cancel() ;

protected:
   virtual Object *newObject( double x, double y ) ;

private:
   Object *_obj ;

};

#endif