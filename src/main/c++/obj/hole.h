#pragma once
#ifndef __HOLE__H__
#define __HOLE__H__ 2

#include "scalable_object.h"
#include "point2d.h"

class Hole : public Scalable
{
public:
   Hole() ;
   virtual ~Hole() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable( );

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;


};

#endif