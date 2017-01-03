#pragma once
#ifndef _SCREW__
#define _SCREW__ 1

#include "solid_object.h"


class Screw : public Solid
{
public:
   //Screw( const Point2d& position );
   Screw() ;
   virtual ~Screw() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   void drawSelectable() ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;



};

#endif