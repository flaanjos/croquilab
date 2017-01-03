#include "wide_segmented_saver.h"

//fstream

WideSegmentedSaver::WideSegmentedSaver( WideSegmented* s ) : _type_name( "Segmented" )
{
   _segmented = s ;
};
WideSegmentedSaver::WideSegmentedSaver( WideSegmented* s, const std::string &type_name ) : _type_name( type_name )
{
   _segmented = s ;
};
WideSegmentedSaver::WideSegmentedSaver()
{
   _segmented = 0 ;
};
WideSegmentedSaver::~WideSegmentedSaver()
{
};
Saver* WideSegmentedSaver::copy()
{
   return new WideSegmentedSaver( _segmented, _type_name ) ;
}

Object* WideSegmentedSaver::object()
{
   return _segmented ;
}

void WideSegmentedSaver::object( Object* o ) 
{
   _segmented = (WideSegmented*)o ;
}
void WideSegmentedSaver::save( std::ostream& stream )
{

   if( _segmented )
   {
      stream << _type_name ;
      stream << " = [ _points = [ " ;

      unsigned int p=0;
      for( p=0; p<_segmented->numPoints()-1 ;p++ )
      {
         Point2d point = _segmented->position( p );
         stream << "[ ";
         stream << point._x ;
         stream << ", " ;
         stream << point._y ;
         stream << " ], ";
      }
      stream << "[ ";
      stream << _segmented->position( p )._x ;
      stream << ", " ;
      stream << _segmented->position( p )._y ;
      stream << " ] ], ";   

      stream << "_line_type = " ;
      stream << _segmented->lineType() ;

      stream << ", ";
      stream << "_line_size = " ;
      stream << _segmented->lineSize() ;

      stream << ", ";   
      stream << " _color = " ; 
      stream << _segmented->color( ) ;

      stream << ", ";   
      stream << " _width = " ;
      stream << _segmented->width( ) ;

      stream << " ] ;\n" ;
   }
};

