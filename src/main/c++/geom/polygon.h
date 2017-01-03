#pragma once
#ifndef __POLYGON__H__
#define __POLYGON__H__ 1

#include <vector>
#include "point2d.h"

class Polygon
{
public:
   Polygon() ;
   ~Polygon() ;

   unsigned int addPoint( unsigned int i, const Point2d& p  ) ;

   unsigned int removePoint( unsigned int i ) ;

   unsigned int numPoints() const  ;

   const Point2d& pointVal( unsigned int i ) const ;
   unsigned int editPoint( unsigned int i, const Point2d& p  ) ;

   void draw( const Point2d& s, const Point2d& p ) const ;
   void draw(  ) const  ;

   //void bezierPolygon( Line *bez_line ) ;
private:

   std::vector<Point2d> _points ;

};

#endif