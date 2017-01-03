#ifndef __LIST_MANIPULATOR___H__
#define __LIST_MANIPULATOR___H__ 3

#include "manipulator.h"
#include "point2d.h"
#include "scalable_object.h"
#include <vector>
#include "group.h"

class ListManipulator : public Manipulator
{
private:
   ListManipulator() ;

public:
   virtual ~ListManipulator() {} ;

   static ListManipulator* instance( std::vector<Object*> list ) ;

   void restart() ;

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Manipulator::Type motion( double x, double y, bool shift, bool control ) ;
   virtual bool pressKey( int c ) ;
   virtual bool releaseKey( int c ) ;
   virtual void draw() const ;
   virtual bool cancel() ;
   virtual bool manipulating() const ;

private:
   static ListManipulator* _unique ;

   Group _group;

// Saves bouding box to save re-processing
   Point2d _bb_min ;
   Point2d _bb_max ;
   Point2d _bb_mid ;

// For control once manipulation has started
   Manipulator::Type _tp_manipulation ;
   Point2d _start ;
   Point2d _original_pos ;
   Point2d _original_scale ;
   
   std::vector< Point2d > _new_ps ;
   std::vector< Point2d > _old_ps ;
   std::vector< Point2d > _new_ss ;
   std::vector< Point2d > _old_ss ;


   bool _pressed ;
} ;
#endif