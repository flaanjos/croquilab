#pragma once
#ifndef _FREE_LINE_BUILDER__H__
#define _FREE_LINE_BUILDER__H__ 1

#include "builder.h"

class FreeLineBuilder : public Builder
{
public:
   FreeLineBuilder() ;
   ~FreeLineBuilder() ;

   virtual Object * releaseButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual void motion( double x, double y, bool shift, bool control ) ;
   virtual void draw() ;
   virtual bool cancel() ;

protected:
   virtual Object *newObject( double x, double y ) ;

private:
   Object *_obj ;
   bool _pressed ;
   int _count ;

};

#endif