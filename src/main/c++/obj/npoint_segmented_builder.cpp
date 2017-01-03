#include "npoint_segmented_builder.h"
#include "segmented_object.h"

NPointSegmentedBuilder::NPointSegmentedBuilder()
{
      _obj = NULL ;
}
NPointSegmentedBuilder::~NPointSegmentedBuilder()
{
}

Object * NPointSegmentedBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 ) 
   {
      if( !d_click )
      {
         if( !_obj )
         {
            _obj = newObject( x, y ) ;
            return NULL ;
         }
         Segmented *s = (Segmented*)_obj ;
         if( s->numPoints() >0 )
         {
            s->position( s->numPoints()-1, Point2d(x, y) ) ;
            s->addPoint( Point2d(x, y) ) ;
            return NULL ;
         }
      }
      else
      {
         if( _obj )
         {
            Segmented *s = (Segmented*)_obj ;
            s->removePoint( s->numPoints()-1 ) ;
            _obj = 0 ;
            return s ;

         }
      }
   }
   return 0 ;
}; 
void NPointSegmentedBuilder::motion( double x, double y, bool shift, bool control )
{
   if( _obj )
   {
      Segmented *s = (Segmented*)_obj ;
      s->position( s->numPoints()-1, Point2d(x, y) ) ;
   }
};
void NPointSegmentedBuilder::draw() 
{
   if( _obj )
      _obj->draw() ;
};
bool NPointSegmentedBuilder::cancel()
{
   delete _obj ;
   _obj = 0 ;
   return true ;
};

