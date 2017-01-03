#pragma once
#ifndef _ROUTE__
#define _ROUTE__ 1

class Route
{
public:
   int _num_fap_members ;
   char _first_ascent_party[2048]  ;
   char _first_ascent_date[64]  ;
   char _name[256] ;
   int _overall_grade ;
   int _crux_grade ;
   int _artificial_grade ;
   int _free_artificial_grade ;
   int _length ;
   int _exposure_rating ;
   int _duration ;

  int _num_pitches ;
  int *_pitches_lengths ;

  int _grade_system ;
  int _mesure_system ;

  Route()  ;
  Route( char *name ) ;
  ~Route(){} ;

  int setFirstAscentParty( char *fap ) ;

} ;

#endif

