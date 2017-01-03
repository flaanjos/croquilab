#include "image_saver.h"
#include "ArithmeticCoder.h"
#include "Base64Coder.h"

//fstream

ImageSaver::ImageSaver( Image* s ) : _type_name( "Image" )
{
   _image = s ;
};

ImageSaver::ImageSaver( Image* s, const std::string &type_name ) : _type_name( type_name )
{
   _image = s ;
};

ImageSaver::ImageSaver()
{
   _image = NULL ;
};

ImageSaver::~ImageSaver()
{
};

Saver* ImageSaver::copy()
{
   return new ImageSaver() ;
}

Object* ImageSaver::object()
{
   return _image ;
}

void ImageSaver::object( Object* o ) 
{
   _image = (Image*)o ;
}

void ImageSaver::save( std::ostream& stream )
{

   if( _image )
   {
      stream << _type_name ;
      stream << " = [ _position = [ " ;
      stream << _image->position()._x ;
      stream << ", " ;
      stream << _image->position()._y ;
      stream << "], ";
      stream << "_scale = [ " ;
      stream << _image->scale()._x ;
      stream << ", " ;
      stream << _image->scale()._y ;
      stream << "], ";
      stream << "_line_type = " ;
      stream << _image->lineType() ;
      stream << ", _line_size = " ;
      stream << _image->lineSize() ;
      stream << ", _color = " ;
      stream << _image->color( ) ;
      stream << ", automatic_color = " ;
      stream << _image->isColored( ) ;
      stream << ", intensity = " ;
      stream << _image->intensity( ) ;
      stream << ", palette_count = " ;
      stream << 256;
      
      stream << ", palette = [ " ;
	  int i = 0 ;
      for( i=0 ; i<255 ; i++)
      {
         stream << _image->palette( i );
         stream << ", ";
      }
      stream << _image->palette( i );
      stream << " ]";


      int w = 0;
      int h = 0;
      unsigned char* data = _image->data( w, h );

      if( data )
      {
         int size  = w * h ;

         unsigned char* compressed = new unsigned char[ size * 1.1 ];
         ArithmeticCoder compressor;
         int n_comp = compressor.encode( data, size, compressed, size );

         Base64Coder stringfier;
         int n_out = 0;
         const unsigned char* image_bytes = stringfier.encode( compressed, n_comp, n_out );

         stream << ", width = " ;
         stream << w ;
         stream << ", height = " ;
         stream << h ;
         
         stream << ", pixels = \"" ;
         stream << image_bytes;
         stream << "\"" ;

         stream << " ] ;\n" ;

         delete[] compressed ;
      }
      else
      {
         stream << ", width = 0" ;
         stream << _image->scale()._x;
         stream << ", height = 0" ;
         stream << _image->scale()._y;
         stream << " ] ;\n" ;
      }
   }
};

