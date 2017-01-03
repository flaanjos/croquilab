#include "route.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
Route::Route()
{
   _num_fap_members ;
   _first_ascent_party[0]=0  ;
   _first_ascent_date[0]=0  ;
   _name[0]=0 ;
   _overall_grade=0 ;
   _crux_grade=0 ;
   _artificial_grade=0 ;
   _free_artificial_grade=0 ;
   _length=0 ;
   _exposure_rating=0 ;
   _duration=0 ;
   _num_pitches = 1 ;
   _pitches_lengths = NULL;

   _grade_system = 0 ;
   _mesure_system = 0 ;
}

Route::Route( char *name )
{
   _num_fap_members =0;
   _first_ascent_party[0]=0  ;
   _first_ascent_date[0]=0  ;
   strcpy( _name, name ) ;
   _overall_grade=0 ;
   _crux_grade=0 ;
   _artificial_grade=0 ;
   _free_artificial_grade=0 ;
   _length=0 ;
   _exposure_rating=0 ;
   _duration=0 ;

   _num_pitches = 1 ;
   _pitches_lengths = NULL;

   _grade_system = 0 ;
   _mesure_system = 0 ;

}

char * str_trim( char * str ) 
{
   while( *str == ' ' )
   {
      str ++ ;
   }  

   char *end = str+strlen(str)-1 ;
   while( *end == ' ' )
   {
      *end = '\0' ;
      end -- ;
   }
   return str ;
};
void str_up( char *str )
{
 //  while( *str != '\0' )
 //  {
  //    toupper( *str ) ;
  //    str ++ ;
 //  }   
}

int Route::setFirstAscentParty( char *fap ) 
{
   _first_ascent_party[0] = '\0' ;
   _num_fap_members = 0 ;

   char *fam = strtok( fap, ";\n" ) ;
   while( fam )
   {
      fam = str_trim( fam ) ;
      str_up( fam ) ;
      sprintf( _first_ascent_party, "%s\n%s", _first_ascent_party, fam ) ;
      _num_fap_members++ ;
      fam = strtok( NULL, ";\n" ) ;

   }
   return _num_fap_members ;
}



