#pragma once
#ifndef _PITON__
#define _PITON__ 1

#include "solid_object.h"


class Piton : public Solid
{
public:
   Piton() ;
   virtual ~Piton() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void draw( ) const ;
   void drawSelectable( );

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;



};

#endif