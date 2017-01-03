#pragma once
#ifndef __CURVED_OBJECT__H__
#define __CURVED_OBJECT__H__ 2

#include "object.h"
#include "point2d.h"
#include "bezier.h"

class Curved : public Object
{
public:
   Curved( ) ;
   Curved( const Point2d& p1, const Point2d& p2 ) ;
   virtual ~Curved() ;

   virtual unsigned int numPoints( ) const ;

   virtual void addPoint( unsigned int i, const Point2d& p ) ;
   virtual void addPoint( const Point2d& p ) ;
   virtual void removePoint( unsigned int i ) ;

   virtual void position( const Point2d& p ) ;
   virtual const Point2d& position( ) const ;

   virtual void position( unsigned int i, const Point2d& p ) ;
   virtual const Point2d& position( unsigned int i ) const ;

   virtual void positionPrevScape( unsigned int i, const Point2d& p ) ;
   virtual const Point2d& positionPrevScape( unsigned int i ) const ;

   virtual void positionAftScape( unsigned int i, const Point2d& p ) ;
   virtual const Point2d& positionAftScape( unsigned int i ) const ;

   virtual void draw( ) const = 0 ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const ;

   virtual Manipulator *manipulator() ;

   double length();

   Object *copy() = 0 ;

protected:
   virtual void recalculatePointBoundingBox() ;
   virtual void recalculateScapeBoundingBox() ;
   virtual void recalculateBoundingBox() ;
   virtual void estimateBoundingBox();

   Bezier _curve ;
   Point2d _position ;
   Point2d _min ;
   Point2d _max ;
   Point2d _min_point ;
   Point2d _max_point ;
   Point2d _min_scape ;
   Point2d _max_scape ;
};

#endif