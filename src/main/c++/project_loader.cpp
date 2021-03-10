#include <string>
#include <fstream>
#include "im.h"
#include "im_util.h"
#include "im_image.h"
#include "image.h"
#include "round_bolt.h"
#include "sharp_bolt.h"
#include "sharp_bolt_with_ring.h"
#include "chains.h"
#include "screw.h"
#include "piton.h"
#include "opt_station.h"
#include "rapel.h"
#include "expo.h"
#include "text.h"
#include "crystal.h"
#include "hole.h"
#include "Block.h"
#include "tree.h"
#include "palm_tree.h"
#include "pine_tree.h"
#include "bush.h"
#include "cactus.h"
#include "grass.h"
#include "elliptical.h"
#include "box.h"
#include "braces.h"
#include "cable.h"
#include "chimney.h"
#include "dihedral.h"
#include "arete.h"
#include "crack.h"
#include "off_width.h"
#include "oposition.h"
#include "stations.h"
#include "Arrow.h"
#include "polygonal.h"
#include "route_line.h"
#include "solid_saver.h"
#include "segmented_saver.h"
#include "wide_segmented_saver.h"
#include "curved_saver.h"
#include "scalable_saver.h"
#include "text_saver.h"
#include "image_saver.h"

#include "Base64Coder.h"
#include "ArithmeticCoder.h"
#include "topoEditor.h"

void readColor   ( Object *o, std::ifstream& stream ) ;
void readLineType( Object *o, std::ifstream& stream ) ;
void readLineSize( Object *o, std::ifstream& stream ) ;
long readInt     ( std::ifstream& stream ) ;
double readDouble( std::ifstream& stream ) ;
bool readBool    ( std::ifstream& stream ) ;

void readPosition( Solid *s, std::ifstream& stream ) ;
void readScale( Scalable *s, std::ifstream& stream ) ;
void readPoints( Segmented *s, std::ifstream& stream ) ;
void readPoints( Curved *s, std::ifstream& stream ) ;
void readWidth( WideSegmented *ws, std::ifstream& stream ) ;
void readText( Text *t, std::ifstream& stream ) ;
unsigned char* readPixels( Image* i, std::ifstream& stream, int w, int h );
long * readLongVector( std::ifstream& stream, int n );

void loadSolid( Solid *s, std::ifstream& stream ) ;
void loadScalable( Scalable *s, std::ifstream& stream ) ;
void loadSegmented( Segmented *s, std::ifstream& stream ) ;
void loadWideSegmented( WideSegmented *s, std::ifstream& stream ) ;
void loadCurved( Curved *s, std::ifstream& stream ) ;
void loadText( Text *t, std::ifstream& stream ) ;
void readTextSize( Text *t, std::ifstream& stream ) ;
void loadImage( Image *bi, std::ifstream& stream ) ;

Object *loadRoundBolt( std::ifstream& stream );
Object *loadSharpBolt( std::ifstream& stream );
Object *loadSharpBoltWithRing( std::ifstream& stream );
Object *loadChains( std::ifstream& stream );
Object *loadPiton( std::ifstream& stream );
Object *loadScrew( std::ifstream& stream );
Object *loadOptStation( std::ifstream& stream );
Object *loadRapel( std::ifstream& stream );
Object *loadExpo( std::ifstream& stream );
Object *loadText( std::ifstream& stream );
Object *loadCrystal( std::ifstream& stream );
Object *loadHole( std::ifstream& stream );
Object *loadBlock( std::ifstream& stream );
Object *loadTree( std::ifstream& stream );
Object *loadPalmTree( std::ifstream& stream );
Object *loadPineTree( std::ifstream& stream );
Object *loadBush( std::ifstream& stream );
Object *loadCactus( std::ifstream& stream );
Object *loadGrass( std::ifstream& stream );
Object *loadElliptical( std::ifstream& stream );
Object *loadBox( std::ifstream& stream );
Object *loadBrace( std::ifstream& stream );
Object *loadCable( std::ifstream& stream );
Object *loadChimney( std::ifstream& stream );
Object *loadDihedral( std::ifstream& stream );
Object *loadArete( std::ifstream& stream );
Object *loadCrack( std::ifstream& stream );
Object *loadOffWidth( std::ifstream& stream );
Object *loadOposition( std::ifstream& stream );
Object *loadStations( std::ifstream& stream );
Object *loadArrow( std::ifstream& stream );
Object *loadPolygonal( std::ifstream& stream );
Object *loadFreeLine( std::ifstream& stream );
Object *loadRouteLine( std::ifstream& stream );
Object *loadImage( std::ifstream& stream ) ;


