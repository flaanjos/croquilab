#pragma once
#ifndef _EXPO__
#define _EXPO__ 1

#include "solid_object.h"


class Expo : public Solid
{
public:
   Expo() ;
   virtual ~Expo() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   
   void boundingBox( Point2d& min, Point2d& max ) const ;

private:

   Point2d _position ;

};

#endif