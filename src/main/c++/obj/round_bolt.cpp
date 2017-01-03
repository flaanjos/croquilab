
#include "round_bolt.h"
#include "cd.h"
#include "wd.h"

// para circulo
static double RADIUS = 6.0 ;
static double HALFRADIUS =3 ;

// para X
//static double RADIUS = 8.0 ;
//static double HALFRADIUS =4.0 ;


RoundBolt::RoundBolt()
{
}


RoundBolt::~RoundBolt()
{
};

//const Point2d & RoundBolt::scale( ) const
//{
//   return _scale ;
//} ;
//
//void RoundBolt::scale( const Point2d & s ) 
//{
//   Point2d ss = s ;
//   if( ss._x <= 5.75f/8 )
//   {
//      ss._x = ss._y = 5.75f/8 ;
//   }
//   else if( ss._x > 5.75f/8 )
//   {
//      ss._x = ss._y = 1 ;
//   }
//
//   edit( ss, _position ) ;
//};

const Point2d & RoundBolt::position( ) const
{
   return _position ;
} ;

void RoundBolt::position( const Point2d & p ) 
{
   _position = p ;
};

//void RoundBolt::edit( const Point2d & s, const Point2d & p ) 
//{
//   _position = p ;
//   _scale = s ;
//};


//void RoundBolt::draw( const Point2d & s, const Point2d & p ) const
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
//   wdSector( pp[0], pp[1], 8*ss[0], 8*ss[1], 0.0, 360.0 ) ;
//} ;

void RoundBolt::draw( ) const
{
   cdInteriorStyle( CD_SOLID ) ; //*4
   //wdBegin( CD_FILL ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4, _position._y-RADIUS*1.41/4+1.3 ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4, _position._y-RADIUS*1.41/4 ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4+1.3, _position._y-RADIUS*1.41/4 ) ;
   //
   //wdVertex(  _position._x+RADIUS*1.41/4, _position._y+RADIUS*1.41/4-1.5 ) ;
   //wdVertex(  _position._x+RADIUS*1.41/4, _position._y+RADIUS*1.41/4 ) ;
   //wdVertex(  _position._x+RADIUS*1.41/4-1.3, _position._y+RADIUS*1.41/4 ) ;
   //wdEnd() ;

   //wdBegin( CD_FILL ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4, _position._y+RADIUS*1.41/4-1.3 ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4, _position._y+RADIUS*1.41/4 ) ;
   //wdVertex(  _position._x-RADIUS*1.41/4+1.3, _position._y+RADIUS*1.41/4 ) ;
   //
   //wdVertex(  _position._x+RADIUS*1.41/4, _position._y-RADIUS*1.41/4+1.3 ) ;
   //wdVertex(  _position._x+RADIUS*1.41/4, _position._y-RADIUS*1.41/4 ) ;
   //wdVertex(  _position._x+RADIUS*1.41/4-1.3, _position._y-RADIUS*1.41/4 ) ;
   //wdEnd() ;

   wdSector( _position._x, _position._y, RADIUS, RADIUS, 0.0, 360.0 ) ;
   //wdSector( _position._x, _position._y, 8*_scale._x, 8*_scale._y, 0.0, 360.0 ) ;
} ;

void RoundBolt::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(HALFRADIUS,HALFRADIUS);
   max = _position + Point2d(HALFRADIUS,HALFRADIUS);
};
Object *RoundBolt::copy()
{
   return new RoundBolt( *this ) ;
}