void loadProject( TopoEditor&editor, std::string url )
{
   long version = -1 ; // Alpha
   std::ifstream stream;
   stream.open( url.c_str(), std::ifstream::in );

   std::string alfa;

   stream >> alfa;
   if( alfa == "Topo" )
   {

      stream >> alfa; // =
      stream >> alfa; // [
      stream >> alfa;
      while( alfa != ";" )
      {
         if( alfa == "_version" )
         {
            stream >> alfa ; // = 
            stream >> version ;
            stream >> alfa;
         }
         stream >> alfa; // ;
      }
      stream >> alfa;
   }    

   Object *o = NULL;
   while( alfa != ";" )
   {
       o= 0;
      if( alfa == "RoundBolt" )
      {
         o = loadRoundBolt( stream );
      }
      else if( alfa == "SharpBolt" )
      {
         o = loadSharpBolt( stream );
      }
      else if( alfa == "SharpBoltWithRing" )
      {
         o = loadSharpBoltWithRing( stream );
      }
      else if( alfa == "Chains" )
      {
         o = loadChains( stream );
      }
      else if( alfa == "Piton" )
      {
         o = loadPiton( stream );
      }
      else if( alfa == "Screw" )
      {
         o = loadScrew( stream );
      }
      else if( alfa == "OptStation" )
      {
         o = loadOptStation( stream );
      }
      else if( alfa == "Rapel" )
      {
         o = loadRapel( stream );
      }
      else if( alfa == "Expo" )
      {
         o = loadExpo( stream );
      }
      else if( alfa == "Text" )
      {
         o = loadText( stream );
      }
      else if( alfa == "Crystal" )
      {
         o = loadCrystal( stream );
      }
      else if( alfa == "Hole" )
      {
         o = loadHole( stream );
      }
      else if( alfa == "Block" )
      {
         o = loadBlock( stream );
      }
      else if( alfa == "Tree" )
      {
         o = loadTree( stream );
      }
      else if( alfa == "PalmTree" )
      {
         o = loadPalmTree( stream );
      }
      else if( alfa == "PineTree" )
      {
         o = loadPineTree( stream );
      }
      else if( alfa == "Bush" )
      {
         o = loadBush( stream );
      }
      else if( alfa == "Cactus" )
      {
         o = loadCactus( stream );
      }
      else if( alfa == "Grass" )
      {
         o = loadGrass( stream );
      }
      else if( alfa == "Elliptical" )
      {
         o = loadElliptical( stream );
      }
      else if( alfa == "Box" )
      {
         o = loadBox( stream );
      }
      else if( alfa == "Brace" )
      {
         o = loadBrace( stream );
      }
      else if( alfa == "Cable" )
      {
         o = loadCable( stream );
      }
      else if( alfa == "Chimney" )
      {
         o = loadChimney( stream );
      }
      else if( alfa == "Dihedral" )
      {
         o = loadDihedral( stream );
      }
      else if( alfa == "Arete" )
      {
         o = loadArete( stream );
      }
      else if( alfa == "Crack" )
      {
         o = loadCrack( stream );
      }
      else if( alfa == "OffWidth" )
      {
         o = loadOffWidth( stream );
      }
      else if( alfa == "Oposition" )
      {
         o = loadOposition( stream );
      }
      else if( alfa == "Stations" )
      {
         o = loadStations( stream );
      }
      else if( alfa == "Arrow" )
      {
         o = loadArrow( stream );
      }
      else if( alfa == "Polygonal" )
      {
         o = loadPolygonal( stream );
      }
      else if( alfa == "RouteLine" )
      {
         o = loadRouteLine( stream );
      }
      else if( alfa == "FreeLine" )
      {
         o = loadFreeLine( stream );
      }
      else if( alfa == "Image" )
      {
         o = loadImage( stream );
      }      

      if( o )
         editor.addObject( o );

      stream >> alfa ; // ;
      stream >> alfa ;
   }
}


