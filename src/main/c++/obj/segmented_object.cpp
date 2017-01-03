#include "segmented_object.h"
#include "segmented_manipulator.h"
#include "float.h"


Segmented::Segmented( ) : _position( 0, 0 ), _min( 0, 0 ), _max( 0, 0 )
{
}


Segmented::Segmented( const Point2d& p1, const Point2d& p2 ) : _position( 0, 0 ), _min( 0, 0 ), _max( 0, 0 )
{
   _points.push_back( p1 ) ;
   _points.push_back( p2 ) ;
   recalculateBoundingBox( ) ;
 //  _position = ( _max + _min )/ 2 ;
}


Segmented::~Segmented() 
{
   _points.clear();
}


unsigned int Segmented::numPoints( ) const
{
   return (unsigned int)_points.size() ;
}


void Segmented::addPoint( unsigned int i, const Point2d& p ) 
{
   if( i > _points.size() )
      return;

   _points.insert( _points.begin() + i, p );
   updateBoundingBox( _min, _max, p );
  _position = ( _max + _min )/ 2 ;
}


void Segmented::addPoint( const Point2d& p )
{
   _points.push_back( p ) ;

   if( _points.size() == 1 )
   {
      _min = p;
      _max = p;
   }
   else
   {
      updateBoundingBox( _min, _max, p ) ;
   }
   _position = ((_max + _min) / 2) ;
}


void Segmented::removePoint( unsigned int i )
{
   if( i >= _points.size() )
      return ;

   _points.erase( _points.begin() + i ) ;

   recalculateBoundingBox() ;
 // _position = ((_max + _min) / 2) ;
}


void Segmented::position( const Point2d& p )
{
   Point2d diff = p - position();

   int n = numPoints() ;
   for( int i = 0 ; i < n ; i ++ )
   {
      Point2d pos_i = _points[i]  ;
      _points[i] = pos_i + diff ;
   }
   _position  = (_position + diff) ;
   _min = (_min + diff) ;
   _max = (_max + diff) ;
}


const Point2d& Segmented::position( ) const
{
   return _position ;
}


void Segmented::position( unsigned int i, const Point2d& p )
{
   if( i >= _points.size() )
      return ;

   _points[i] = p ;
   recalculateBoundingBox() ;
 //  _position = ((_max + _min) / 2) ;
}


const Point2d& Segmented::position( unsigned int i ) const
{
   return _points[i] ;
}


void Segmented::boundingBox( Point2d& min, Point2d& max ) const
{
   min = _min ;
   max = _max ;
}


Manipulator *Segmented::manipulator()
{
   return SegmentedManipulator::instance( this ) ;
}


void Segmented::recalculateBoundingBox()
{
   _min._x = _min._y = DBL_MAX;
   _max._x = _max._y = -DBL_MAX;

   for( unsigned int i = 0 ; i< _points.size() ;i ++ )
   {
      updateBoundingBox( _min, _max, _points[i] );
   }
   _position = ((_max + _min) / 2) ;
}