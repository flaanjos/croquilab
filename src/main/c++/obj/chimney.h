#pragma once
#ifndef _CHIMNEY__
#define _CHIMNEY__ 1

#include "wide_segmented_object.h"
#include "point2d.h"


class Chimney : public WideSegmented
{
public:
   Chimney( const Point2d &a, const Point2d &b );
   virtual ~Chimney() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;   
};

#endif