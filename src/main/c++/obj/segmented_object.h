#pragma once
#ifndef __SEGMENTED_OBJECT__H__
#define __SEGMENTED_OBJECT__H__ 2

#include "object.h"
#include "point2d.h"
#include <vector>


class Segmented : public Object
{
public:
   Segmented( ) ;
   Segmented( const Point2d& p1, const Point2d& p2 ) ;
   virtual ~Segmented();

   virtual unsigned int numPoints( ) const ;

   virtual void addPoint( unsigned int i, const Point2d& p ) ;
   virtual void addPoint( const Point2d& p ) ;
   virtual void removePoint( unsigned int i ) ;

   virtual void position( const Point2d& p ) ;
   virtual const Point2d& position( ) const ;

   virtual void position( unsigned int i, const Point2d& p ) ;
   virtual const Point2d& position( unsigned int i ) const ;

   virtual void draw( ) const = 0 ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const ;

   virtual Manipulator *manipulator() ;

   Object *copy() = 0 ;

protected:

   virtual void recalculateBoundingBox() ;

   std::vector<Point2d> _points ;
   Point2d _position ;
   Point2d _min ;
   Point2d _max ;
} ;

#endif