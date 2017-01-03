#pragma once
#ifndef _BRACE__
#define _BRACE__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"


class Brace : public Scalable
{
public:
   Brace() ;
   virtual ~Brace() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:
   Bezier _points ;
   Point2d _scale ;
   Point2d _position ;
};

#endif