#include "segment.h"
#include "cd.h"
#include "wd.h"



Segment::Segment()
{
   _points.clear() ;

};
Segment::~Segment()
{
   _points.clear() ;
};


unsigned int Segment::addPoint( unsigned int i, const Point2d& p  ) 
{
   if( _points.size() < i )
   {
      i = (unsigned int)_points.size() ;
   }

   _points.insert( _points.begin() + i, p ) ;

   return i ;
};


unsigned int Segment::removePoint( unsigned int i )
{
   if( _points.size() <= 0 )
      return 0 ;

   if( _points.size() <= i )
   {
      i = (unsigned int)_points.size()-1 ;
   }

   _points.erase( _points.begin() + i ) ;

   return i ;
};

unsigned int Segment::numPoints() const 
{
   return (unsigned int)_points.size() ;
};

const Point2d& Segment::pointVal( unsigned int i )const
{
   return _points[i] ;
};


unsigned int Segment::editPoint( unsigned int i, const Point2d& p )
{
   if( _points.size() > i )
   {
      _points[i] = p ;
      return true ;
   }
   return false ;
};



void Segment::draw( const Point2d& s, const Point2d& p )  const 
{
   unsigned int n = (unsigned int)_points.size() ;
   wdBegin( CD_OPEN_LINES ) ;
   {
      for( unsigned int i=0 ; i<n; i++ )
      {
         wdVertex( _points[i]._x*s._x+p._x, _points[i]._y*s._x+p._y) ;
      }
   }
   wdEnd() ;
} ;

void Segment::draw(  )  const 
{
   unsigned int n = (unsigned int)_points.size() ;
   wdBegin( CD_OPEN_LINES ) ;
   {
      for( unsigned int i=0 ; i<n; i++ )
      {
         wdVertex( _points[i]._x, _points[i]._y ) ;
      }
   }
   wdEnd() ;
} ;

