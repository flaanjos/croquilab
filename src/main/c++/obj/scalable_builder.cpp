#include "scalable_builder.h"
#include "scalable_object.h"
#include "math.h"

ScalableBuilder::ScalableBuilder() : _ini(0,0)
{
   _obj = 0 ;
}
ScalableBuilder::~ScalableBuilder()
{
}

Object * ScalableBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 && !d_click ) 
   {
      if( !_obj )
      {
         _obj = newObject( x, y ) ;
         _ini = Point2d( x, y ) ;
         return NULL ;
      }
      double dif_x = fabs(_ini._x-x) ;
      double dif_y = fabs(_ini._y-y) ;

      if( control )
      {
         dif_x = dif_y = (dif_x<dif_y)?dif_x:dif_y ;
      }
      Scalable *e = (Scalable*)_obj ;
      if( shift )
      {
         e->scale( Point2d( dif_x,dif_y)*2 ) ;
         e->position( _ini ) ;
      }
      else
      {      
         e->scale( Point2d( dif_x,dif_y) ) ;
         if( _ini._x-x > 0 )
         {
            dif_x = -dif_x ;
         }
         if( _ini._y-y > 0 )
         {
            dif_y = -dif_y ;
         }

         e->position( (Point2d( dif_x, dif_y) + _ini+ _ini)/2 ) ;
      }
      _obj = 0 ;
      return e ;
   }
   return 0 ;
}; 
void ScalableBuilder::motion( double x, double y, bool shift, bool control )
{
   if( _obj )
   {
      double dif_x = fabs(_ini._x-x) ;
      double dif_y = fabs(_ini._y-y) ;

      if( control )
      {
         dif_x = dif_y = (dif_x<dif_y)?dif_x:dif_y ;
      }
      Scalable *e = (Scalable*)_obj ;
      if( shift )
      {
         e->scale( Point2d( dif_x,dif_y)*2 ) ;
         e->position( _ini ) ;
      }
      else
      {      
         e->scale( Point2d( dif_x,dif_y) ) ;
         if( _ini._x-x > 0 )
         {
            dif_x = -dif_x ;
         }
         if( _ini._y-y > 0 )
         {
            dif_y = -dif_y ;
         }

         e->position( (Point2d( dif_x, dif_y) + _ini+ _ini)/2 ) ;
      }
   }
};
void ScalableBuilder::draw() 
{
   if( _obj )
      _obj->draw() ;
};
bool ScalableBuilder::cancel()
{
   delete _obj ;
   _obj = 0 ;
   return true ;
};