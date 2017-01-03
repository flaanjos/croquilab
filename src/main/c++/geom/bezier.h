#pragma once
#ifndef __BEZIER__H__
#define __BEZIER__H__ 1

#include <vector>
#include "point2d.h"

class Bezier
{
public:
   enum Style
   {
      FILL,
      LINE,
   };

public:
   Bezier() ;
   ~Bezier() ;

   unsigned int addPoint( unsigned int i, const Point2d& p ) ;

   unsigned int removePoint( unsigned int i ) ;

   unsigned int numPoints() const  ;

   const Point2d& pointVal( unsigned int i ) const ;
   unsigned int editPoint( unsigned int i, const Point2d& p  ) ;

   const Point2d &prevScapeVal( unsigned int i ) const ;
   const Point2d &aftScapeVal( unsigned int i ) const ;
   void pointScapesVals( unsigned int i, Point2d& prev, Point2d& aft ) const ;
   unsigned int editPointScapes( unsigned int i, const Point2d& prev, const Point2d& aft ) ;
 
   void draw( const Point2d& s, const Point2d& p, Style style = LINE ) const ;
   void draw( Style style = LINE ) const  ;
   void autoBezier() ;
   void autoBezier( unsigned int i) ;

   double lenght();


   void boundingBox( Point2d& min, Point2d& max ) const ;

private:

   std::vector<Point2d> _aft_scapes ;
   std::vector<Point2d> _prev_scapes ;
   std::vector<Point2d> _points ;

};

#endif