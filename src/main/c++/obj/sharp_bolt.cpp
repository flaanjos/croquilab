
#include "sharp_bolt.h"
#include "cd.h"
#include "wd.h"

static double SIDE =6.0 ;
static double HALFSIDE =3.3 ;

SharpBolt::SharpBolt()
{
}


SharpBolt::~SharpBolt()
{
};

//const Point2d & SharpBolt::scale( ) const
//{
//   return _scale ;
//} ;
//
//void SharpBolt::scale( const Point2d & s ) 
//{
//   edit( s, _position ) ;
//};

const Point2d & SharpBolt::position( ) const
{
   return _position ;
} ;

void SharpBolt::position( const Point2d & p ) 
{
   _position = p  ;
};

//void SharpBolt::edit( const Point2d & s, const Point2d & p ) 
//{
//   _position = p ;
//   _scale = s ;
//};


//void SharpBolt::draw( const Point2d & s, const Point2d & p ) const
//{
//   double ss[2] ;
//   double pp[2] ;
//
//   ss[0] = _scale._x*s._x ;
//   ss[1] = _scale._y*s._y ;
//
//   pp[0] = _position._x*s._x + p._x ;
//   pp[1] = _position._y*s._y + p._y ;
//
//   cdInteriorStyle( CD_SOLID ) ; 
//   wdBox( pp[0]-ss[0]*2.5f, pp[0]+ss[0]*2.5f,  pp[1]-ss[1]*2.5f, pp[1]+ss[1]*2.5f ) ;
//} ;

void SharpBolt::draw( ) const
{
   cdInteriorStyle( CD_SOLID ) ; 

   // Desenha uma cruz
   //wdBegin( CD_FILL ) ;
   //wdVertex(  _position._x-.5, _position._y+HALFSIDE ) ;
   //wdVertex(  _position._x+.5, _position._y+HALFSIDE ) ;

   //wdVertex(  _position._x+.5, _position._y+.5 ) ;

   //wdVertex(  _position._x+HALFSIDE, _position._y+.5 ) ;
   //wdVertex(  _position._x+HALFSIDE, _position._y-.5 ) ;

   //wdVertex(  _position._x+.5, _position._y-.5 ) ;

   //wdVertex(  _position._x+.5, _position._y-HALFSIDE ) ;
   //wdVertex(  _position._x-.5, _position._y-HALFSIDE ) ;

   //wdVertex(  _position._x-.5, _position._y-.5 ) ;

   //wdVertex(  _position._x-HALFSIDE, _position._y-.5 ) ;
   //wdVertex(  _position._x-HALFSIDE, _position._y+.5 ) ;

   //wdVertex(  _position._x-.5, _position._y+.5 ) ;

   //wdEnd() ;


// Desenha um X
   int RADIUS = 8;
    wdBegin( CD_FILL ) ;
    wdVertex(  _position._x-RADIUS*1.41/4, _position._y-RADIUS*1.41/4+1.3 ) ;
    wdVertex(  _position._x-RADIUS*1.41/4, _position._y-RADIUS*1.41/4 ) ;
    wdVertex(  _position._x-RADIUS*1.41/4+1.3, _position._y-RADIUS*1.41/4 ) ;

    wdVertex(  _position._x+RADIUS*1.41/4, _position._y+RADIUS*1.41/4-1.5 ) ;
    wdVertex(  _position._x+RADIUS*1.41/4, _position._y+RADIUS*1.41/4 ) ;
    wdVertex(  _position._x+RADIUS*1.41/4-1.3, _position._y+RADIUS*1.41/4 ) ;
    wdEnd() ;

    wdBegin( CD_FILL ) ;
    wdVertex(  _position._x-RADIUS*1.41/4, _position._y+RADIUS*1.41/4-1.3 ) ;
    wdVertex(  _position._x-RADIUS*1.41/4, _position._y+RADIUS*1.41/4 ) ;
    wdVertex(  _position._x-RADIUS*1.41/4+1.3, _position._y+RADIUS*1.41/4 ) ;

    wdVertex(  _position._x+RADIUS*1.41/4, _position._y-RADIUS*1.41/4+1.3 ) ;
    wdVertex(  _position._x+RADIUS*1.41/4, _position._y-RADIUS*1.41/4 ) ;
    wdVertex(  _position._x+RADIUS*1.41/4-1.3, _position._y-RADIUS*1.41/4 ) ;
    wdEnd() ;




  // wdBox( _position._x-HALFSIDE, _position._x+HALFSIDE,  _position._y-HALFSIDE, _position._y+HALFSIDE ) ;
 //wdBox( _position._x-_scale._x*2.5f, _position._x+_scale._x*2.5f,  _position._y-_scale._y*2.5f, _position._y+_scale._y*2.5f ) ;
} ;
void SharpBolt::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(HALFSIDE,HALFSIDE);
   max = _position + Point2d(HALFSIDE,HALFSIDE);
};
Object *SharpBolt::copy()
{
   return new SharpBolt( *this ) ;
}
