#pragma once
#ifndef __BOX_OBJECT__H__
#define __BOX_OBJECT__H__ 1

#include <vector>
#include "rectangle.h"
#include "scalable_object.h"


class Box : public Scalable
{
public:
   Box() ;
   ~Box() ;

   virtual const Point2d &position( ) const ;
   virtual void position( const Point2d & p ) ;

   virtual void scale( const Point2d & s ) ;
   virtual const Point2d & scale( ) const ;

   virtual void edit( const Point2d &s, const Point2d & p ) ;


   void draw( const Point2d& s, const Point2d& p ) const ;
   void draw(  ) const  ;

 //  virtual Manipulator* manipulator() ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:

   Rectangle _rectangle ;
};

#endif