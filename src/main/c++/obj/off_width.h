#pragma once
#ifndef _OFF_WIDTH__
#define _OFF_WIDTH__ 1

#include "segmented_object.h"
#include "point2d.h"


class OffWidth : public Segmented
{
public:
   OffWidth( const Point2d &a, const Point2d &b ) ;
   virtual ~OffWidth() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif