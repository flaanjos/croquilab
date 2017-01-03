#pragma once
#ifndef _POLYGONAL__
#define _POLYGONAL__ 1

#include "segmented_object.h"


class Polygonal : public Segmented
{
public:
   Polygonal( const Point2d &a, const Point2d &b ) ;
   virtual ~Polygonal() ;
   
   void draw( const Point2d& s ) const;
   virtual void draw( ) const ;

   Object *copy() ;
} ;


#endif