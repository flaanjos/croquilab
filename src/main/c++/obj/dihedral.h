#pragma once
#ifndef __DIHEDRAL__H__
#define __DIHEDRAL__H__ 2

#include "wide_segmented_object.h"
#include "point2d.h"


class Dihedral : public WideSegmented
{
public:
   Dihedral( const Point2d &a, const Point2d &b ) ;
   virtual ~Dihedral() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif