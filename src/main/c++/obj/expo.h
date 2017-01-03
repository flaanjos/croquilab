#pragma once
#ifndef __EXPO__H__
#define __EXPO__H__ 2

#include "solid_object.h"
#include "polygon.h"


class Expo : public Solid
{
public:
   Expo() ;
   virtual ~Expo() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   
   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

private:
   Polygon _exclamation_bar ;
   Polygon _exclamation_point ;
   Polygon _letter_e ;
};

#endif