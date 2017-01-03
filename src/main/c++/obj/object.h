#pragma once
#ifndef _OBJECT__
#define _OBJECT__ 1

#include <vector>
#include "manipulator.h"
#include "point2d.h"
#include "saver.h"

class Object
{
public:
   Object ( )  ;
   Object( const Object& obj ) ;  
   virtual ~Object( ) ;

   long int id() const ;
   static long int noId() ;

   virtual void draw() const = 0 ;
   virtual void drawSelectable() ;

   virtual long int color() const ;
   virtual void color( long int c ) ;

   virtual long int lineSize() const ;
   virtual void lineSize( long int ls ) ;

   virtual long int lineType() const ;
   virtual void lineType( long int lt ) ;

   virtual void position( const Point2d& p ) = 0 ;
   virtual const Point2d& position( ) const = 0 ;

   virtual void scale( const Point2d& s ) {} ;
   virtual const Point2d& scale( ) const {return _temp_scale;} ;

   virtual void boundingBox( Point2d& min, Point2d& max ) const = 0 ;
 
   virtual Object* copy() = 0 ;

   virtual Manipulator* manipulator()  = 0 ;

   Saver *saver() ;
   void saver( Saver* s ) ;

private:
   static long int _id_count ;
   long int _id ;


   long int _color ;
   long int _line_size ;
   long int _line_type ;
   Saver *_saver ;
protected:
   Point2d _temp_scale; 

  };

#endif

