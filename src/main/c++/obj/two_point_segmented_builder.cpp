#include "two_point_segmented_builder.h"

#include "segmented_object.h"

TwoPointSegmentedBuilder::TwoPointSegmentedBuilder()
{
   _obj = NULL ;
}
TwoPointSegmentedBuilder::~TwoPointSegmentedBuilder()
{
}

Object * TwoPointSegmentedBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 && !d_click ) 
   {
      if( !_obj )
      {
         _obj = newObject( x, y ) ;
         return NULL ;
      }
      Segmented *s = (Segmented*)_obj ;
      if( s->numPoints() == 2 )
      {
         s->position( 1, Point2d(x, y) ) ;
         _obj = NULL ;
         return s ;
      }
   }
   return NULL ;
}; 
void TwoPointSegmentedBuilder::motion( double x, double y, bool shift, bool control )
{
   if( _obj )
   {
      Segmented *s = (Segmented*)_obj ;
      s->position( 1, Point2d(x, y) ) ;
   }
};
void TwoPointSegmentedBuilder::draw() 
{
   if( _obj )
      _obj->draw() ;
};
bool TwoPointSegmentedBuilder::cancel()
{
   delete _obj ;
   _obj = NULL ;
   return true ;
};

