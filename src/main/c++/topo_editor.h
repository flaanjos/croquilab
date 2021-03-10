#pragma once
#ifndef _TOPO_EDITOR__
#define _TOPO_EDITOR__ 1

#include "object.h"
#include "point2d.h"
#include <vector>
#include <ostream>

class TopoEditor
{
public:
   TopoEditor() ; 
   ~TopoEditor() ;
   //Object *_background ;
   std::vector<Object *> _objects ;
   std::vector<Object *> _objectsHistory ;

   //void setBackground( Object * o ) ;
   //Object * getBackground( ) ;
   //void removeBackground( ) ;

   void addObject( int position, Object * o ) ;
   void addObject( Object * o ) ;

   void removeObject( int position ) ;
   void removeObject( Object * o  ) ;
   void clear();
   void selectDraw() ;
   void draw() ;
   void drawSelectable() ;
   void save( std::ostream& os ) ;

   void moveToEnd( Object * o  ) ;
   void moveToBegining( Object * o  ) ;
   void moveFowardOne( Object * o  ) ;
   void moveBackOne( Object * o  ) ;

   int numObjects();

   void deleteObjects(); 


   void boundingBox( Point2d& min, Point2d& max ) const ;


   Object *select( int i ) ;

   Object *selectId( long int i ) ;
};

#endif