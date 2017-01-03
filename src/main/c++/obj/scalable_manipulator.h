#ifndef __SCALABLE_MANIPULATOR___H__
#define __SCALABLE_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "scalable_object.h"

class ScalableManipulator : public Manipulator
{
private:
   ScalableManipulator() ;

public:
   virtual ~ScalableManipulator() {} ;

   static ScalableManipulator* instance( Scalable *s ) ;

   void scalable( Scalable* s ) ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Manipulator::Type motion( double x, double y, bool shift, bool control ) ;
   virtual bool pressKey( int c ) ;
   virtual bool releaseKey( int c ) ;
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

private:
   static ScalableManipulator* _unique ;

   Scalable *_scalable ;
// Saves bouding box to save re-processing
   Point2d _bb_min ;
   Point2d _bb_max ;
   Point2d _bb_mid ;

// For control once manipulation has started
   Manipulator::Type _tp_manipulation ;
   Point2d _start ;
   Point2d _original_pos ;
   Point2d _original_scale ;

   bool _pressed ;
} ;
#endif