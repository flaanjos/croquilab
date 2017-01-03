#pragma once
#ifndef _CRACK__
#define _CRACK__ 1

#include "segmented_object.h"
#include "point2d.h"


class Crack : public Segmented
{
public:
   Crack( const Point2d &a, const Point2d &b ) ;
   virtual ~Crack() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif