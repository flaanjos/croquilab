#pragma once
#ifndef _CABLE__
#define _CABLE__ 1

#include "segmented_object.h"
#include "point2d.h"


class Cable : public Segmented
{
public:
   Cable( const Point2d &a, const Point2d &b ) ;
   virtual ~Cable() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif