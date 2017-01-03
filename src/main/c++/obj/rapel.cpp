
#include "rapel.h"
#include "cd.h"
#include "wd.h"



Rapel::Rapel() 
{
}


Rapel::~Rapel()
{
};



const Point2d & Rapel::position( ) const
{
   return _position ;
} ;

void Rapel::position( const Point2d & p ) 
{
   _position = p  ;
}



void Rapel::draw( ) const
   {
   cdInteriorStyle( CD_FILL ) ;

   wdSector( _position._x, _position._y, 12.0f, 12.0f, 0.0, 360.0 ) ;
   wdBegin( CD_FILL ) ;
   {
      wdVertex( _position._x, _position._y+6 ) ;
     wdVertex( _position._x-9.0f, _position._y ) ;
     wdVertex( _position._x-9.0f, _position._y-10.0f ) ;
     wdVertex( _position._x-11.0f, _position._y-9.0f ) ;
     wdVertex( _position._x-8.0f, _position._y-15.0f ) ;
     wdVertex( _position._x-5   , _position._y-9.0f ) ;
     wdVertex( _position._x-7.0f, _position._y-10.0f ) ;
     wdVertex( _position._x-7.0f, _position._y-1 ) ;
     
   }
   wdEnd() ;
   long x = cdForeground( CD_WHITE ) ;
   wdSector( _position._x, _position._y, 8.0f, 8.0f, 0.0, 360.0 ) ;
   cdForeground( x ) ;
 }
//{
//   cdInteriorStyle( CD_FILL ) ;
//
//   wdSector( _position._x, _position._y, 12.0f, 12.0f, 0.0, 360.0 ) ;
//   wdBegin( CD_FILL ) ;
//   {
//     wdVertex( _position._x, _position._y-1 ) ;
//     wdVertex( _position._x+12, _position._y-1 ) ;
//     wdVertex( _position._x+12, _position._y-8 ) ;
//     wdVertex( _position._x+10, _position._y-8 ) ;
//     wdVertex( _position._x+13, _position._y-10 ) ;
//     wdVertex( _position._x+16, _position._y-8 ) ;
//     wdVertex( _position._x+14, _position._y-8 ) ;
//     wdVertex( _position._x+14, _position._y+1 ) ;
//     wdVertex( _position._x, _position._y+1 ) ;
//   }
//   wdEnd() ;
//   long x = cdForeground( CD_WHITE ) ;
//   wdSector( _position._x, _position._y, 8.0f, 8.0f, 0.0, 360.0 ) ;
//   cdForeground( x ) ;
// }
//{
//   cdInteriorStyle( CD_FILL ) ;
//
//   wdSector( _position._x, _position._y, 16.0f, 16.0f, 0.0, 360.0 ) ;
//   wdBegin( CD_FILL ) ;
//   {
//     wdVertex( _position._x-8.0f, _position._y ) ;
//     wdVertex( _position._x-8.0f, _position._y-10.0f ) ;
//     wdVertex( _position._x-10.0f, _position._y-9.0f ) ;
//     wdVertex( _position._x-7.0f, _position._y-15.0f ) ;
//     wdVertex( _position._x-4   , _position._y-9.0f ) ;
//     wdVertex( _position._x-6.0f, _position._y-10.0f ) ;
//     wdVertex( _position._x-6.0f, _position._y-1 ) ;
//   }
//   wdEnd() ;
//   long x = cdForeground( CD_WHITE ) ;
//   wdSector( _position._x, _position._y, 12.0f, 12.0f, 0.0, 360.0 ) ;
//   cdForeground( x ) ;
// }



void Rapel::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(10,15);
   max = _position + Point2d(8,8);
}



Object *Rapel::copy()
{
   return new Rapel( *this ) ;
}