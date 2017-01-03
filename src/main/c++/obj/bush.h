#pragma once
#ifndef _BUSH__
#define _BUSH__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "cd.h"

class Bush : public Scalable
{
public:
   Bush() ;
   virtual ~Bush() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   virtual void drawSelectable() ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

//private:
   Bezier _points ;
   Bezier _leaves_1 ;
   Bezier _leaves_2 ;

};

#endif