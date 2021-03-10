#pragma once
#ifndef __TEXT__H__
#define __TEXT__H__ 2

#include "solid_object.h"
#include "point2d.h"
#include "manipulator.h"
#include <string>

class Text : public Solid
{
public:
   Text() ;
   virtual ~Text() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

  // void scale( const Point2d & s ) ;
  // const Point2d & scale( ) const ;

  // void edit( const Point2d &s, const Point2d & p ) ;

  // void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   virtual void drawSelectable() ;

   virtual Manipulator * manipulator() ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   const std::string &text() ;
   void text( const std::string& t ) ;

   Object *copy() ;

   void size( int size) { _size = size; };
   int  size( ) { return _size; };

private:
    int _size;
   std::string _text ;
};

#endif