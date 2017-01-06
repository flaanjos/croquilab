#pragma once
#ifndef _PROJECT__H_
#define _PROJECT__H_ 1

#include "route.h"
#include "location.h"
#include <vector>
#include "topoEditor.h"


class Project
{
public:
   Project() ;
   ~Project() ;

public:
   void color( long int c ) ;
   long int color() ;

   long int lineSize() const {return _line_size ;};
   void lineSize( long int ls ) {_line_size = ls ;} ;

   long int lineType() const {return _line_type ;};
   void lineType( long int lt ) {_line_type = lt ;} ;

   void fileName( const std::string& file_name ) { _file_name = file_name ; }; 
   const std::string& fileName( ) { return _file_name ; }; 

   void centerTopo();

   TopoEditor &editor() ;

private:
   long int _line_size ;
   long int _line_type ;
   long int _color ;
   Object *_selected ;
   Location   _location ;
   TopoEditor _editor ;
   std::vector<Route*>  _routes ;
   std::string _file_name;

} ;



#endif