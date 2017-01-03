#pragma once
#ifndef _GROUP__
#define _GROUP__ 2

#include "scalable_object.h"
#include <vector>


class Group : public Scalable
{
public:
   Group( )  ;
   Group( std::vector< Object*> ) ;
   Group( const Group& grp );  
   virtual ~Group( ) ;


   virtual void draw() const ;
   virtual void drawSelectable() ;

   virtual long int color() const ;
   virtual void color( long int c ) ;

   long int lineSize() const ;
   void lineSize( long int ls ) ;

   long int lineType() const ;
   void lineType( long int lt ) ;

   virtual void position( const Point2d& p ) ;
   virtual const Point2d& position( ) const ;

   virtual Manipulator * manipulator() ;
   virtual void boundingBox( Point2d& min, Point2d& max ) const ;
 
   Saver *saver() ;
   void saver( Saver* s ) ;

   virtual void scale( const Point2d & s )  ;
   virtual const Point2d& scale() const{ return Object::scale(); } ;
   virtual void edit( const Point2d &s, const Point2d & p ) ;

   virtual Object*copy() ;

   void addObject( Object* o ) ;

   void removeObject( Object* o ) ;
   void clear();

   unsigned int numObjects() const ;

   Object* object( unsigned int i ) ;

   const std::vector< Object*>& children() {return _children;};

private:
   std::vector< Object*> _children ;

} ;

#endif

