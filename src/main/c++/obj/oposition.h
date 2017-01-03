#pragma once
#ifndef _OPOSITION__
#define _OPOSITION__ 1

#include "segmented_object.h"
#include "point2d.h"


class Oposition : public Segmented
{
public:
   Oposition( const Point2d &a, const Point2d &b ) ;
   virtual ~Oposition() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif