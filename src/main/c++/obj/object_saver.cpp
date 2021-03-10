#pragma once
#ifndef _OBJECT__
#define _OBJECT__ 1
#include <vector>
#include "manipulator.h"
#include "point2d.h"



ObjectSaver::ObjectSaver ( )  
{
}



ObjectSaver::ObjectSaver( const Object& obj )
{
   _object = obj ;

}



ObjectSaver::~ObjectSaver( ) { } 
{
}



void ObjectSaver::save( FILE* file )
{
   fprintf( "Object = {\n" );

   fprintf( "\t_line_size = %d,\n" object->lineSize() );
   fprintf( "\t_line_type = %d,\n" object->lineType() );
   fprintf( "\t_color = %d\n" object->color() );
   fprintf( "};\n" );
}



