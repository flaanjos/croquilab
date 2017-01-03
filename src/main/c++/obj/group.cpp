#include <vector>
#include "scalable_manipulator.h"
#include "point2d.h"
#include "group.h"
#include "float.h"


Group::Group ( ) 
{
}


Group::Group( std::vector< Object*> children )
{
   _children = children ;
}


Group::Group( const Group& grp )
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children.push_back( (grp._children[o])->copy() ) ;
   }
}


Group::~Group( ) 
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      delete _children[o] ;
   }
   _children.clear() ;
}


void Group::draw()  const
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children[o]->draw() ;
   }
}


void Group::drawSelectable() 
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children[o]->drawSelectable() ;
   }
}


long int Group::color() const 
{
   long int c = -1 ;

   if( _children.size() >= 1 )
   {
      c = _children[0]->color() ;
   }

   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      if( _children[o]->color() != c )
      {
         return -1 ;
      }
   }
   return c ;
}


void Group::color( long int c )
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children[o]->color( c ) ;
   }
}


long int Group::lineSize() const
{
   long int ls = -1 ;

   if( _children.size() >= 1 )
   {
      ls = _children[0]->lineSize() ;
   }

   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      if( _children[o]->lineSize() != ls )
      {
         return -1 ;
      }
   }
   return ls ;
}


void Group::lineSize( long int ls ) 
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children[o]->lineSize( ls ) ;
   }
}


long int Group::lineType() const 
{
   long int lt = -1 ;

   if( _children.size() >= 1 )
   {
      lt = _children[0]->lineType() ;
   }

   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      if( _children[o]->lineType() != lt )
      {
         return -1 ;
      }
   }
   return lt ;
}


void Group::lineType( long int lt ) 
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      _children[o]->lineType( lt ) ;
   }
}


void Group::position( const Point2d& p )
{
   Point2d diff = p - _position;

   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      Point2d pos_i = _children[o]->position() ;
      _children[o]->position( pos_i + diff ) ;
   }
   _position = p ;
}


const Point2d& Group::position( ) const
{
   return _position ;
}


void Group::scale( const Point2d& s )
{
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      Point2d scale_i = _children[o]->scale() ;
      Point2d new_scale( scale_i._x * s._x/_temp_scale._x, scale_i._y * s._y/_temp_scale._y );
      _children[o]->scale( new_scale ) ;

      Point2d diffPos = _children[o]->position() - _position;
      diffPos._x = diffPos._x * s._x / _temp_scale._x;
      diffPos._y = diffPos._y * s._y / _temp_scale._y;

      diffPos = diffPos + _position;
      _children[o]->position( diffPos ) ;
   }   
   _temp_scale = s;
}

void Group::edit( const Point2d& s, const Point2d& p )
{
scale( s );
position( p );
}

 Manipulator * Group::manipulator()
 {
    return ScalableManipulator::instance( this ) ;
 }

void Group::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y =  DBL_MAX ;
   max._x = max._y = -DBL_MAX ;

   Point2d children_min( DBL_MAX, DBL_MAX ) ;
   Point2d children_max( -DBL_MAX, -DBL_MAX ) ;

   for( unsigned int o = 0 ; o < _children.size() ; o++ )
   {
      _children[o]->boundingBox( children_min, children_max ) ;
      updateBoundingBox( min, max, children_min );
      updateBoundingBox( min, max, children_max );
   }
}



void Group::addObject( Object* o )
{
   _children.push_back( o );

   Point2d min( 0, 0 ) ;
   Point2d max( 0, 0 ) ;

   boundingBox( min, max ) ;

   _position = ( min + max ) / 2 ;
}


unsigned int Group::numObjects( ) const
{
   return _children.size() ;
}


Object* Group::object( unsigned int i)
{
   return _children[i] ;
}










Object* Group::copy() 
{
   Group *g = new Group() ;
   for( unsigned int o=0 ; o<_children.size() ; o++ )
   {
      g->addObject( _children[o]->copy() ) ;
   }
   return g ;
 }

void Group::removeObject( Object* o )
{
   unsigned int n = (unsigned int)_children.size() ;

   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _children[i] == o )
      {
         _children.erase( _children.begin() + i ) ;
         return ;
      }
   }
   return ;
}

void Group::clear()
{
   _children.clear();
   _temp_scale._x = 1;
   _temp_scale._y = 1;
}
