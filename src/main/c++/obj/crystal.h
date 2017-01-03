#pragma once
#ifndef __CRYSTAL__H__
#define __CRYSTAL__H__ 2

#include "scalable_object.h"
#include "point2d.h"
#include "segment.h"


class Crystal : public Scalable
{
public:
   Crystal() ;
   virtual ~Crystal() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const;

   Object *copy() ;

private:
   Segment _high_crystal ;
   Segment _low_crystal ;


};

#endif