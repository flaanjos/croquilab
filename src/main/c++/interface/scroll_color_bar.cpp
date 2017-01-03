#include "iup.h"
#include "cd.h"
#include "iupcontrols.h"

#include "scroll_color_bar.h"

long ScrollColorBar::colors[2000];

int ScrollColorBar::nColors = 200;

int ScrollColorBar::nLinesCallback( Ihandle* h ) 
{
   return 1;
}


int ScrollColorBar::nColumnsCallback(Ihandle* h) 
{
   return nColors;
}


int ScrollColorBar::cellHeightCallback( Ihandle* h, int i ) 
{
   return 40;
}


int ScrollColorBar::cellWidthCallback( Ihandle* h, int j ) 
{
   return 20;
}





int ScrollColorBar::mouseclickCallback( Ihandle* handle, int button, int pressed, int line, int column, int x, int y, char* status ) 
{
   if( pressed )
      return IUP_DEFAULT;

   ScrollColorBar* scroll_color_bar = (ScrollColorBar*) IupGetAttribute( handle, "SCROLLCOLORBAR" );

   if (scroll_color_bar)
   {
      if (scroll_color_bar->_callback)
      {
         scroll_color_bar->_callback( colors[column] );
      }
   }

   return IUP_DEFAULT;
}


int ScrollColorBar::drawCallback(Ihandle* h, int i, int j, int xmin, int xmax, int ymin, int ymax) 
{
   cdForeground( colors[j] );

   cdBox(xmin, xmax, ymin, ymax);

   return IUP_DEFAULT;
}

ScrollColorBar::ScrollColorBar( SCBcallback click_callback )
{
   _callback = click_callback;

   _cells = IupCells(); 

   IupSetCallback( _cells, "MOUSECLICK_CB", (Icallback)mouseclickCallback);
   IupSetCallback( _cells, "DRAW_CB",   (Icallback)drawCallback);
   IupSetCallback( _cells, "WIDTH_CB",  (Icallback)cellWidthCallback);
   IupSetCallback( _cells, "HEIGHT_CB", (Icallback)cellHeightCallback);
   IupSetCallback( _cells, "NLINES_CB", (Icallback)nLinesCallback);
   IupSetCallback( _cells, "NCOLS_CB",  (Icallback)nColumnsCallback);

   IupSetAttribute( _cells, "BOXED","NO");
   IupSetAttribute( _cells,"RASTERSIZE","500x40");
   IupSetAttribute( _cells, "SCROLLCOLORBAR", (char*)this );
   IupSetAttribute( _cells,IUP_EXPAND,IUP_HORIZONTAL);

   // Só pra nao ficar vazio, mas as celas começam de 1
  colors[0] =cdEncodeColor( 1,0,0);

   int i = 1 ;
   for( int c = 0; c <= 256; c+=32 )
   {
      if( c == 256 )
         c = 255;

      colors[i] = cdEncodeColor( (unsigned char)(c), (unsigned char)(c), (unsigned char)(c) ) ; 
      i++;
   }  

   colors[i++] = cdEncodeColor( (unsigned char)(128), (unsigned char)(0), (unsigned char)(0) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(0), (unsigned char)(0) ) ;      
   colors[i++] = cdEncodeColor( (unsigned char)(128), (unsigned char)(128), (unsigned char)(0) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(255), (unsigned char)(0) ) ; 

   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(128), (unsigned char)(0) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(255), (unsigned char)(0) ) ; 

   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(128), (unsigned char)(128) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(255), (unsigned char)(255) ) ; 

   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(0), (unsigned char)(128) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(0), (unsigned char)(255) ) ; 

   colors[i++] = cdEncodeColor( (unsigned char)(128), (unsigned char)(0), (unsigned char)(128) ) ; 
   colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(0), (unsigned char)(255) ) ; 

   int increment = 32;
   // VERMELHO
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(0), (unsigned char)(0) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(c), (unsigned char)(c) ) ; 
   } 

   // LARANJA
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(c/2), (unsigned char)(0) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(128+c/2), (unsigned char)(c) ) ; 
   } 


   // AMARELO
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(c), (unsigned char)(0) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(255), (unsigned char)(c) ) ; 
   }

   // VERDE
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(c), (unsigned char)(0) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(255), (unsigned char)(c) ) ; 
   } 

   // PSCINA
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(c), (unsigned char)(c/2) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(255), (unsigned char)(128+c/2) ) ; 
   } 

   // CIANO
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(c), (unsigned char)(c) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(255), (unsigned char)(255) ) ; 
   } 

   // AZUL estranho
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(c/2), (unsigned char)(c) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(128+c/2), (unsigned char)(255) ) ; 
   }

   // AZUL
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(0), (unsigned char)(0), (unsigned char)(c) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(c), (unsigned char)(255) ) ; 
   } 

   // ROXO
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c/2), (unsigned char)(0), (unsigned char)(c) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(128+c/2), (unsigned char)(c), (unsigned char)(255) ) ; 
   } 

   // MAGENTA
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(0), (unsigned char)(c) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(c), (unsigned char)(255) ) ; 
   } 

   // MAGENTA2
   for( int c = increment; c <= 256; c+=increment )
   {
      if( c == 256 )
         c = 255;

      colors[i++] = cdEncodeColor( (unsigned char)(c), (unsigned char)(0), (unsigned char)(c/2) ) ; 
   }
   for( int c = increment; c < 256; c+=increment )
   {
      colors[i++] = cdEncodeColor( (unsigned char)(255), (unsigned char)(c), (unsigned char)(128+c/2) ) ; 
   } 

   nColors = i-1; // -1 porque as celas começam de 1
}



