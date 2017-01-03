#pragma once
#ifndef __WIDE_SEGMENTED_OBJECT__H__
#define __WIDE_SEGMENTED_OBJECT__H__ 2

#include "segmented_object.h"
#include "point2d.h"
#include <vector>


class WideSegmented : public Segmented
{
public:
   WideSegmented( ) ;
   WideSegmented( const Point2d& p1, const Point2d& p2 ) ;
   virtual ~WideSegmented();


   virtual void width( double w ) ;
   virtual const double width() const ;

   virtual void draw( ) const = 0 ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const ;

   virtual Manipulator *manipulator() ;

   Object *copy() = 0 ;

protected:

   double _width ;
} ;

#endif