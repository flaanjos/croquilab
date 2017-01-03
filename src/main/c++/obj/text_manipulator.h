#ifndef __TEXT_MANIPULATOR___H__
#define __TEXT_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "text.h"

class TextManipulator : public Manipulator
{
public:
   static TextManipulator* instance( Text *t ) ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Manipulator::Type motion( double x, double y, bool shift, bool control ) ;
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

   void text( Text* b ) ;

   bool doubleClick( double x, double y );



private:
   TextManipulator( ) ;
public:
   virtual ~TextManipulator() {} ;

private:
   static TextManipulator* _unique ;

   Text *_text ;

// For control once manipulation has started
   Manipulator::Type _tp_manipulation ;
   Point2d _start ;
   Point2d _original_pos ;

   bool _manipulating ;
   bool _motion;
} ;
#endif