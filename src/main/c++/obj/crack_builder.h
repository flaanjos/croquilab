#pragma once
#ifndef _CRACK_BUILDER__H__
#define _CRACK_BUILDER__H__ 1

#include "2point_segmented_builder.h"

class CrackBuilder : public TwoPointSegmentedBuilder
{
public:
   CrackBuilder() ;
   ~CrackBuilder() ;

   virtual Object *newObject( double x, double y ) ;
};

#endif