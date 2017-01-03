#include "route_line_builder.h"
#include "route_line.h"
#include "math.h"
#include "cd.h"
#include "curved_saver.h"
#include "cd.h"
#include "wd.h"

RouteLineBuilder::RouteLineBuilder()
{
   _obj = 0 ;
}
RouteLineBuilder::~RouteLineBuilder()
{
}

Object *RouteLineBuilder::newObject( double x, double y )
{
   RouteLine *d = new RouteLine( Point2d(x, y), Point2d(x, y) ) ;

   CurvedSaver *cs = new CurvedSaver( d, "RouteLine" );
   d->saver( cs );
   return d ;
}

Object * RouteLineBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 ) 
   {
      if( !d_click )
      {
         if( !_obj )
         {
            _obj = newObject( x, y ) ;
            return 0 ;
         }
         Curved *c = (Curved*)_obj ;
         unsigned int n = c->numPoints() ;
         if( n>0 )
         {
            c->addPoint( Point2d(x, y) ) ;
            if( n>1 )
            {
               c->positionPrevScape( c->numPoints()-1, Point2d(x, y) ) ;

               if( n>2 )
               {
                  c->positionAftScape(  c->numPoints()-2, Point2d(x, y)  ) ;
               }
            }
            return 0 ;
         }
      }
      else
      {
         if( _obj )
         {
            Curved *c = (Curved*)_obj ;
            c->removePoint( c->numPoints()-1 ) ;
            _obj = 0 ;
            return c ;

         }
      }
   }
   return 0 ;
}; 
void RouteLineBuilder::motion( double x, double y, bool shift, bool control )
{
   if( _obj )
   {
      Curved *c = (Curved*)_obj ;
      c->position( c->numPoints()-1, Point2d(x, y) ) ;
      c->positionPrevScape( c->numPoints()-1, Point2d(x, y) ) ;


      if( c->numPoints() >= 3 )
      {
         unsigned int i = c->numPoints()-2 ;

         double ratio = 1 ;
         double len = sqrt((c->position(i-1)-c->position(i+1)).squareSize())*3 ;

         if( len >0 )
         {
            double ratio = 1 ;
            ratio = sqrt((c->position(i-1)-c->position(i)).squareSize()) / len  ;
            c->positionPrevScape( i, c->position(i) + (c->position(i-1)-c->position(i+1)) * ratio ) ;

            ratio = sqrt((c->position(i+1)-c->position(i)).squareSize()) / len ;
            c->positionAftScape( i, c->position(i) + (c->position(i+1)-c->position(i-1)) * ratio ) ;
         }
      }
   }
};
void RouteLineBuilder::draw() 
{
   if( _obj ){
      _obj->draw() ;
    Curved *c = (Curved*)_obj ;

    int n = c->numPoints();
    cdTextAlignment( CD_WEST );
    wdVectorCharSize( 10 ) ; 
    cdLineCap( CD_CAPROUND ) ;
    cdLineJoin( CD_ROUND ) ;
    char txt[100];
    sprintf( txt, "%.1f m", (c->length()*.2) ) ;
    cdLineWidth( 1 ) ;
    wdMultiLineVectorText( c->position(n-1)._x+10, c->position(n-1)._y+10, txt ); 
   }
};
bool RouteLineBuilder::cancel()
{
   delete _obj ;
   _obj = 0 ;
   return true ;
};


