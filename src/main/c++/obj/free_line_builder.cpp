#include "free_line_builder.h"
#include "route_line.h"
#include "math.h"
#include "curved_saver.h"



FreeLineBuilder::FreeLineBuilder()
{
   _obj = 0 ;
   _pressed = false ;
   _count = 0 ;
}
FreeLineBuilder::~FreeLineBuilder()
{
}

Object *FreeLineBuilder::newObject( double x, double y )
{
   RouteLine *d = new RouteLine( Point2d(x, y), Point2d(x, y) ) ;
   CurvedSaver *ss = new CurvedSaver( d, "FreeLine" );
   d->saver( ss );
   return d ;
}
Object * FreeLineBuilder::releaseButton( int button, double x, double y, bool shift, bool control, bool d_click)  
{
   _pressed = false ;
   return 0 ;
}
Object * FreeLineBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   _pressed = true ;
   _count = 0 ;
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
void FreeLineBuilder::motion( double x, double y, bool shift, bool control )
{
   if( _obj )
   {
      Curved *c = (Curved*)_obj ;
      if( !_pressed ) 
      {
         c->position( c->numPoints()-1, Point2d(x, y) ) ;
         c->positionPrevScape( c->numPoints()-1, Point2d(x, y) ) ;
      }
      else
      {
         if( _count %5== 0)
         {
            c->addPoint( Point2d(x, y) ) ;
         }
         _count ++ ;
      }


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
void FreeLineBuilder::draw() 
{
   if( _obj )
      _obj->draw() ;
};
bool FreeLineBuilder::cancel()
{
   delete _obj ;
   _obj = 0 ;
   return true ;
};


