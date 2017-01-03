#ifndef __SOLID_MANIPULATOR___H__
#define __SOLID_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "solid_object.h"

class SolidManipulator : public Manipulator
{
private:
   SolidManipulator() ;

public:
   virtual ~SolidManipulator() {} ;

   static SolidManipulator* instance( Solid *b ) ;

   void solid( Solid* s ) ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Manipulator::Type motion( double x, double y, bool shift, bool control ) ;
   virtual bool pressKey( int c ) ;
   virtual bool releaseKey( int c ) ;
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

protected:
   static SolidManipulator* _unique ;
   Solid *_solid ;

private:

// For control once manipulation has started
   Manipulator::Type _tp_manipulation ;
   Point2d _original_pos ;

   bool _pressed ;
} ;
#endif