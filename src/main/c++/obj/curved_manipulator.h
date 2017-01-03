#ifndef __CURVED_MANIPULATOR___H__
#define __CURVED_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "curved_object.h"

class CurvedManipulator : public Manipulator
{
public:
   static CurvedManipulator* instance( Curved *b ) ;

   Manipulator::Type type( double x, double y ) const ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click); 
   virtual Type motion( double x, double y, bool shift, bool control ) ;
   virtual bool pressKey( int c ) ;
   virtual bool releaseKey( int c ) ;
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

   void curved( Curved* b ) ;



private:
   CurvedManipulator( ) ;
public:
   virtual ~CurvedManipulator() {} ;

private:
   static CurvedManipulator* _unique ;

   enum TYPE_SELECTED_POINT
   {
      PREV,
      AFT,
      MAIN
   } ;

   Curved *_curved ;
// Saves bouding box to save re-processing
   Point2d _bb_min ;
   Point2d _bb_max ;
   Point2d _bb_mid ;

// For control once manipulation has started
   unsigned int _selected_index ;
   TYPE_SELECTED_POINT _type_selected ;
   Manipulator::Type _tp_manipulation ;

   Point2d _start ;

   Point2d _new_pos ;
   Point2d _original_scale ;

   bool _pressed ;
   bool _manipulating ;
} ;
#endif