#pragma once
#ifndef _ARETE__
#define _ARETE__ 1

#include "wide_segmented_object.h"
#include "point2d.h"


class Arete : public WideSegmented
{
public:
   Arete( const Point2d &a, const Point2d &b ) ;
   virtual ~Arete() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;
};

#endif