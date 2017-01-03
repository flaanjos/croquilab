#ifndef _OBJECT_BUILDER__H__
#define _OBJECT_BUILDER__H__ 1
#include "object.h"

class Builder
{
public:
   Builder() {} ;
   virtual ~Builder() {} ;

   virtual Object * pressButton( int button, double x, double y, bool shift, bool control, bool d_click) {return NULL ;}; 
   virtual Object * releaseButton( int button, double x, double y, bool shift, bool control, bool d_click) {return NULL ;}; 
   virtual void motion( double x, double y, bool shift, bool control ) {};
   virtual Object * pressKey( int c ) {return NULL ;};
   virtual Object * releaseKey( int c ) {return NULL ;};
   virtual void draw() {} ;
   virtual bool cancel() {return false ;};


   //long int color() const {return _color ;};
   //void color( long int c ) {_color = c ;} ;
   //long int lineSize() const {return _line_size ;};
   //void lineSize( long int ls ) {_line_size = ls ;} ;
   //long int lineType() const {return _line_type ;};
   //void lineType( long int lt ) {_line_type = lt ;} ;

protected:
   virtual Object *newObject( double x, double y ) =0 ;

};

#endif