void loadSolid( Solid *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

   stream >> alfa;
   while( alfa != "]" )
   {
      if( alfa == "_position" )
      {
         readPosition( s, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( s, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( s, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( s, stream );
      }
      stream >> alfa;
      if( alfa == "," )
         stream >> alfa;
   }
}
void loadScalable( Scalable *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> alfa;
   while( alfa != "]" )
   {
      if( alfa == "_position" )
      {
         readPosition( s, stream );
      }
      else if( alfa == "_scale" )
      {
         readScale( s, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( s, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( s, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( s, stream );
      }
      stream >> alfa ;
      if( alfa == "," )
         stream >> alfa;
   }
}

void loadCurved( Curved *c, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> alfa;
   while( alfa != "]" )
   {
      if( alfa == "_points" )
      {
         readPoints( c, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( c, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( c, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( c, stream );
      }
      stream >> alfa ;
      if( alfa == "," )
         stream >> alfa;
   }
}
void loadSegmented( Segmented *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> alfa; // caracteristica do objeto

   while( alfa != "]" )
   {
      if( alfa == "_points" )
      {
         readPoints( s, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( s, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( s, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( s, stream );
      }
      stream >> alfa ; // , ou ]
      if( alfa == "," )
         stream >> alfa;
   }
}

void loadWideSegmented( WideSegmented *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> alfa; // caracteristica do objeto

   while( alfa != "]" )
   {
      if( alfa == "_points" )
      {
         readPoints( s, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( s, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( s, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( s, stream );
      }
      else if( alfa == "_width" )
      {
         readWidth( s, stream );
      }
      stream >> alfa ; // , ou ]
      if( alfa == "," )
         stream >> alfa;
   }
}

void loadText( Text *t, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

   stream >> alfa;
   while( alfa != "]" )
   {
      if( alfa == "_position" )
      {
         readPosition( t, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( t, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( t, stream );
      }
      else if( alfa == "_color" )
      {
         readColor( t, stream );
      }
      else if( alfa == "_text" )
      {
         readText( t, stream );
      }
      else if( alfa == "_size" )
      {
         readTextSize( t, stream );
      }
      stream >> std::skipws >> alfa;
      if( alfa == "," )
         stream >> alfa;
   }
}
void loadImage( Image *s, std::ifstream& stream )
{
   long width = 0 ;
   long height = 0 ;
   long palette_count = 0 ;
   unsigned char* pixels = 0;
   long *palette = 0;
   int color = 0;
   bool auto_color = 0;
   double intensity = 0 ;

   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> alfa;
   while( alfa != "]" )
   {
      if( alfa == "_position" )
      {
         readPosition( s, stream );
      }
      else if( alfa == "_scale" )
      {
         readScale( s, stream );
      }
      else if( alfa == "_line_type" )
      {
         readLineType( s, stream );
      }
      else if( alfa == "_line_size" )
      {
         readLineSize( s, stream );
      }
      else if( alfa == "_color" )
      {
         color = readInt( stream );
      }
      else if( alfa == "automatic_color" )
      {
         auto_color = readBool( stream );
      }
      else if( alfa == "intensity" )
      {
         intensity = readDouble( stream );
      }
      else if( alfa == "_color" )
      {
         color = readInt( stream );
      }
      else if( alfa == "width" )
      {
         width = readInt( stream );
      }
      else if( alfa == "height" )
      {
         height = readInt( stream );
      }
      else if( alfa == "palette_count" )
      {
         palette_count = readInt( stream );
      }
      else if( alfa == "palette" )
      {
         palette = readLongVector( stream, palette_count );
      }
      else if( alfa == "pixels" )
      {
         pixels = readPixels( s, stream, width, height );
      }
      stream >> alfa ;
      if( alfa == "," )
         stream >> alfa;
   }

   s->setData( width, height, pixels, palette );
   delete[] pixels ;
   delete[] palette ;

   s->color( color );
   if( auto_color )
      s->setColored();
   else
      s->color( color );

   s->setIntensity( intensity );
}

long readInt( std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long c = 0;
   stream >> c ;
   return c ;
}

double readDouble( std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   double c = 0;
   stream >> c ;
   return c ;
}

bool readBool( std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   bool c = 0;
   stream >> c ;
   return c ;
}

void readColor( Object *o, std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long c = 0;
   stream >> c ;
   o->color( c );
}
void readLineType( Object *o, std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long t = 0;
   stream >> t ;
   o->lineType( t );
}
void readLineSize( Object *o, std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long s = 0;
   stream >> s ;
   o->lineSize( s );
}
void readTextSize( Text *t, std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long s = 0;
   stream >> s ;
   t->size( s );
}
void readWidth( WideSegmented *ws, std::ifstream& stream )
{
   std::string alfa ;
   stream >> alfa ; // = 
   long w = 0;
   stream >> w ;
   ws->width( w );
}

void readPoints( Segmented* o, std::ifstream& stream )
{
   std::string alfa;
   float x=0;
   float y=0;

   //read = 
   stream >> alfa;

   // read set [
   stream >> alfa;

   unsigned int n = o->numPoints();
   unsigned int i = 0;

   while( alfa != "]" )
   {
      stream >> alfa; // [
      stream >> x;
      stream >> alfa; // coma
      stream >> y;

      if( i<n )
         o->position( i, Point2d( x, y ) );
      else
         o->addPoint( Point2d( x, y ) );

      stream.width( 1 );
      stream >> alfa; // ]

      stream.width( 1 );
      stream >> alfa; // , or ]

      i++;
   }
}

void readPosition( Solid* o, std::ifstream& stream )
{
   std::string alfa;

   float x=0;
   float y=0;

   stream >> alfa; // =
   stream >> alfa; // [
   stream >> x;
   stream >> alfa; // ,
   stream >> y;
   stream >> alfa; // ], ou ]

   o->position( Point2d( x, y ) );
}

long* readLongVector( std::ifstream& stream, int n )
{
   std::string alfa;

   long* vector = new long[n] ;

   stream >> alfa; // =
   stream >> alfa; // [
   for( int i=0 ; i< n-1 ; i++)
   {
      stream >> vector[i];
      stream >> alfa; // ,
   }
   stream >> vector[n-1];
   stream >> alfa; // ], ou ]

   return vector;
}

void readScale( Scalable* o, std::ifstream& stream )
{
   std::string alfa;
   float x=0;
   float y=0;


   stream >> alfa; // =
   stream >> alfa; // [
   stream >> x;
   stream >> alfa; // ,
   stream >> y;
   stream >> alfa; //], ou ]

   o->scale( Point2d( x, y ) );
}
void readPoints( Curved* o, std::ifstream& stream )
{
   std::string alfa;
   float px=0;
   float py=0;
   float x=0;
   float y=0;
   float ax=0;
   float ay=0;


   //read = 
   stream >> alfa;

   // read set [
   stream >> alfa;

   unsigned int n = o->numPoints();
   unsigned int i = 0;
   while( alfa != "]" )
   {
      stream >> alfa; // [

      stream >> alfa; // [
      stream >> px;
      stream >> alfa; // coma
      stream >> py;
      stream >> alfa; //],

      stream >> alfa; // [
      stream >> x;
      stream >> alfa; // coma
      stream >> y;
      stream >> alfa; //],

      stream >> alfa; // [
      stream >> ax;
      stream >> alfa; // coma
      stream >> ay;
      stream >> alfa; //]

      stream.width( 1 );
      stream >> alfa; // ]

      stream.width( 1 );
      stream >> alfa; // , or ]

      if( i<n )
         o->position( i, Point2d( x, y ) );
      else
         o->addPoint( Point2d( x, y ) );

      o->positionPrevScape( i, Point2d( px, py ) );
      o->positionAftScape( i, Point2d( ax, ay ) );
      i++;
   }
}
unsigned char* readPixels( Image* i, std::ifstream& stream, int w, int h )
{
   char alfinha;
   stream >> alfinha; // =

  // stream.width( 1 );
   stream >> alfinha ; // "

   stream.width();
   std::string base64_pixels;
   stream >> base64_pixels;

   Base64Coder stringfier;
   int n_comp =0;
   const unsigned char* string64 = (unsigned char*)base64_pixels.c_str();
   // Nao inclui as aspas finais na descompressao
   unsigned char* compressed = stringfier.decode( string64, base64_pixels.size()-1, n_comp );

   unsigned char* decompressed = new unsigned char[ w*h+100 ];

   ArithmeticCoder decompressor;
   int n_decomp = decompressor.decode(compressed, n_comp, decompressed, n_comp*3 );

   return decompressed;
}
void readText( Text* o, std::ifstream& stream, int length )
{
   std::string alfa;
   std::string text;
   float px=0;
   float py=0;
   float x=0;
   float y=0;
   float ax=0;
   float ay=0;


   //read = 
   char alfinha;
   stream >> alfinha;

   stream.width( 1 );
   stream >> alfinha ; // "

   stream.width( 1 );
   stream >> std::noskipws >> alfinha ; // "

   for( int i=0;i<length;i++)
   {     
      //if( alfa == "\\" )
      //{
      //   stream.width( 1 );
      //   stream >> alfa ;

      //   if( alfa == "n" )
      //      alfa = "\n" ;
      //   else if( alfa == "t" )
      //      alfa = "\t" ;

      //}

      text += alfinha;

    //  stream.width( 1 );
      stream >> alfinha ;
   }

     stream.width( 1 );
    stream >> std::noskipws >> alfinha ; // "

   o->text( text );
}

Object *loadRoundBolt( std::ifstream& stream )
{
   RoundBolt * o = new RoundBolt();
   SolidSaver *ss  = new SolidSaver( o, "RoundBolt"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadSharpBolt( std::ifstream& stream )
{
   SharpBolt * o = new SharpBolt();
   SolidSaver *ss  = new SolidSaver( o, "SharpBolt"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}


Object *loadSharpBoltWithRing( std::ifstream& stream )
   {
   SharpBoltWithRing * o = new SharpBoltWithRing();
   SolidSaver *ss  = new SolidSaver( o, "SharpBoltWithRing"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadChains( std::ifstream& stream )
{
   Chains * o = new Chains();
   SolidSaver *ss  = new SolidSaver( o, "Chains"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadPiton( std::ifstream& stream )
{
   Piton * o = new Piton();
   SolidSaver *ss  = new SolidSaver( o, "Piton"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadScrew( std::ifstream& stream )
{
   Screw * o = new Screw();
   SolidSaver *ss  = new SolidSaver( o, "Screw"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}



Object *loadOptStation( std::ifstream& stream )
{
   OptStation * o = new OptStation();
   SolidSaver *ss  = new SolidSaver( o, "OptStation"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadRapel( std::ifstream& stream )
{
   Rapel * o = new Rapel();
   SolidSaver *ss  = new SolidSaver( o, "Rapel"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadExpo( std::ifstream& stream )
{
   Expo * o = new Expo();
   SolidSaver *ss  = new SolidSaver( o, "Expo"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadText( std::ifstream& stream )
{
   Text * o = new Text();
   TextSaver *ss  = new TextSaver( o );
   o->saver( ss );
   loadText( o, stream );
   if( o->text().size() == 0)
   {
      delete o;
      return 0;
   }
   return o;
}

Object *loadImage( std::ifstream& stream )
{
   Image *bi = new Image();
   ImageSaver *is  = new ImageSaver( bi );
   bi->saver( is );
   loadImage( bi, stream );
   return bi;
}



Object *loadCrystal( std::ifstream& stream )
{
   Crystal * o = new Crystal();
   ScalableSaver *ss  = new ScalableSaver( o, "Crystal"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadHole( std::ifstream& stream )
{
   Hole * o = new Hole();
   ScalableSaver *ss  = new ScalableSaver( o, "Hole"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBlock( std::ifstream& stream )
{
   Block * o = new Block();
   ScalableSaver *ss  = new ScalableSaver( o, "Block"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadTree( std::ifstream& stream )
{
   Tree * o = new Tree();
   ScalableSaver *ss  = new ScalableSaver( o, "Tree"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadPalmTree( std::ifstream& stream )
{
   PalmTree * o = new PalmTree();
   ScalableSaver *ss  = new ScalableSaver( o, "PalmTree"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;

}

Object *loadPineTree( std::ifstream& stream )
{
   PineTree * o = new PineTree();
   ScalableSaver *ss  = new ScalableSaver( o, "PineTree"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBush( std::ifstream& stream )
{
   Bush * o = new Bush();
   ScalableSaver *ss  = new ScalableSaver( o, "Bush"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadCactus( std::ifstream& stream )
{
   Cactus * o = new Cactus();
   ScalableSaver *ss  = new ScalableSaver( o, "Cactus"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadGrass( std::ifstream& stream )
{
   Grass * o = new Grass();
   ScalableSaver *ss  = new ScalableSaver( o, "Grass"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadElliptical( std::ifstream& stream )
{
   Elliptical * o = new Elliptical();
   ScalableSaver *ss  = new ScalableSaver( o, "Elliptical"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBox( std::ifstream& stream )
{
   Box * o = new Box();
   ScalableSaver *ss  = new ScalableSaver( o, "Box"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBrace( std::ifstream& stream )
{
   Brace * o = new Brace();
   ScalableSaver *ss  = new ScalableSaver( o, "Brace"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}



Object *loadCable( std::ifstream& stream )
{
   Cable * o = new Cable( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Cable" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadChimney( std::ifstream& stream )
{
   Chimney * o = new Chimney( Point2d(0,0), Point2d(0,0) );
   WideSegmentedSaver *ss  = new WideSegmentedSaver( o, "Chimney" );
   o->saver( ss );
   loadWideSegmented( o, stream );
   return o;
}

Object *loadDihedral( std::ifstream& stream )
{
   Dihedral * o = new Dihedral( Point2d(0,0), Point2d(0,0) );
   WideSegmentedSaver *ss  = new WideSegmentedSaver( o, "Dihedral" );
   o->saver( ss );
   loadWideSegmented( o, stream );
   return o;
}

Object *loadArete( std::ifstream& stream )
{
   Arete * o = new Arete( Point2d(0,0), Point2d(0,0) );
   WideSegmentedSaver *ss  = new WideSegmentedSaver( o, "Arete" );
   o->saver( ss );
   loadWideSegmented( o, stream );
   return o;
}

Object *loadCrack( std::ifstream& stream )
{
   Crack * o = new Crack( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Crack" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadOffWidth( std::ifstream& stream )
{
   OffWidth * o = new OffWidth( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "OffWidth" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadOposition( std::ifstream& stream )
{
   Oposition * o = new Oposition( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Oposition" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadStations( std::ifstream& stream )
{
   Stations * o = new Stations();
   SegmentedSaver *ss  = new SegmentedSaver( o, "Stations" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadArrow( std::ifstream& stream )
{
   Arrow * o = new Arrow( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Arrow" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadPolygonal( std::ifstream& stream )
{
   Polygonal * o = new Polygonal( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Polygonal"  );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}



Object *loadFreeLine( std::ifstream& stream )
{
   RouteLine * o = new RouteLine( Point2d(0,0), Point2d(0,0) );
   CurvedSaver *ss = new CurvedSaver( o, "FreeLine" );
   o->saver( ss );
   loadCurved( o, stream );
   return o;
}

Object *loadRouteLine( std::ifstream& stream )
{
   RouteLine * o = new RouteLine( Point2d(0,0), Point2d(0,0) );
   CurvedSaver *ss = new CurvedSaver( o, "RouteLine" );
   o->saver( ss );
   loadCurved( o, stream );
   return o;
}
