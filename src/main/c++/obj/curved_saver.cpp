#include "curved_saver.h"

//fstream

CurvedSaver::CurvedSaver( Curved* s ) : _type_name( "Curved" )
{
   _curved = s ;
}


CurvedSaver::CurvedSaver( Curved* s, const std::string &type_name ) : _type_name( type_name )
{
   _curved = s ;
}


CurvedSaver::CurvedSaver()
{
   _curved = NULL ;
}


CurvedSaver::~CurvedSaver()
{
}


Saver* CurvedSaver::copy()
{
   return new CurvedSaver( _curved, _type_name ) ;
}


Object* CurvedSaver::object()
{
   return _curved ;
}


void CurvedSaver::object( Object* o ) 
{
   _curved = (Curved*)o ;
}

void CurvedSaver::save( std::ostream& stream )
{

   if( _curved )
   {
      stream << _type_name ;
      stream << " = [ _points = [ " ;

      unsigned int p=0;
      for( p=0 ; p<_curved->numPoints()-1 ; p++ )
      {        
         Point2d prev  = _curved->positionPrevScape( p );
         Point2d point = _curved->position( p );
         Point2d aft  = _curved->positionAftScape( p );
         stream << "[ [ ";
         stream << prev._x ;
         stream << ", " ;
         stream << prev._y ;
         stream << " ], [ ";
         stream << point._x ;
         stream << ", " ;
         stream << point._y ;
         stream << " ], [ ";
         stream << aft._x ;
         stream << ", " ;
         stream << aft._y ;
         stream << " ] ],";
      }

      Point2d prev  = _curved->positionPrevScape( p );
      Point2d point = _curved->position( p );
      Point2d aft = _curved->positionAftScape( p );
      stream << "[ [ ";
      stream << prev._x ;
      stream << ", " ;
      stream << prev._y ;
      stream << " ], [ ";
      stream << point._x ;
      stream << ", " ;
      stream << point._y ;
      stream << " ], [ ";
      stream << aft._x ;
      stream << ", " ;
      stream << aft._y ;
      stream << " ] ] ], ";   

      stream << "_line_type = " ;
      stream << _curved->lineType() ;
      stream << ", ";
      stream << "_line_size = " ;
      stream << _curved->lineSize() ;
      stream << ", ";   
      stream << " _color = " ;
      stream << _curved->color( ) ;
      stream << " ] ;\n" ;
   }
};

