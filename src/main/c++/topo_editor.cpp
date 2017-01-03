#include "topo_editor.h"
#include "cd.h"
#include "float.h"
#include "number_spliter.h"
#include "wd.h"

TopoEditor::TopoEditor()
{
}


TopoEditor::~TopoEditor()
{

}


void TopoEditor::draw()
{
   int n = (int)(_objects.size()) ;


   for( int i=0 ; i<n ; i++ )
   {
      cdLineStyle( CD_CONTINUOUS ) ;
      cdLineWidth( _objects[i]->lineSize() ) ;
      cdLineStyle( _objects[i]->lineType() );
      cdForeground( _objects[i]->color() );
      _objects[i]->draw();
      Point2d minzz( 0,0 );
      Point2d maxzz( 0,0 );
      _objects[i]->boundingBox( minzz, maxzz );
      cdForeground( cdEncodeColor( 128,128,128) );
      //wdBegin( CD_OPEN_LINES );
      //wdVertex( minzz._x, minzz._y );
      //wdVertex( maxzz._x, minzz._y );
      //wdVertex( maxzz._x, maxzz._y );
      //wdVertex( minzz._x, maxzz._y );
      //wdVertex( minzz._x, minzz._y );
      //wdEnd();
     //  printf( "%d:   %f, %f, %f, %f\n", _objects[i]->id(), minzz._x, maxzz._x, minzz._y, maxzz._y );
   }
}


void TopoEditor::save( std::ostream& os )
{
   int n = (int)(_objects.size()) ;

   os << "Topo = [ _version = 0 ] ;\n";

   Saver *saver ;
   for( int i=0 ; i<n ; i++ )
   {
      saver = _objects[i]->saver();
      if( saver )
         saver->save( os );
      os.flush() ;
   }
}


void TopoEditor::drawSelectable()
{
   int n = (int)(_objects.size()) ;
   int x = cdLineWidth( 1 ) ;
   unsigned char r = 0 ;
   unsigned char g = 0 ;
   unsigned char b = 0 ;


   for( int i=0 ; i<n ; i++ )
   {
      cdLineStyle( CD_CONTINUOUS ) ;
      cdLineWidth( _objects[i]->lineSize()+4 ) ;

      unsigned int id = _objects[i]->id() ;
      splitNumber( id, r, g, b ) ;
      cdForeground( cdEncodeColor( r, g, b ) ) ;
      _objects[i]->drawSelectable() ;
   }
   cdLineWidth( x ) ;
}

void TopoEditor::addObject( Object * o )      
{
   _objects.push_back( o ) ;

   unsigned int n = _objectsHistory.size();
   for( unsigned int i=n ; i>0 ; i-- )
   {
      if( _objectsHistory[i-1] == o )
         return;
   }
   _objectsHistory.push_back( o );
}

void TopoEditor::addObject( int i,  Object * o )      
{
   _objects.insert( _objects.begin() + i, o );

   unsigned int n = _objectsHistory.size();
   for( unsigned int i=n ; i>0 ; i-- )
   {
      if( _objectsHistory[i-1] == o )
         return;
   }
   _objectsHistory.push_back( o );
}

void TopoEditor::removeObject( Object * o )
{
   unsigned int n = (unsigned int)_objects.size() ;



   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _objects[i] == o )
      {
         _objects.erase( _objects.begin() + i ) ;
         return ;
      }
   }
   return ;
}
void TopoEditor::removeObject( int i )
{
   if( _objects.size() <= 0 )
      return ;

   if( _objects.size() <= (unsigned int)i )
   {
      return ;
   }

   _objects.erase( _objects.begin() + i ) ;

};



void TopoEditor::clear(  )
{
   _objects.clear();
}

void TopoEditor::selectDraw()
{
   return ;
}

Object *TopoEditor::select( int i )
{
   if( (unsigned int)i < _objects.size() )
      return _objects[i] ;

   return 0;
}

Object *TopoEditor::selectId( long int id )
{
   int n = (int)(_objects.size()) ;

   for( int i=0 ; i<n ; i++ )
   {
      if( _objects[i]->id() == id )
         return _objects[i] ;
   }
   return 0 ;
}
int TopoEditor::numObjects( )
{
   return (int) _objects.size();
}

void TopoEditor::boundingBox( Point2d& min, Point2d& max ) const
{
   min._x = min._y = DBL_MAX;
   max._x = max._y = -DBL_MAX;

   Point2d min_obj(0,0) ;
   Point2d max_obj(0,0) ;

   unsigned int n = (unsigned int)(_objects.size()) ;
   for( unsigned int i=0 ; i<n ; i++ )
   {
      Point2d min_obj(0,0) ;
      Point2d max_obj(0,0) ;
      Object* obj = _objects[i];
      obj->boundingBox( min_obj, max_obj ) ;
      updateBoundingBox( min, max, min_obj );
      updateBoundingBox( min, max, max_obj );
    //  printf( "%d:   %f, %f, %f, %f\n", obj->id(), min_obj._x, max_obj._x, min_obj._y, max_obj._y );
   }
}



void TopoEditor::moveToBegining( Object * o  )
{
   // Objetos são desenhados a partir do primeiro
   // entao levar pra frente do desenho é trazer pro fim da lista
   unsigned int n = (unsigned int)_objects.size() ;


   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _objects[i] == o )
      {
         for( unsigned int j=i ; j<(n-1); j++ )
         {
            _objects[j] = _objects[j+1] ;
         }
         _objects[n-1] = o ;
         return ;
      }
   }
}


void TopoEditor::deleteObjects()
{
   unsigned int n = _objectsHistory.size();

   for( unsigned int i=0 ; i<n ; i++ )
   {
      delete _objectsHistory[i];
      _objectsHistory[i] = 0;
   }
   _objectsHistory.clear();
   _objects.clear();
}


void TopoEditor::moveToEnd( Object * o  )
{
      // Objetos são desenhados a partir do primeiro
   // entao levar pra tras do desenho é trazer pro inicio da lista
   unsigned int n = (unsigned int)_objects.size() ;

   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _objects[i] == o )
      {
         // Aqui pode fazer j-- com unsigned j  SEM perigo
         // pois a comparação é j>0 e não j>=0
         for( unsigned int j=i ; j>0 ; j-- )
         {
            _objects[j] = _objects[j-1] ;
         }
         _objects[0] = o ;
         return ;
      }
   }
}


void TopoEditor::moveFowardOne( Object * o  )
{
   unsigned int n = (unsigned int)_objects.size() ;

   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _objects[i] == o )
      {
         if( i < n-1 )
         {
            Object *o1 = _objects[i+1] ;
            _objects[i+1] = o;
            _objects[i] = o1 ;
         }
         return ;
      }
   }
}

void TopoEditor::moveBackOne( Object * o  )
{
   unsigned int n = (unsigned int)_objects.size() ;


   for( unsigned int i=0 ; i<n ; i++ )
   {
      if( _objects[i] == o )
      {
         if( i > 0 )
         {
            Object *o1 = _objects[i-1] ;
            _objects[i-1] = o ;
            _objects[i] = o1 ;
         }
         return ;
      }
   }
}
