#pragma once
#ifndef __SOLID_OBJECT__
#define __SOLID_OBJECT__ 1

#include "object.h"
#include "manipulator.h"
#include "point2d.h"

class Solid : public Object
{
public:
   Solid ( )  : _position(0,0) {};
   virtual ~Solid( ) { } ;

   virtual const Point2d &position( ) const = 0 ;
   virtual void position( const Point2d & p ) = 0 ;

   virtual void draw( ) const = 0 ;

   virtual Manipulator * manipulator() ;
   virtual void boundingBox( Point2d& min, Point2d& max ) const = 0 ;

protected:
   Point2d _position;
} ;

#endif