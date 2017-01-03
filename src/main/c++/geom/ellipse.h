#pragma once
#ifndef __ELLIPSE__H__
#define __ELLIPSE__H__ 1

#include <vector>
#include "point2d.h"

class Ellipse
{
public:
   Ellipse() ;
   ~Ellipse() ;

   void center( const Point2d& p  ) ;

   void width( double w ) ;
   void height( double h ) ;

   void beginAngle( double a ) ;
   void endAngle( double a ) ;

   const Point2d& center( ) const ;

   double width( ) const ;
   double height( ) const ;

   double beginAngle( ) const ;
   double endAngle( ) const ;


   void draw( const Point2d& s, const Point2d& p ) const ;
   void draw(  ) const  ;

private:

   Point2d _center ;
   double  _width ;
   double _height ;
   double _ini_angle ;
   double _end_angle ;
};

#endif