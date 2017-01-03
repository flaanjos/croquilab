#pragma once
#ifndef _TEXT_BUILDER__H__
#define _TEXT_BUILDER__H__ 1

#include "builder.h"

class TextBuilder : public Builder
{
public:
   TextBuilder() ;
   ~TextBuilder() ;


   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Object * releaseButton( int button, double x, double y, bool shift, bool control, bool d_click) {return 0 ;}; 
   virtual void motion( double x, double y ) {};
   virtual Object * pressKey( int c ) {return 0 ;};
   virtual Object * releaseKey( int c ) {return 0 ;};
   virtual void draw() {} ;
   virtual bool cancel() {return false ;};

protected:
   virtual Object *newObject( double x, double y )  ;

private:
   Object *_obj ;
};
#endif