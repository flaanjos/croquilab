
#include "sharp_bolt_with_ring.h"
#include "cd.h"
#include "wd.h"

static double SIDE =6.0 ;
static double HALFSIDE =3.3 ;

SharpBoltWithRing::SharpBoltWithRing()
{
}


SharpBoltWithRing::~SharpBoltWithRing()
{
};


const Point2d & SharpBoltWithRing::position( ) const
{
   return _position ;
} ;

void SharpBoltWithRing::position( const Point2d & p ) 
{
   _position = p  ;
};


void SharpBoltWithRing::draw( ) const
{
   double RADIUS = 8;

   // Desenha um X

    cdInteriorStyle( CD_SOLID ) ; 
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

   // Desenha um O
    cdLineWidth( 2 );
   cdInteriorStyle( CD_HOLLOW ) ; 
   wdSector( _position._x, _position._y-RADIUS/2, RADIUS*3/4, RADIUS*3/4, 0, 360 );
} ;

void SharpBoltWithRing::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _position - Point2d(HALFSIDE,HALFSIDE);
   max = _position + Point2d(HALFSIDE,HALFSIDE);
};
Object *SharpBoltWithRing::copy()
{
   return new SharpBoltWithRing( *this ) ;
}
