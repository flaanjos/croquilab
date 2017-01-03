#include "image.h"
#include "float.h"
#include "cd.h"
#include "wd.h"
#include "im.h"
#include "im_util.h"
#include "im_image.h"
#include "im_convert.h" 
#include "math.h"
#include "image_saver.h"

Image::Image(  imFile *file  ) 
{
   int error ;
   _file = file ;
   imImage* image = imFileLoadBitmap( file, 0, &error ) ;
   imFileClose(_file);

   if( image->color_space == IM_MAP )
   {
      _map_image = image ;
      image = NULL ;
   }
   else
   {
      _map_image = imImageCreate( image->width, image->height, IM_MAP, IM_BYTE ) ;
      imConvertColorSpace ( image, _map_image ) ;
   }
   for( int c=0 ; c<_map_image->palette_count ; c++ )
   {    
      imColorDecode(
      &(_original_palette[c][0]),
      &(_original_palette[c][1]),
      &(_original_palette[c][2]),
      _map_image->palette[c] ) ;         
   }
   
   setColored() ;
   setIntensity(0);
}

void Image::setData( int w, int h, const unsigned char* data, const long* palette256  ) 
{
   if( _map_image )
   {
      imImageDestroy( _map_image );
      _map_image = 0;
   }
   _map_image = imImageCreate( w, h, IM_MAP, IM_BYTE ) ;

   if( data )
   {
      memcpy( _map_image->data[0], data, w*h );
   }
   //if( _map_image->palette_count != 256 )
   //{
   //   //ERROR ABSURDO, compartamento inesperado da IM
   //}
   for( int c=0 ; c<_map_image->palette_count ; c++ )
   {    
      if( palette256 )
          _map_image->palette[c] = palette256[c] ;    

    
      imColorDecode(
      &(_original_palette[c][0]),
      &(_original_palette[c][1]),
      &(_original_palette[c][2]),
      _map_image->palette[c] ) ;         
   }
}


Image::Image( ) 
{
   _file = 0 ;
   _map_image  = 0 ; 

   _intensity  = 0 ;
   _use_pseudo_color  = 0 ;
   Object::color( 0 );
}
Image::~Image()
{
   if( _map_image )
      imImageDestroy(_map_image); 
};

const Point2d & Image::scale( ) const
{
   return _scale ;
} ;

void Image::scale( const Point2d & s ) 
{
   edit( s, _position ) ;
};

const Point2d & Image::position( ) const
{
   return _position ;
} ;

void Image::position( const Point2d & p ) 
{
   edit( _scale, p ) ;
};

void Image::edit( const Point2d & s, const Point2d & p ) 
{
   _position = p ;
   _scale = s ;
};


void Image::draw( const Point2d & s, const Point2d & p ) const
{
   if( !_map_image )
      return;

   int w = (int)(_map_image->width *_scale._x) ;
   int h = (int)(_map_image->height*_scale._y) ;

   int xmin=0, xmax=0, ymin=0, ymax=0;

   //if (_map_image->color_space == IM_RGB)                                      
   //{                                                                       
   //   if (_image->has_alpha)                                                 
   //      wdPutImageRectRGBA(_image->width, _image->height,                   
   //      (unsigned char*)_image->data[0],                  
   //      (unsigned char*)_image->data[1],                  
   //      (unsigned char*)_image->data[2],                  
   //      (unsigned char*)_image->data[3],                  
   //      _position._x-_image->width*_scale._x/2, _position._y-_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);      
   //   else                                                                  
   //      wdPutImageRectRGB(_image->width, _image->height,                    
   //      (unsigned char*)_image->data[0],                  
   //      (unsigned char*)_image->data[1],                  
   //      (unsigned char*)_image->data[2],                  
   //      _position._x-_image->width*_scale._x/2, _position._y-_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);      
   //} 

   //else    
   //{
      wdPutImageRectMap(_map_image->width, _map_image->height, 
         (unsigned char*)_map_image->data[0], _map_image->palette,   
         _position._x-_map_image->width*_scale._x/2, _position._y-_map_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);
   //}
} ;

void Image::draw( ) const
{   
   if( !_map_image )
      return;

   int w = (int)(_map_image->width *_scale._x) ;
   int h = (int)(_map_image->height*_scale._y) ;

   int xmin=0, xmax=0, ymin=0, ymax=0;

/*   if (_image->color_space == IM_RGB)                                      
   {                                                                       
      if (_image->has_alpha)                                                 
         wdPutImageRectRGBA(_image->width, _image->height,                   
         (unsigned char*)_image->data[0],                  
         (unsigned char*)_image->data[1],                  
         (unsigned char*)_image->data[2],                  
         (unsigned char*)_image->data[3],                  
         _position._x-_image->width*_scale._x/2, _position._y-_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);      
      else                                                                  
         wdPutImageRectRGB(_image->width, _image->height,                    
         (unsigned char*)_image->data[0],                  
         (unsigned char*)_image->data[1],                  
         (unsigned char*)_image->data[2],                  
         _position._x-_image->width*_scale._x/2, _position._y-_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);      
   } 

   else  */  
   {
      wdPutImageRectMap(_map_image->width, _map_image->height, 
         (unsigned char*)_map_image->data[0], _map_image->palette,   
         _position._x-_map_image->width*_scale._x/2, _position._y-_map_image->height*_scale._y/2, w, h, xmin, xmax, ymin, ymax);
   }
} ;


