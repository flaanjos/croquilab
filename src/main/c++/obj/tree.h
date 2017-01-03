#pragma once
#ifndef _TREE__
#define _TREE__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "polygon.h"


class Tree : public Scalable
{
public:
   Tree() ;
   virtual ~Tree() ;

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

//private:
   Bezier _crown ;
   Bezier _leaves_1 ;
   Bezier _leaves_2 ;
   Bezier _leaves_3 ;
   Polygon _trunk ;

};

#endif