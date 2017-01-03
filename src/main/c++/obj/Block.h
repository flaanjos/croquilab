#pragma once
#ifndef __BLOCK__H__
#define __BLOCK__H__ 2

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "polygon.h"
#include "manipulator.h"


class Block : public Scalable
{
public:
   Block() ;
   virtual ~Block() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable( ) ;


  // virtual Manipulator * manipulator() ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:
   Bezier _face ;
   Polygon _shadow ;

};

#endif