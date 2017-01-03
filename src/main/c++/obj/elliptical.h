#pragma once
#ifndef __ELLIPTICAL_OBJECT__H__
#define __ELLIPTICAL_OBJECT__H__ 1

#include "ellipse.h"
#include "scalable_object.h"


class Elliptical : public Scalable
{
public:
   Elliptical() ;
   ~Elliptical() ;

   virtual const Point2d &position( ) const ;
   virtual void position( const Point2d & p ) ;

   virtual void scale( const Point2d & s ) ;
   virtual const Point2d & scale( ) const ;

   virtual void edit( const Point2d &s, const Point2d & p ) ;



   void beginAngle( double a ) ;
   void endAngle( double a ) ;


   double beginAngle( ) ;
   double endAngle( ) ;

   void draw( const Point2d& s, const Point2d& p ) const ;
   void draw(  ) const  ;

 //  virtual Manipulator* manipulator() ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:
  Ellipse _ellipse ;
};

#endif