#include "image_builder.h"
#include "image_saver.h"
#include "image.h"
#include "iup.h"

ImageBuilder::ImageBuilder()
{
}
ImageBuilder::~ImageBuilder()
{
}

Object * ImageBuilder::pressButton( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( button == 1 && !d_click ) 
   {
     return newObject( x, y ) ;
   }
   return 0 ;
}; 

Object *ImageBuilder::newObject( double x, double y )
{

   char nome[5000]  = "";
   if( IupGetFile( nome ) != 0 )
   {
      return 0 ;
   }

   int error =IM_ERR_NONE ;
   imFile* ifile = imFileOpen(nome, &error);
   if (error != IM_ERR_NONE) 
   {
      if (error == IM_ERR_OPEN) { IupMessage( "Erro", "O aplicativo encontrou um erro ao abrir o arquivo." ) ; }      /**< Error while opening the file (read or write). */
      else if (error ==  IM_ERR_ACCESS) { IupMessage( "Erro", "O aplicativo não tem permissão para ler este arquivo." ) ;  }    /**< Error while accessing the file (read or write). */
      else if (error ==  IM_ERR_FORMAT) { IupMessage( "Erro", "O aplicativo não reconhece o formato deste arquivo." ) ;  }    /**< Invalid or unrecognized file format. */
      else if (error ==  IM_ERR_DATA) { IupMessage( "Erro", "O aplicativo não dá suporte para o formato de armazenamento de dados nesta imagem." ) ;  }      /**< Invalid or unsupported data. */
      else if (error ==  IM_ERR_COMPRESS) { IupMessage( "Erro", "O aplicativo não dá suporte para o formato de compressão desta imagem." ) ;  }  /**< Invalid or unsupported compression. */
      else if (error ==  IM_ERR_MEM) { IupMessage( "Erro", "O aplicativo não conseguiu memória suficiente para trabalhar com esta imagem." ) ;  }       /**< Insuficient memory */
      else if (error ==  IM_ERR_COUNTER) { IupMessage( "Erro", "O aplicativo não conseguiu interpretar o tamanho desta imagem." ) ;  }    /**< Interrupted by the counter */
      else{ IupMessage( "Erro", "O aplicativo não conseguiu interpretar esta imagem." ) ;  }
      return 0 ;
   }

   // Creating new background
   Image* img = new Image( ifile ) ;

   // setting the new file's position
   img->position( Point2d( x, y ) ) ;
    
   // Seting the new background to the project
   ImageSaver *image_saver = new ImageSaver( img );
   img->saver( image_saver );

   return img ;
}