#pragma once
#ifndef _PINE_TREE__
#define _PINE_TREE__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "polygon.h"


class PineTree : public Scalable
{
public:
   PineTree() ;
   virtual ~PineTree() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable( ) ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   virtual Object *copy() ;

private:

   Bezier _trunk ;
   Bezier _bottom_crown ;  
   Bezier _mid_bottom_crown ;
   Bezier _mid_top_crown ;
   Bezier _top_crown ;

   Point2d _min ;
   Point2d _max ;
};


#endif