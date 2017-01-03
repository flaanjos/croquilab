#pragma once
#ifndef _ROUTE_LINE__
#define _ROUTE_LINE__ 1

#include "curved_object.h"


class RouteLine : public Curved
{
public:
   RouteLine( const Point2d &a, const Point2d &b ) ;
   virtual ~RouteLine() ;

   void draw( const Point2d& s ) const;
   void drawSelectable( ) ;
   void draw( ) const ;

   Object *copy() ;
};

#endif