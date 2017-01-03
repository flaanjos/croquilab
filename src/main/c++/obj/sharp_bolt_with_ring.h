#pragma once
#ifndef _SHARP_BOLT_WITH_RING__
#define _SHARP_BOLT_WITH_RING__ 1

#include "solid_object.h"


class SharpBoltWithRing : public Solid
{
public:
   SharpBoltWithRing() ;
   virtual ~SharpBoltWithRing() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   //void scale( const Point2d & s ) ;
   //const Point2d & scale( ) const ;

   //void edit( const Point2d &s, const Point2d & p ) ;

   //void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;



};

#endif