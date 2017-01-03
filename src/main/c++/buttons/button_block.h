#pragma once
#ifndef _BUTTON_BLOCK__
#define _BUTTON_BLOCK__ 1

#include "block.h"
#include "bloco_bt.h"

static char button_block_hint = "Bloco" ;
static char block_img_name = "bloco" ;
Object *canvasButtonBlock( int button, int state, float wx, float wy )
{
   float p[2] = {wx, wy } ;
   Block* block = new Block() ;
   block->position( p ) ;
   return block ;
}
static int buttonBlock_cb( Ihandle* self )
{
  objectButtonFunction = canvasButtonBlock ;
  objectMotionFunction = NULL ;
  return IUP_DEFAULT; 
} 

Ihandle * createButtonBlock()
{
   Ihandle *image  = IupImage ( 24, 24, block_button_pix ) ;
   IupSetAttribute( image, "15", IUP_BGCOLOR ) ;   
   IupSetHandle( block_img_name, image ) ;

   Ihandle *button = IupButton( "", NULL ) ; 
   IupSetAttribute( button, IUP_IMAGE, block_img_name );
// IupSetAttribute( button, "FLAT", IUP_YES );    
   IupSetAttribute( button, IUP_TIP, button_block_hint );
   IupSetCallback( button, IUP_ACTION, (Icallback)blockButtonCalback ) ;

   return button ;
}

#endif