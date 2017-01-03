
#include "piton.h"
#include "cd.h"
#include "wd.h"



Piton::Piton() 
{
}


Piton::~Piton()
{
};



const Point2d & Piton::position( ) const
{
    return _position ;
} ;

void Piton::position( const Point2d & p ) 
{
    _position = p  ;
};


void Piton::draw( ) const
{
    cdInteriorStyle( CD_SOLID ) ;

    wdSector( _position._x, _position._y, 14.0f/3, 14.0f/3, 0.0, 360.0 ) ;
    wdBegin( CD_FILL ) ;
    {
        wdVertex( _position._x-6.0f/3, _position._y-2.0f/3 ) ;
        wdVertex( _position._x-36.0f/3, _position._y-8.0f/3 ) ;
        wdVertex( _position._x+2.0f/3, _position._y-8.0f/3 ) ;
        wdVertex( _position._x+6.9f/3, _position._y ) ;
        wdVertex( _position._x       , _position._y-5.0f/3 ) ;
    }
    wdEnd() ;
    long x = cdForeground( CD_WHITE ) ;
    wdSector( _position._x, _position._y, 6.0f/3, 6.0f/3, 0.0, 360.0 ) ;
    cdForeground( x ) ;


   //cdForeground( CD_WHITE );
   //cdInteriorStyle( CD_SOLID ) ;
   //wdBox( _position._x - 3, _position._x+3, _position._y - 3, _position._y+3) ;

   //cdForeground( this->color() );
   //cdInteriorStyle( CD_HOLLOW ) ;
   //wdBox( _position._x - 3, _position._x+3, _position._y - 3, _position._y+3) ;
}



void Piton::drawSelectable( )
{
    cdInteriorStyle( CD_SOLID ) ;

    wdSector( _position._x, _position._y, 14.0f/3, 14.0f/3, 0.0, 360.0 ) ;
    wdBegin( CD_FILL ) ;
    {
        wdVertex( _position._x-6.0f/3, _position._y-2.0f/3 ) ;
        wdVertex( _position._x-36.0f/3, _position._y-8.0f/3 ) ;
        wdVertex( _position._x+2.0f/3, _position._y-8.0f/3 ) ;
        wdVertex( _position._x+6.9f/3, _position._y ) ;
        wdVertex( _position._x       , _position._y-5.0f/3 ) ;
    }
    wdEnd() ;
   //cdInteriorStyle( CD_SOLID ) ;
   //wdBox( _position._x - 3, _position._x+3, _position._y - 3, _position._y+3) ;
}



void Piton::boundingBox( Point2d& min, Point2d& max ) const
{
    min = _position - Point2d(36/3,8/3);
    max = _position + Point2d(7/3,7/3);
}



Object *Piton::copy()
{
    return new Piton( *this ) ;
}
