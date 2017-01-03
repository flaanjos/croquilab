#pragma once
#ifndef _GRASS__
#define _GRASS__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "segment.h"


class Grass : public Scalable
{
public:
   Grass() ;
   virtual ~Grass() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

//private:
   Segment _segments[8] ;
 
};

#endif