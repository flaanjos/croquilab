#pragma once
#ifndef __SCALABLE_OBJECT__
#define __SCALABLE_OBJECT__ 1

#include "solid_object.h"
#include "manipulator.h"
#include "point2d.h"

class Scalable : public Solid
{
public:
   Scalable ( ) : _scale(1,1) {};
   virtual ~Scalable( ) { } ;

   virtual const Point2d &position( ) const =0;
   virtual void position( const Point2d & p ) =0;

   virtual void scale( const Point2d & s ) =0;
   virtual const Point2d & scale( ) const =0;

   virtual void edit( const Point2d &s, const Point2d & p ) =0;

   virtual void draw( ) const = 0 ;

   virtual Manipulator * manipulator() ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const =0;

protected:
   Point2d _scale ;
} ;

#endif