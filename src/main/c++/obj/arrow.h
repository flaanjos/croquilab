#pragma once
#ifndef _ARROW__
#define _ARROW__ 1

#include "segmented_object.h"
#include "point2d.h"


class Arrow : public Segmented
{
public:
   Arrow( const Point2d &a, const Point2d &b );
   virtual ~Arrow() ;

   void draw( const Point2d& s ) const;
   void draw( ) const ;



   Object *copy() ;
};

#endif