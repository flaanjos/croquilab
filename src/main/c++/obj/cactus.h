#pragma once
#ifndef _CACTUS__
#define _CACTUS__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"


class Cactus : public Scalable
{
public:
   Cactus() ;
   virtual ~Cactus() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable( ) ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:
   Bezier _points ;

   int _seed ;
   static int _next_seed ;
};

#endif