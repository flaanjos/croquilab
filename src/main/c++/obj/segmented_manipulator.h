#ifndef __SEGMENTED_MANIPULATOR___H__
#define __SEGMENTED_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "segmented_object.h"

class SegmentedManipulator : public Manipulator
{
public:
   static SegmentedManipulator* instance( Segmented *b ) ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click); 
   virtual Type motion( double x, double y, bool shift, bool control ) ;
   virtual bool pressKey( int c ) ;
   virtual bool releaseKey( int c ) {return false ;};
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

   void segmented( Segmented* b ) ;



private:
   SegmentedManipulator( ) ;
public:
   virtual ~SegmentedManipulator() {} ;

private:
   static SegmentedManipulator* _unique ;

   Segmented *_segmented ;
// Saves bouding box to save re-processing
   Point2d _bb_min ;
   Point2d _bb_max ;
   Point2d _bb_mid ;

// For control once manipulation has started
   unsigned int _selected_index ;
   Manipulator::Type _tp_manipulation ;
   Point2d _start ;
   Point2d _new_pos ;
   Point2d _original_scale ;

   bool _pressed ;
   bool _manipulating ;
} ;
#endif