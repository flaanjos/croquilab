#include "solid_object.h"
#include "solid_manipulator.h"

 Manipulator * Solid::manipulator()
 {
    return SolidManipulator::instance( this ) ;
 }