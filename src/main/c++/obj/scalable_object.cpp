#include "scalable_object.h"
#include "scalable_manipulator.h"


 Manipulator * Scalable::manipulator()
 {
    return ScalableManipulator::instance( this ) ;
 }