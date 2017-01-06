#pragma once
#ifndef __RECTANGLE__H__
#define __RECTANGLE__H__ 1
#include "point2d.h"
class Rectangle 
{
public:
   Rectangle() ;
   virtual ~Rectangle() ;

   virtual const Point2d &min( ) const ;
   virtual void min( const Point2d & p ) ;

   virtual void max( const Point2d & s ) ;
   virtual const Point2d & max( ) const ;

   void draw( const Point2d& s, const Point2d& p ) const ;
   void draw(  ) const  ;

private:

   Point2d _max ;
   Point2d _min ;
};

#endif
