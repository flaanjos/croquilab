#include "elliptical.h"



Elliptical::Elliptical()
{
   _ellipse.center( _position ) ;
   _ellipse.width( _scale._x ) ;
   _ellipse.height( _scale._y)  ;
};
Elliptical::~Elliptical()
{
};


void Elliptical::position( const Point2d& c  ) 
{
   _position = c ;
   _ellipse.center(c) ;
}

void Elliptical::scale( const Point2d &s ) 
{
   _ellipse.width( s._x ) ;
   _ellipse.height( s._y)  ;
   _scale = s ;
}
void Elliptical::beginAngle( double a )
{
   _ellipse.beginAngle( a ) ;
}
void Elliptical::endAngle( double a )
{
   _ellipse.endAngle( a ) ;
}
const Point2d& Elliptical::position( ) const
{
   return _ellipse.center() ;
}

const Point2d& Elliptical::scale( )  const
{
   return _scale ;
}
double Elliptical::beginAngle( )
{
   return _ellipse.beginAngle() ;
}
double Elliptical::endAngle( )
{
   return _ellipse.endAngle() ;
}

void Elliptical::draw( const Point2d& s, const Point2d& p )  const 
{
   _ellipse.draw(s, p) ;
} ;

void Elliptical::draw(  )  const 
{
   _ellipse.draw(); 
} ;


void Elliptical::edit( const Point2d &s, const Point2d & p ) 
{
   scale(s);
   position(p);
}
void Elliptical::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = _ellipse.center()._x - _ellipse.width()/2 ;
   min._y = _ellipse.center()._y - _ellipse.height()/2 ;
   max._x = _ellipse.center()._x + _ellipse.width()/2 ;
   max._y = _ellipse.center()._y + _ellipse.height()/2 ;
};


Object *Elliptical::copy()
{
   return new Elliptical( *this ) ;
}

