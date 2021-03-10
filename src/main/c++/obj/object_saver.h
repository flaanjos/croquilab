#pragma once
#ifndef _OBJECT__
#define _OBJECT__ 1
#include <vector>
#include "manipulator.h"
#include "point2d.h"
class Object
{
public:
   Object ( )  ;
   Object( const Object& obj );  
   virtual ~Object( ) { } ;

   virtual void drawSelectable() { draw() ;} ;
       
   virtual void draw() const = 0 ;

   long int color() const {return _color ;};
   void color( long int c ) {_color = c ;} ;

   long int lineSize() const {
      return _line_size ;
   };
   void lineSize( long int ls ) {_line_size = ls ;} ;

   long int lineType() const {return _line_type ;};
   void lineType( long int lt ) {_line_type = lt ;} ;

   long int id() const { return _id ; } ;
   static long int noId() { return 0 ; } ;

   virtual Manipulator* manipulator() 
   {
      return NULL ;
   }

   virtual void boundingBox( Point2d& min, Point2d& max ) const =0 ;

   virtual Object*copy(){return NULL;} ;

   //boundingBox( float &xmin, float &ymin, float &xmax, float &xmax ) = 0 ;
   //bool contains( float x, float y ) = 0 ;

private:
   long int _line_size ;
   long int _line_type ;
   long int _color ;
   long int _id   ;
   static long int _id_count ;
} ;

#endif

