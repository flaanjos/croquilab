#include "segmented_saver.h"

//fstream

SegmentedSaver::SegmentedSaver( Segmented* s ) : _type_name( "Segmented" )
{
   _segmented = s ;
};
SegmentedSaver::SegmentedSaver( Segmented* s, const std::string &type_name ) : _type_name( type_name )
{
   _segmented = s ;
};
SegmentedSaver::SegmentedSaver()
{
   _segmented = 0 ;
};
SegmentedSaver::~SegmentedSaver()
{
};
Saver* SegmentedSaver::copy()
{
   return new SegmentedSaver( _segmented, _type_name ) ;
}

Object* SegmentedSaver::object()
{
   return _segmented ;
}

void SegmentedSaver::object( Object* o ) 
{
   _segmented = (Segmented*)o ;
}
void SegmentedSaver::save( std::ostream& stream )
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
      stream << " ] ;\n" ;
   }
};

