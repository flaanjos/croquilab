#pragma once
#ifndef _RAPEL__
#define _RAPEL__ 1

#include "solid_object.h"


class Rapel : public Solid
{
public:
   Rapel() ;
   virtual ~Rapel() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;



};

#endif