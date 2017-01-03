#include "braces.h"
#include "float.h"

//  Dimension
static const float dim = 12.0f;
//  Dimension/2
static const float dim2= 6.0f;
//  Dimension/4
static const float dim4= 3.0f;

Brace::Brace()  :_scale( 1, 4 ), _position ( 0, 0 )
{
   int i =  0 ;

   _points.addPoint( 0, Point2d(-dim,   -dim  ) ) ;
   _points.addPoint( 1, Point2d( 0.0f,   -dim  ) ) ;
   _points.addPoint( 2, Point2d( dim2, -dim2) ) ;
   _points.addPoint( 3, Point2d( dim2, -dim2) ) ;
   _points.addPoint( 4, Point2d( dim, 0.0f  ) ) ;
   _points.addPoint( 5, Point2d( dim2,  dim2) ) ;
   _points.addPoint( 6, Point2d( dim2,  dim2) ) ;
   _points.addPoint( 7, Point2d( 0.0f,    dim  ) ) ;
   _points.addPoint( 8, Point2d(-dim,    dim  ) ) ;

   _points.editPointScapes( 0, Point2d(-dim,   -dim  ), Point2d(-dim, -dim) ) ;
   _points.editPointScapes( 1, Point2d( 0.0f,   -dim  ), Point2d( dim2, -dim) ) ;
   _points.editPointScapes( 2, Point2d( dim2, -dim  ), Point2d(dim2, -dim2) ) ;
   _points.editPointScapes( 3, Point2d( dim2, -dim2), Point2d(dim2, -dim4) ) ;
   _points.editPointScapes( 4, Point2d( dim4,  0.0f  ), Point2d( dim4, 0.0f) ) ;
   _points.editPointScapes( 5, Point2d( dim2,  dim4  ), Point2d( dim2, dim2) ) ;
   _points.editPointScapes( 6, Point2d( dim2,  dim2), Point2d( dim2, dim) ) ;
   _points.editPointScapes( 7, Point2d( dim2,  dim  ), Point2d( 0.0f,  dim) ) ;
   _points.editPointScapes( 8, Point2d(-dim,    dim  ), Point2d( -dim, dim) ) ;

}

Brace::~Brace()
{
};

const Point2d & Brace::scale( ) const
{
   return _scale ;
} ;

void Brace::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Brace::position( ) const
{
   return _position ;
} ;

void Brace::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Brace::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;

   if( _scale._y<1 )
      _scale._y=1;

   int direction = 1;
   if (_scale._x<0)
      direction = -1;

   //if( _scale._x<1 )
   //{
   //      _scale._x=1 ;
   //}



   _points.editPoint( 0, Point2d(-direction*dim*_scale._x+p._x , -direction*dim*_scale._y+p._y ) ) ;
   _points.editPoint( 1, Point2d( direction*dim*_scale._x+p._x-direction*dim , -direction*dim*_scale._y+p._y ) ) ;
   _points.editPoint( 2, Point2d( direction*dim*_scale._x+p._x-direction*dim2, -direction*dim*_scale._y+p._y+direction*dim2) ) ;
   _points.editPoint( 3, Point2d( direction*dim*_scale._x+p._x-direction*dim2, +p._y-direction*dim2) ) ;
   _points.editPoint( 4, Point2d( direction*dim*_scale._x+p._x , p._y ) ) ;
   _points.editPoint( 5, Point2d( direction*dim*_scale._x+p._x-direction*dim2, p._y+direction*dim2) ) ;
   _points.editPoint( 6, Point2d( direction*dim*_scale._x+p._x-direction*dim2, direction*dim*_scale._y+p._y-direction*dim2) ) ;
   _points.editPoint( 7, Point2d( direction*dim*_scale._x+p._x-direction*dim , direction*dim*_scale._y+p._y ) ) ;
   _points.editPoint( 8, Point2d(-direction*dim*_scale._x+p._x , direction*dim*_scale._y+p._y ) ) ;


   _points.editPointScapes( 0, Point2d(-direction*dim*_scale._x+p._x , -direction*dim*_scale._y+p._y ), Point2d(-direction*dim*_scale._x+p._x , -direction*dim*_scale._y+p._y ) ) ;
   _points.editPointScapes( 1, Point2d( direction*dim*_scale._x+p._x-direction*dim , -direction*dim*_scale._y+p._y ), Point2d( direction*dim*_scale._x+p._x-direction*dim2, -direction*dim*_scale._y+p._y ) ) ;
   _points.editPointScapes( 2, Point2d( direction*dim*_scale._x+p._x-direction*dim2, -direction*dim*_scale._y+p._y ), Point2d( direction*dim*_scale._x+p._x-direction*dim2, -direction*dim*_scale._y+p._y+direction*dim2) ) ;
   _points.editPointScapes( 3, Point2d( direction*dim*_scale._x+p._x-direction*dim2, +p._y-direction*dim2), Point2d( direction*dim*_scale._x+p._x-direction*dim2, p._y-direction*dim4 ) ) ;
   _points.editPointScapes( 4, Point2d( direction*dim*_scale._x+p._x-direction*dim4, p._y ), Point2d( direction*dim*_scale._x+p._x-direction*dim4, p._y ) ) ;
   _points.editPointScapes( 5, Point2d( direction*dim*_scale._x+p._x-direction*dim2, p._y+direction*dim4 ), Point2d( direction*dim*_scale._x+p._x-direction*dim2, p._y+direction*dim2) ) ;
   _points.editPointScapes( 6, Point2d( direction*dim*_scale._x+p._x-direction*dim2, direction*dim*_scale._y+p._y-direction*dim2), Point2d( direction*dim*_scale._x+p._x-direction*dim2, direction*dim*_scale._y+p._y ) ) ;
   _points.editPointScapes( 7, Point2d( direction*dim*_scale._x+p._x-direction*dim2, direction*dim*_scale._y+p._y ), Point2d( direction*dim*_scale._x+p._x-direction*dim , direction*dim*_scale._y+p._y ) ) ;
   _points.editPointScapes( 8, Point2d(-direction*dim*_scale._x+p._x , direction*dim*_scale._y+p._y ), Point2d(-direction*dim*_scale._x+p._x , direction*dim*_scale._y+p._y ) ) ;

   _position = p ;
   _scale = s ;
};

void Brace::draw( const Point2d & s, const Point2d & p )const 
{
 //  _points.draw( s, p ) ;
} ;

void Brace::draw( ) const
{
   _points.draw() ;
} ;

void Brace::boundingBox( Point2d& min, Point2d& max ) const 
{
   min = _position - _scale*dim ;
   max = _position + _scale*dim ;
};


Object *Brace::copy()
{
   return new Brace( *this ) ;
}