void Image::boundingBox( Point2d& min, Point2d& max ) const
{
   if( _map_image )
   {
      min._x = _position._x-_map_image->width*_scale._x/2 ;
      min._y = _position._y-_map_image->height*_scale._y/2 ;

      max._x = min._x+_map_image->width*_scale._x-1 ;
      max._y = min._y+_map_image->height*_scale._y-1 ;
   }
   else
   {
      min._x = _position._x ;
      min._y = _position._y ;

      max._x = min._x ;
      max._y = min._y ;
   }
}
void Image::drawSelectable() 
{
   Point2d min(0,0), max(0,0) ;
   boundingBox( min, max ) ;
   cdInteriorStyle( CD_SOLID );

   wdBox( min._x, max._x, min._y, max._y);
}

void Image::setIntensity( double i ) 
{
   _intensity = i ;
    resetPalette() ;

}
void Image::setColored()
{
   _use_pseudo_color = false ;
    resetPalette() ;
};

bool Image::isColored()
{
   return !_use_pseudo_color;
}

double Image::intensity()
{
   return _intensity;
};
long int Image::color() const 
{
   return Object::color();
}
void Image::color( long int c ) 
{
   Object::color( c );
   _use_pseudo_color = true ;
   resetPalette() ;
}
void Image::resetPalette()
{
   double i = 1-pow(_intensity, 1.35);
//0.2989*red + 0.5870*green + 0.1140*blue  

   //if( _use_pseudo_color )
   //{
   //   for( int c=0 ; c<_map_image->palette_count ; c++ )
   //   {  
   //      double index = _original_palette[c][0]*0.2989+
   //                     _original_palette[c][1]*0.5870+
   //                     _original_palette[c][2]*0.1140 ;


   //      long color = imColorEncode( 
   //            (unsigned char)(((index*(255-_pseudo_r)/255)+_pseudo_r)*i+(255-255*i)),
   //            (unsigned char)(((index*(255-_pseudo_g)/255)+_pseudo_g)*i+(255-255*i)),
   //            (unsigned char)(((index*(255-_pseudo_b)/255)+_pseudo_b)*i+(255-255*i)));
   //   
   //      _map_image->palette[c] = color ;
   //   }
   //}
   if( _use_pseudo_color )
   {
      unsigned char  _pseudo_r = 0 ;
      unsigned char  _pseudo_g = 0 ;
      unsigned char  _pseudo_b = 0 ;
      imDecodeColor( &_pseudo_r, &_pseudo_g, &_pseudo_b, color() );

      double tempr = 3.0*_pseudo_r/4 ;
      double tempg = 3.0*_pseudo_g/4 ;
      double tempb = 3.0*_pseudo_b/4 ;

      double n = (_map_image->palette_count)/2;

      for( int c=0 ; c<_map_image->palette_count ; c++ )
      {  
         double index = _original_palette[c][0]*0.2989 +
                        _original_palette[c][1]*0.5870 +
                        _original_palette[c][2]*0.1140 ;
       
         if( index < 128 )
         {
            long color = imColorEncode( 
               (unsigned char)( ((index*tempr)/n) * i + (255-255*i) ),
               (unsigned char)( ((index*tempg)/n) * i + (255-255*i) ),
               (unsigned char)( ((index*tempb)/n) * i + (255-255*i) )) ;

            _map_image->palette[c] = color ;
         }
         else
         {  
            index -= 128 ;
            long color = imColorEncode( 
               (unsigned char)( ((index*(255-tempr)/127)+tempr) * i + (255-255*i) ),
               (unsigned char)( ((index*(255-tempg)/127)+tempg) * i + (255-255*i) ),
               (unsigned char)( ((index*(255-tempb)/127)+tempb) * i + (255-255*i) ) );

            _map_image->palette[c] = color ;
         }
      }
   }
   else
   {
      for( int c=0 ; c<_map_image->palette_count ; c++ )
      {    
         long color = imColorEncode(
               (unsigned char)(_original_palette[c][0]*i+(255-255*i)),
               (unsigned char)(_original_palette[c][1]*i+(255-255*i)),
               (unsigned char)(_original_palette[c][2]*i+(255-255*i)) ) ;
      
         _map_image->palette[c] = color ;
      }
   }

};



Object* Image::copy()
{
   return 0 ;
}


long Image::palette( int i )
{
   return imEncodeColor( _original_palette[i][0], _original_palette[i][1], _original_palette[i][2] );
}

unsigned char* Image::data( int& w, int& h )
{
   if( _map_image )
   {
      w = _map_image->width;
      h = _map_image->height;
      return (unsigned char*)(_map_image->data[0]);
   }

   return 0;
}