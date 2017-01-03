#pragma once
#ifndef _ROUND_BOLT__
#define _ROUND_BOLT__ 1

#include "solid_object.h"


class RoundBolt : public Solid
{
public:
   RoundBolt() ;
   virtual ~RoundBolt() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

  // void scale( const Point2d & s ) ;
   //const Point2d & scale( ) const ;

 //  void edit( const Point2d &s, const Point2d & p ) ;

   //void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;

      void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;

};

#endif