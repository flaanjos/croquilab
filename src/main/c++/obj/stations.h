#pragma once
#ifndef _STATIONS__
#define _STATIONS__ 1

#include "segmented_object.h"
#include "point2d.h"


class Stations : public Segmented
{
public:
   Stations( ) ;
   Stations( const Point2d &a, const Point2d &b ) ;
   virtual ~Stations() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;
   void drawSelectable( ) ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif