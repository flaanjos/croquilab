#include "list_manipulator.h"
#include "math.h"
#include "cd.h"
#include "wd.h"

#include "edit_list_command.h"
#include "commandStack.h"

ListManipulator* ListManipulator::_unique = 0 ;

ListManipulator * ListManipulator::instance( std::vector<Object*> list  )
{
   if( !_unique )
      _unique = new ListManipulator() ;

   _unique->_group.clear();
   for( unsigned int i = 0 ; i < list.size() ; i++ )
   {
      _unique->_group.addObject( list[i] );
   }
   _unique->restart();



   return _unique ;
}



ListManipulator::ListManipulator( ) : _bb_min(0,0),_bb_max(0,0),_bb_mid(0,0), _start(0,0), _original_pos (0,0), _original_scale (1,1)
{
   _group.clear();
   _pressed = false ;
}



void ListManipulator::restart() 
{
   _old_ss.resize( _group.children().size() );
   _old_ps.resize( _group.children().size() );
   _new_ss.resize( _group.children().size() );
   _new_ps.resize( _group.children().size() );

   for( unsigned int o = 0; o < _group.children().size(); o++)
   {
      _old_ss[o] = _group.children()[o]->scale();
      _old_ps[o] = _group.children()[o]->position();
   }
   _group.boundingBox( _bb_min, _bb_max ) ;
   _bb_mid = (_bb_max + _bb_min) / 2 ;
   _original_pos = _group.position() ;
   _original_scale = _group.scale() ;
   _pressed = false ;
   _tp_manipulation = Manipulator::NONE ;
}

bool ListManipulator::pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _group.numObjects() <= 0 )
      return false;

   _original_pos = _group.position() ;
   _original_scale = _group.scale() ;

   double radius = 2 ;
   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
   {
      _start = _bb_max ;
      _tp_manipulation = Manipulator::RESIZE_SW ;
      _pressed = true ;
      return true ;
   }

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
   {
      _start = _bb_min ;
      _tp_manipulation = Manipulator::RESIZE_NE ;
      _pressed = true ;
      return true;
   }

   if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
   {
      _start._x = _bb_min._x ;
      _start._y = _bb_max._y ;
      _tp_manipulation = Manipulator::RESIZE_SE ;
      _pressed = true ;
      return true ;
   }

   if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
   {
      _start._x = _bb_max._x ;
      _start._y = _bb_min._y ;
      _tp_manipulation = Manipulator::RESIZE_NW ;
      _pressed = true ;
      return true ;
   }
   radius = 3 ;
   if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
   {     
      _start = _bb_mid ;
      _tp_manipulation = Manipulator::MOVE_ALL ; 
      _pressed = true ;
      return true ;
   }

   _tp_manipulation = Manipulator::NONE ;
   _pressed = false ;
   return false ;
}




Manipulator::Type ListManipulator::motion( double x, double y, bool shift, bool control )
{
   if( _group.numObjects() <= 0 )
      return Manipulator::NONE ;

   if( !_pressed )
   {
      double radius = 2 ;
      if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
         return Manipulator::RESIZE_SW ;

      if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
         return Manipulator::RESIZE_NE;

      if( x<= _bb_max._x+radius && x>= _bb_max._x-radius && y<= _bb_min._y+radius && y>= _bb_min._y-radius )
         return Manipulator::RESIZE_SE ;

      if( x<= _bb_min._x+radius && x>= _bb_min._x-radius && y<= _bb_max._y+radius && y>= _bb_max._y-radius )
         return Manipulator::RESIZE_NW ;

      radius = 3 ;
      if( x<= _bb_mid._x+radius && x>= _bb_mid._x-radius && y<= _bb_mid._y+radius && y>= _bb_mid._y-radius )
         return Manipulator::MOVE_ALL ;

      return Manipulator::NONE ;
   }
   else
   {
      if(  _tp_manipulation == Manipulator::MOVE_ALL )
      {
         _group.position( Point2d( x, y ) );
         return _tp_manipulation ;
      }


      Point2d ini = _start ;
      if( shift )
      {
         ini = _bb_mid ;
      }
      bool valid = false ;

      switch( _tp_manipulation ) 
      {
      case Manipulator::RESIZE_SW :
         if( y <ini._y && x<ini._x )
         {
            valid = true ;
         }
         break ;

      case Manipulator::RESIZE_NE :         
         if( y >ini._y && x>ini._x )
         {
            valid = true ;
         }
         break;

      case Manipulator::RESIZE_SE :
         if( y <ini._y && x>ini._x )
         {
            valid = true ;
         }
         break;

      case Manipulator::RESIZE_NW :
         if( y >ini._y && x<ini._x )
         {
            valid = true ;
         }
         break;
      }

      if( valid )
      {
         double old_size_x = _bb_max._x-_bb_min._x ;
         double old_size_y = _bb_max._y-_bb_min._y ;
         double new_size_x = fabs( x-ini._x ) ;
         double new_size_y = fabs( y-ini._y ) ;
         Point2d new_scale( _original_scale._x*new_size_x / old_size_x, _original_scale._y*new_size_y / old_size_y ) ; 
         if( control )
         {
            new_scale._x = new_scale._y = (new_scale._x<new_scale._y)?new_scale._x:new_scale._y ;
            new_size_x = new_scale._x * old_size_x / _original_scale._x ;
            new_size_y = new_scale._y * old_size_y / _original_scale._y ;
         }

         if( shift )
         {
            _group.scale( new_scale ) ;
            _group.position( _original_pos ) ;
         }
         else
         { 
            if( ini._x-x > 0 )
            {
               new_size_x = -new_size_x ;
            }
            if( ini._y-y > 0 )
            {
               new_size_y = -new_size_y ;
            }

            _group.scale( new_scale ) ;
            _group.position( (Point2d( new_size_x, new_size_y) + ini + ini) / 2 ) ;
         }

            for( unsigned int o = 0; o < _group.children().size(); o++)
            {
               _new_ss[o] = _group.children()[o]->scale();
               _new_ps[o] = _group.children()[o]->position();
            }
      }
      return _tp_manipulation ;
   }
   return Manipulator::NONE ;
};

bool ListManipulator::pressKey( int c )
{
   return false; 
}
bool ListManipulator::releaseKey( int c )
{
   return false ;
}
void ListManipulator::draw() const 
{
   double zero=0, two=2 ;
   wdCanvas2World( 0, 0, &zero, NULL ) ;
   wdCanvas2World( 2, 2, &two, NULL ) ;
   double radius = two-zero ;

   Point2d min(0,0), max(0,0) ;
   _group.boundingBox( min, max ) ;
   Point2d mid = (max+min)/2 ;

   cdForeground ( cdEncodeColor( 92, 92, 92 ) ) ;
   cdInteriorStyle( CD_HOLLOW );
   _group.boundingBox( min, max );
   wdBox( min._x, max._x, min._y, max._y); 


   cdMarkSize( 4 ) ;
   cdMarkType( CD_HOLLOW_BOX ) ;
   cdForeground( CD_BLUE ) ;

   wdMark( min._x, min._y ) ;
   wdMark( max._x, min._y ) ;
   wdMark( min._x, max._y ) ;
   wdMark( max._x, max._y ) ;

   cdMarkSize( 6 ) ;
   cdMarkType( CD_HOLLOW_CIRCLE ) ;
   wdMark( mid._x, mid._y ) ;
}
bool ListManipulator::cancel() 
{
   if( _group.numObjects() <= 0 )
      return false ;

   _group.edit( _original_scale, _original_pos ) ;
   _pressed = false ;
   return true ;
}
bool ListManipulator::manipulating() const 
{
   return (_tp_manipulation != Manipulator::NONE) ;
};
bool ListManipulator::releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click)
{
   if( _pressed )  
   {
            Command* command = 0;
      switch( _tp_manipulation)
      {
      case Manipulator::NONE: break; 
      case Manipulator::MOVE_ALL:
      case Manipulator::RESIZE_E: 
      case Manipulator::RESIZE_N: 
      case Manipulator::RESIZE_S: 
      case Manipulator::RESIZE_W: 
      case Manipulator::RESIZE_NE: 
      case Manipulator::RESIZE_NW: 
     case Manipulator::RESIZE_SE: 
     case Manipulator::RESIZE_SW: command = new EditListCommand( _group.children(), _new_ps, _old_ps, _new_ss, _old_ss);
         break;
      default:
         break;
      }  ;
      if( command )
         CommandStack::insert( command );


      restart();
      _pressed = false ;
      _tp_manipulation = Manipulator::NONE ;
      return true ;
   }
   return false ;
}