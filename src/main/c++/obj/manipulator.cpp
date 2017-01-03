#include "manipulator.h"
#include "iup.h"

bool Manipulator::pressButton( int button, double x, double y, bool shift, bool control, bool d_click) 
{
   if( button == 1 )
   {
      return pressButtonImp( button, x, y, shift, control, d_click ) ;
   }
   if( manipulating() )
   {
      return cancel() ;
   }
   return false;
}

bool Manipulator::releaseButton( int button, double x, double y, bool shift, bool control, bool d_click) 
{
   if( button == 1 )
   {

     return releaseButtonImp( button, x, y, shift, control, d_click ) ;
   }
   return false ;
}

