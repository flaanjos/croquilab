#pragma once
#ifndef __IMAGE_TOPO_OBJECT__H__
#define __IMAGE_TOPO_OBJECT__H__ 2

#include "scalable_object.h"
#include "point2d.h"
#include "bezier.h"
#include "polygon.h"
#include "manipulator.h"
#include "im.h"
#include "im_image.h"


class Image : public Scalable
{
public:
   Image( ) ;
   Image( imFile *file ) ;
   
   void setData( int w, int h, const unsigned char* data, const long* pallete256  ) ;

   virtual ~Image() ;

   const Point2d &position( ) const ;
   void position( const Point2d & p ) ;

   void scale( const Point2d & s ) ;
   const Point2d & scale( ) const ;

   void edit( const Point2d &s, const Point2d & p ) ;

   void draw( const Point2d &s, const Point2d & p) const ;
   void draw( ) const ;
   void drawSelectable() ;

   void setIntensity( double i ) ;
   void setColored() ;
   void color( long int c ) ;
   virtual long int color() const ;
   bool isColored();
   double intensity();

   long palette( int i );
   unsigned char* data( int& w, int& h );


   // virtual Manipulator * manipulator() ;

   void boundingBox( Point2d& min, Point2d& max ) const ;

   Object *copy() ;


protected:
   void resetPalette() ;
private:
   imFile *_file ;
   imImage *_map_image ; 

   unsigned char _original_palette[256][3]  ;

   double _intensity ;
   bool _use_pseudo_color ;
   //unsigned char _pseudo_r ;
   //unsigned char _pseudo_g ;
   //unsigned char _pseudo_b ;


};

#endif