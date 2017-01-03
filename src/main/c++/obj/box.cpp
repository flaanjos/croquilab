#include "box.h"
#include "cd.h"
#include "wd.h"


Box::Box()
{
};
Box::~Box()
{
};


void Box::position( const Point2d& p  ) 
{
   edit( _scale, p ) ;
}

void Box::scale( const Point2d &s ) 
{
   edit( s, _position ) ;
}

const Point2d& Box::position( ) const
{
   return _position ;
}

const Point2d& Box::scale( )  const
{
   return _scale ;
}

void Box::draw( const Point2d& s, const Point2d& p )  const 
{
   _rectangle.draw(s, p) ;
} ;

void Box::draw(  )  const 
{
   _rectangle.draw(); 
} ;


void Box::edit( const Point2d &s, const Point2d & p ) 
{
   _scale = s ;
   _position = p ;
   _rectangle.min( p-s/2 ) ;
   _rectangle.max( p+s/2 ) ;
}
void Box::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position-_scale/2  ;
   max = _position+_scale/2  ;
};

Object *Box::copy()
{
   return new Box( *this ) ;
}



