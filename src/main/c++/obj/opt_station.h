#pragma once
#ifndef _OPT_STATION__
#define _OPT_STATION__ 1

#include "solid_object.h"


class OptStation : public Solid
{
public:
   OptStation() ;
   virtual ~OptStation() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;


};

#endif