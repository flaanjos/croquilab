#include "curved_object.h"
#include "curved_manipulator.h"
#include "float.h"


Curved::Curved( ) : _position( 0, 0 ), _min_point( 0, 0 ), _max_point( 0, 0 ), _min_scape( 0, 0 ), _max_scape( 0, 0 ), _min( 0, 0 ), _max( 0, 0 )
{
}


Curved::Curved( const Point2d& p1, const Point2d& p2 ) : _position( 0, 0 ), _min( 0, 0 ), _max( 0, 0 ), _min_point( 0, 0 ), _max_point( 0, 0 ), _min_scape( 0, 0 ), _max_scape( 0, 0 )
{
   _curve.addPoint( 0, p1 ) ;
   _curve.addPoint( 1, p2 ) ;
   recalculateBoundingBox();
   _position = ( _max + _min ) / 2;
}


Curved::~Curved() 
{
}


unsigned int Curved::numPoints( ) const
{
   return (unsigned int)_curve.numPoints() ;
}

double Curved::length(){
   return _curve.lenght();
}


void Curved::addPoint( unsigned int i, const Point2d& p ) 
{
   if( i > _curve.numPoints() )
      return;

   _curve.addPoint( i, p );
   recalculateBoundingBox() ;
   _position = ( _max + _min ) / 2;
}



void Curved::addPoint( const Point2d& p )
{
   int n = (int)_curve.numPoints() ; 
   _curve.addPoint( n,  p);

   updateBoundingBox( _min_point, _max_point, p ) ;
   updateBoundingBox( _min_scape, _max_scape, p ) ;
   estimateBoundingBox();
   _position = ((_max + _min) / 2) ;
}


void Curved::removePoint( unsigned int i )
{
   if( i >= _curve.numPoints() )
      return ;

   _curve.removePoint( i );

   recalculateBoundingBox() ;
   _position = ( _max + _min ) / 2;
}


void Curved::position( const Point2d& p )
{
   Point2d diff = p - position();

   int n = numPoints() ;
   for( int i = 0 ; i < n ; i ++ )
   {
      Point2d pos_i = _curve.pointVal(i) ;
      _curve.editPoint( i, pos_i + diff ) ;

      Point2d prev_i = _curve.prevScapeVal(i) ;
      Point2d aft_i  = _curve.aftScapeVal(i) ;

      _curve.editPointScapes( i, prev_i + diff, aft_i + diff ) ;
   }

   _position  = (_position + diff) ;
   _min = (_min + diff) ;
   _max = (_max + diff) ;
   _min_point = (_min_point + diff) ;
   _max_point = (_max_point + diff) ;
   _min_scape = (_min_scape + diff) ;
   _max_scape = (_max_scape + diff) ;
}


const Point2d& Curved::position( ) const
{
   return _position ;
}


void Curved::position( unsigned int i, const Point2d& p )
{
   if( i >= _curve.numPoints() )
      return ;

   _curve.editPoint( i ,  p);
   recalculatePointBoundingBox() ;
   estimateBoundingBox();
   _position = ( _max + _min ) / 2;
}


const Point2d& Curved::position( unsigned int i ) const
{
   return _curve.pointVal(i) ;
}


void Curved::positionPrevScape( unsigned int i, const Point2d& p )
{
   if( i >= _curve.numPoints() )
      return ;

   _curve.editPointScapes(i, p, _curve.aftScapeVal( i ) ) ;
   recalculateScapeBoundingBox() ;
   estimateBoundingBox();
   _position = ( _max + _min ) / 2;
}


const Point2d& Curved::positionPrevScape( unsigned int i ) const
{
   return _curve.prevScapeVal( i ) ;
}


void Curved::positionAftScape( unsigned int i, const Point2d& p )
{
   if( i >= _curve.numPoints() )
      return ;

   _curve.editPointScapes(i, _curve.prevScapeVal( i ), p ) ;
   recalculateScapeBoundingBox() ;
   estimateBoundingBox();
   _position = ( _max + _min ) / 2;
}


const Point2d& Curved::positionAftScape( unsigned int i ) const 
{
   return _curve.aftScapeVal(i) ;
}


void Curved::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _min ;
   max = _max ;
}


Manipulator *Curved::manipulator()
{
   return CurvedManipulator::instance( this ) ;
}


void Curved::recalculatePointBoundingBox()
{
   _min_point._x = _min_point._y = DBL_MAX;
   _max_point._x = _max_point._y = -DBL_MAX;

   unsigned int n = numPoints();
   for( unsigned int i = 0 ; i < n ; i++ )
   {
      updateBoundingBox( _min_point, _max_point, _curve.pointVal( i ) );
   }
}


void Curved::recalculateScapeBoundingBox()
{
   _min_scape._x = _min_scape._y = DBL_MAX;
   _max_scape._x = _max_scape._y = -DBL_MAX;

   unsigned int n = numPoints();
   for( unsigned int i = 0 ; i < n ; i++ )
   {
      updateBoundingBox( _min_scape, _max_scape, _curve.aftScapeVal( i ) );
      updateBoundingBox( _min_scape, _max_scape, _curve.prevScapeVal( i ) );
   }
}

void Curved::recalculateBoundingBox()
{
   recalculatePointBoundingBox() ;
   recalculateScapeBoundingBox() ;
   estimateBoundingBox();
   _position = ( _max + _min ) / 2;
}

void Curved::estimateBoundingBox()
{
   _min = _min_point ;
   _max = _max_point ;

   if( _min_scape._x < _min_point._x )
   {
      _min._x = _min_scape._x + ((_min_point._x - _min_scape._x) / 4) ;
   }
   if( _min_scape._y < _min_point._y )
   {
      _min._y = _min_scape._y + ((_min_point._y - _min_scape._y) / 4) ;
   }

   if( _max_scape._x > _max_point._x )
   {
      _max._x = _max_scape._x - ((_max_scape._x - _max_point._x) / 4) ;
   }
   if( _max_scape._y > _max_point._y )
   {
      _max._y = _max_scape._y - ((_max_scape._y - _max_point._y) / 4) ;
   }
}







