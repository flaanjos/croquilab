#include "edition.h"

 
addObject() ;
addT empObject( Object *o )


//*** ARETE  *************************************************************
Object *canvasMotionArete( float wx, float wy, Object *obj )
{
   float p[2] = {wx, wy } ;
   if( obj )
   {
      Arete *c = (Arete*) obj ;
      c->position( 1, p ) ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonArete( int button, int state, float wx, float wy, Object *obj )
{
   float p[2] = {wx, wy } ;
   if( !obj )
   {
      Arete *c = new Arete( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Arete *c = (Arete*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonArete_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonArete ;
  objectMotionFunction = canvasMotionArete ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** CRACK  *************************************************************
Object *canvasMotionCrack( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Crack *c = (Crack*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonCrack( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Crack *c = new Crack( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Crack *c = (Crack*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonCrack_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonCrack ;
  objectMotionFunction = canvasMotionCrack ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** CHIMNEY  ***********************************************************
Object *canvasMotionChimney( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Chimney *c = (Chimney*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonChimney( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Chimney *c = new Chimney( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Chimney *c = (Chimney*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonChimney_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonChimney ;
  objectMotionFunction = canvasMotionChimney ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** CABLE  *************************************************************
Object *canvasMotionCable( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Cable *c = (Cable*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonCable( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Cable *c = new Cable( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Cable *c = (Cable*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonCable_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonCable ;
  objectMotionFunction = canvasMotionCable ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** OPOSITION  *********************************************************
Object *canvasMotionOposition( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Oposition *c = (Oposition*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonOposition( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Oposition *c = new Oposition( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Oposition *c = (Oposition*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonOposition_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonOposition ;
  objectMotionFunction = canvasMotionOposition ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** DIHEDRAL  **********************************************************
Object *canvasMotionDihedral( float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( in_edition )
   {
      Dihedral *c = (Dihedral*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
Object *canvasButtonDihedral( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   if( !in_edition )
   {
      Dihedral *c = new Dihedral( wx, wy, wx, wy ) ;
      in_edition = c ;
      return NULL ;
   }
   else
   {
      Dihedral *c = (Dihedral*) in_edition ;
      c->position( 1, p ) ;
      in_edition = NULL ;
      return (Object*)c ;
   }
   return NULL ;
}
int buttonDihedral_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonDihedral ;
  objectMotionFunction = canvasMotionDihedral ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** ROUND BOLT  ********************************************************
Object *canvasButtonRoundBolt( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   RoundBolt* rb = new RoundBolt() ;
   rb->position( p ) ;
   return rb ;
}
int buttonRoundBolt_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonRoundBolt ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** SHARP BOLT  ********************************************************
Object *canvasButtonSharpBolt( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   SharpBolt* tree = new SharpBolt() ;
   tree->position( p ) ;
   return tree ;
}
int buttonSharpBolt_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonSharpBolt ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** TREE  **************************************************************
Object *canvasButtonTree( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Tree* tree = new Tree() ;
   tree->position( p ) ;
   return tree ;
}
int buttonTree_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonTree ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** HOLE  **************************************************************
Object *canvasButtonHole( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Hole* hole = new Hole() ;
   hole->position( p ) ;
   return hole ;
}
int buttonHole_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonHole ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** BLOCK  *************************************************************
Object *canvasButtonBlock( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Block* block = new Block() ;
   block->position( p ) ;
   return block ;
}
int buttonBlock_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonBlock ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************

//*** LINE  ***************************************************************
Object *canvasButtonLine( int button, int state, float wx, float wy )
{
//   Line* line = new Line() ;
//   line->addPoint( 0, wx, wy ) ;
//   return Line ;
   return NULL ;
}
//************************************************************************

//*** CRYSTAL  ***********************************************************
Object *canvasButtonCrystal( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Crystal* c = new Crystal() ;
   c->position( p ) ;
   return c ;
}
int buttonCrystal_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonCrystal ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
}
//************************************************************************
