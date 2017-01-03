#include "wide_segmented_object.h"
#include "wide_segmented_manipulator.h"
#include "segmented_manipulator.h"
#include "float.h"


WideSegmented::WideSegmented( ) 
{
   _width = 0 ;
}


WideSegmented::WideSegmented( const Point2d& p1, const Point2d& p2 ) : Segmented( p1, p2 )
{
}


WideSegmented::~WideSegmented() 
{
}


void WideSegmented::width( double w )
{
   _width = w ;
   Point2d min(0,0);
   Point2d max(0,0);
   boundingBox(min, max);
   _position = (min + max) / 2;

}


const double WideSegmented::width( ) const
{
   return _width ;
}

void WideSegmented::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _min._x - _width ;
   max._x = _max._x + _width ;

   min._y = _min._y - _width ;
   max._y = _max._y + _width ;
}


Manipulator *WideSegmented::manipulator()
{
   return WideSegmentedManipulator::instance( this ) ;
}

