#ifndef _LINE_TYPE_PANEL__H
#define _LINE_TYPE_PANEL__H

#include "iup.h"

class LineTypePanel
{
   ~LineTypePanel() ;
   LineTypePanel( Icallback list_cb ) ;

   Ihandle *iupHandle() ;
   value( int v ) ;
   int value() ;

private:
   int value ;
}
