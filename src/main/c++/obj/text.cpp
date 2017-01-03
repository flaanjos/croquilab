#include "text.h"
#include "text_manipulator.h"
#include "cd.h"
#include "wd.h"


Text::Text() 
{
    _size = 12;
}


Text::~Text()
{
};


const Point2d & Text::position( ) const
{
    return _position ;
}


void Text::position( const Point2d & p ) 
{
    _position = p ;
}


void Text::draw( ) const
{
    cdTextAlignment( CD_WEST );
    wdVectorCharSize( _size ) ; 
    cdLineCap( CD_CAPROUND ) ;
    cdLineJoin( CD_ROUND ) ;
    char *txt = new char[ _text.size()+1 ] ;
    strcpy( txt, _text.c_str() ) ;
    cdLineWidth( lineSize() ) ;
    wdMultiLineVectorText( _position._x, _position._y, txt ); 
    delete txt ;
}


void Text::drawSelectable()
{
    cdTextAlignment( CD_WEST );
    wdVectorCharSize( _size ) ; 
    cdLineCap( CD_CAPROUND ) ;
    cdLineJoin( CD_ROUND ) ;
    char *txt = new char[ _text.size()+1 ] ;
    strcpy( txt, _text.c_str() ) ;
    cdLineWidth( lineSize()+6 ) ;
    wdMultiLineVectorText( _position._x, _position._y, txt ); 
    delete txt ;
}


void Text::boundingBox( Point2d& min, Point2d& max ) const
{
   if( _text.size() == 0)
   {
      min = max = _position;
      return;
   }

    char *txt = new char[ _text.size() + 1 ] ;
    strcpy( txt, _text.c_str() ) ;
    wdVectorCharSize( _size ) ; 
    cdLineWidth( lineSize()+6 ) ;
    cdTextAlignment( CD_WEST );
    double rect[10];
    wdGetVectorTextBounds( txt, _position._x, _position._y, rect );

    min._x = max._x = rect[0];
    min._y = max._y = rect[1];

    for( int i = 0 ; i <  4 ; i++ )
    {
       updateBoundingBox( min, max, Point2d( rect[2*i], rect[2*i+1] ) ) ;
    }
 
    delete txt ;
}


const std::string &Text::text()
{
    return _text ;
}


void Text::text( const std::string& t )
{
    _text = t ;

}


Manipulator * Text::manipulator()
{
    return TextManipulator::instance( this ) ;
}


Object *Text::copy()
{
    return new Text( *this ) ;
}