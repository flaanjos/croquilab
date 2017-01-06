#include <string>
#include <fstream>

#include "round_bolt.h"
#include "sharp_bolt.h"
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
#include "curved_saver.h"
#include "scalable_saver.h"

void readColor   ( Object *o, std::ifstream& stream ) ;
void readLineType( Object *o, std::ifstream& stream ) ;
void readLineSize( Object *o, std::ifstream& stream ) ;

void readPosition( Solid *s, std::ifstream& stream ) ;
void readScale( Scalable *s, std::ifstream& stream ) ;
void readPoints( Segmented *s, std::ifstream& stream ) ;
void readPoints( Curved *s, std::ifstream& stream ) ;

void loadSolid( Solid *s, std::ifstream& stream ) ;
void loadScalable( Scalable *s, std::ifstream& stream ) ;
void loadSegmented( Segmented *s, std::ifstream& stream ) ;
void loadCurved( Curved *s, std::ifstream& stream ) ;

Object *loadRoundBolt( std::ifstream& stream );
Object *loadSharpBolt( std::ifstream& stream );
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

void loadProject( std::string url )
{
   std::ifstream stream;
   stream.open( url.c_str(), std::ifstream::in );

   std::string alfa;
   stream >> alfa;

   Object *o = NULL;
   while( alfa != "" )
   {
      if( alfa == "RoundBolt" )
      {
         o = loadRoundBolt( stream );
      }
      else if( alfa == "SharpBolt" )
      {
         o = loadSharpBolt( stream );
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

      stream >> alfa ; // ;
      stream >> alfa ;
   }
}


void loadSolid( Solid *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

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
      else if( alfa == "color" )
      {
         readColor( s, stream );
      }
      stream >> alfa ;
   }
}
void loadScalable( Scalable *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

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
      else if( alfa == "color" )
      {
         readColor( s, stream );
      }
      stream >> alfa ;
   }
}

void loadCurved( Curved *c, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

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
      else if( alfa == "color" )
      {
         readColor( c, stream );
      }
      stream >> alfa ;
   }
}
void loadSegmented( Segmented *s, std::ifstream& stream )
{
   std::string alfa;

   stream >> alfa; // =
   stream >> alfa; // [

   while( alfa != "]" )
   {
      stream >> alfa; // caracteristica do objeto

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
      else if( alfa == "color" )
      {
         readColor( s, stream );
      }
      stream >> alfa ; // , ou ]
   }
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

void readPoints( Segmented* o, std::ifstream& stream )
{
   std::string alfa;
   stream >> alfa;
   float x=0;
   float y=0;

   //read = 
   stream >> alfa;

   // read set [
   stream >> alfa;

   unsigned int n = o->numPoints();
   int i = 0;
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

      stream >> alfa; //]
      stream >> alfa; // coma or ]
      i++;
   }
   // read set ]
   stream >> alfa;
}

void readPosition( Solid* o, std::ifstream& stream )
{
   std::string alfa;
   stream >> alfa;
   float x=0;
   float y=0;

   //read = 
   stream >> alfa;

   // read [

   stream >> alfa; // [
   stream >> x;
   stream >> alfa; // coma
   stream >> y;
   stream >> alfa; //]

   o->position( Point2d( x, y ) );

   // read  ]
   stream >> alfa;
}

void readScale( Scalable* o, std::ifstream& stream )
{
   std::string alfa;
   stream >> alfa;
   float x=0;
   float y=0;

   //read = 
   stream >> alfa;

   // read [

   stream >> alfa; // [
   stream >> x;
   stream >> alfa; // coma
   stream >> y;
   stream >> alfa; //]

   o->scale( Point2d( x, y ) );

   // read  ]
   stream >> alfa;
}
void readPoints( Curved* o, std::ifstream& stream )
{
   std::string alfa;
   stream >> alfa;
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
   int i = 0;
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
      stream >> alfa; //]

      if( i<n )
         o->position( i, Point2d( x, y ) );
      else
         o->addPoint( Point2d( x, y ) );

      o->positionPrevScape( i, Point2d( px, py ) );
      o->positionAftScape( i, Point2d( ax, ay ) );

      stream >> alfa; // coma or ]
      i++;
   }
   // read set ]
   stream >> alfa;
}


Object *loadRoundBolt( std::ifstream& stream )
{
   RoundBolt * o = new RoundBolt();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadSharpBolt( std::ifstream& stream )
{
   SharpBolt * o = new SharpBolt();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadPiton( std::ifstream& stream )
{
   Piton * o = new Piton();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadScrew( std::ifstream& stream )
{
   Screw * o = new Screw();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}



Object *loadOptStation( std::ifstream& stream )
{
   OptStation * o = new OptStation();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadRapel( std::ifstream& stream )
{
   Rapel * o = new Rapel();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadExpo( std::ifstream& stream )
{
   Expo * o = new Expo();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}

Object *loadText( std::ifstream& stream )
{
   Text * o = new Text();
   SolidSaver *ss  = new SolidSaver( o, "o"  );
   o->saver( ss );
   loadSolid( o, stream );
   return o;
}


Object *loadCrystal( std::ifstream& stream )
{
   Crystal * o = new Crystal();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadHole( std::ifstream& stream )
{
   Hole * o = new Hole();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBlock( std::ifstream& stream )
{
   Block * o = new Block();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadTree( std::ifstream& stream )
{
   Tree * o = new Tree();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadPalmTree( std::ifstream& stream )
{
   PalmTree * o = new PalmTree();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;

}

Object *loadBush( std::ifstream& stream )
{
   Bush * o = new Bush();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadCactus( std::ifstream& stream )
{
   Cactus * o = new Cactus();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadGrass( std::ifstream& stream )
{
   Grass * o = new Grass();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadElliptical( std::ifstream& stream )
{
   Elliptical * o = new Elliptical();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBox( std::ifstream& stream )
{
   Box * o = new Box();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
   o->saver( ss );
   loadScalable( o, stream );
   return o;
}

Object *loadBrace( std::ifstream& stream )
{
   Brace * o = new Brace();
   ScalableSaver *ss  = new ScalableSaver( o, "o"  );
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
   SegmentedSaver *ss  = new SegmentedSaver( o, "Chimney" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadDihedral( std::ifstream& stream )
{
   Dihedral * o = new Dihedral( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Dihedral" );
   o->saver( ss );
   loadSegmented( o, stream );
   return o;
}

Object *loadArete( std::ifstream& stream )
{
   Arete * o = new Arete( Point2d(0,0), Point2d(0,0) );
   SegmentedSaver *ss  = new SegmentedSaver( o, "Arete" );
   o->saver( ss );
   loadSegmented( o, stream );
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
   Stations * o = new Stations( Point2d(0,0), Point2d(0,0) );
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
