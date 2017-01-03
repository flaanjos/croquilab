#pragma once
#ifndef _PALM_TREE__
#define _PALM_TREE__ 1

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "segment.h"
#include "polygon.h"


class PalmTree : public Scalable
{
public:
   PalmTree() ;
   virtual ~PalmTree() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable( );

   void boundingBox( Point2d& min, Point2d& max ) const ;

   virtual Object *copy() ;

//private:
   Bezier _beziers[6] ;
   Segment _segments[16];

};

#endif