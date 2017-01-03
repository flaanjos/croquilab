#include "rectangle.h"
#include "cd.h"
#include "wd.h"


Rectangle::Rectangle() : _max(1,1), _min(0,0)
{
};
Rectangle::~Rectangle()
{
};


void Rectangle::min( const Point2d& p  ) 
{
   _max = p ;
}

void Rectangle::max( const Point2d &p ) 
{
   _min = p ;
}

const Point2d& Rectangle::min( ) const
{
   return _min ;
}

const Point2d& Rectangle::max( )  const
{
   return _max ;
}

void Rectangle::draw( const Point2d& s, const Point2d& p )  const 
{
   cdInteriorStyle( CD_HOLLOW ) ;
   wdBox( _min._x, _max._x, _min._y, _max._y ) ;
} ;

void Rectangle::draw(  )  const 
{
   cdInteriorStyle( CD_HOLLOW ) ;
   wdBox( _min._x, _max._x, _min._y, _max._y ) ;
} ;




