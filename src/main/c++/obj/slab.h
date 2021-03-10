#pragma once
#ifndef _SLAB__
#define _SLAB__ 1

#include "segmented_object.h"
#include "point2d.h"
#include <vector>


class Slab : public Segmented
{
public:
   Slab( const Point2d &a, const Point2d &b ) ;
   virtual ~Slab() ;

   void addPoint( const Point2d& p ) ;

   void position( unsigned int i, const Point2d& p ) ;
   const Point2d& position( unsigned int i ) const ;

   void scale( Point2d s ) ;
   const Point2d& scale( ) const;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   unsigned int numPoints() const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

private:
   Point2d _scale ;
   std::vector<Point2d> _points ;
};

#endif