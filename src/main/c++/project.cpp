#include "project.h"
#include "string.h"
#include "point2d.h"


Project::Project()
{
   _color = 0 ;
   _line_size = 1 ;
   _line_type = 0 ;
};
Project::~Project()
{
};

void Project::color( long int c)
{
   _color = c ;
};
long int Project::color() 
{
   return _color ;
};

TopoEditor &Project::editor()
{
   return _editor ;
}

void Project::centerTopo(){
   Point2d min, max;
   _editor.boundingBox(min, max );

   Point2d center = ((max - min) / 2) + min;

   for( int i=0; i < _editor.numObjects();i++)
   {
      Point2d oldPos =       _editor.select(i)->position( );
      _editor.select(i)->position( oldPos - center );
   }


}
