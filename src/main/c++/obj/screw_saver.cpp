#include "screw_saver.h"

//fstream

   ScrewSaver::ScrewSaver( Screw* screw )
   {
      _screw = screw ;
   };
   ScrewSaver::ScrewSaver()
   {
      _screw = NULL ;
   };
   ScrewSaver::~ScrewSaver()
   {
   };

   void ScrewSaver::save( std::ostream& stream )
   {
      
      if( _screw )
      {
         stream << "Screw = [ _position = [ " ;
         stream << _screw->position()._x ;
         stream << ", " ;
         stream << _screw->position()._y ;
         stream << "] ] ;\n" ;
      }
   };

