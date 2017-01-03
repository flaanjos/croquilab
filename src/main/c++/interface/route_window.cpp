
#include "iup.h"
#include "iupcontrols.h"
#include "main_window.h"

#include "stdlib.h"
#include "string.h"
#include "route.h"

#define NUM_OVERALL_GRADES 12
#define NUM_CRUX_GRADES 30
#define NUM_A_GRADES 9

char *overall_grade_list[] =
{
   "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"
};
char *crux_grade_list[] =
{
   "I", "Isup", "II", "IIsup", "III", "IIIsup", "IV", "IVsup", "V", "Vsup", "VI", "VIsup",
   "VIIa", "VIIb", "VIIc", "VIIIa", "VIIIb", "VIIIc", "IXa", "IXb", "IXc", "Xa", "Xb", "Xc",
   "XIa", "XIb", "XIc", "XIIa", "XIIb", "XIIc"
};
char *A_grade_list[] =
{
   "A0", "A1", "A2", "A2+", "A3", "A3+","A4", "A4+", "A5"
};

char *exposure_grade_list[] =
{
   "E1", "E2", "E3", "E4", "E5", "E6","E7",
};

char *duration__list[] =
{
   "Esportiva", "D1 (1-3 h)", "D2 (3-4 h)", "D3 (4-6 h)", "D4  (1 dia)", "D5 (1-2 dias)", "D6 (2+ dias)" 
};



char *route_labels[] =
{
"Nome",

"Conquistadores",
"Data da conquista",

"Grau geral",
"Grau do crux",

"Grau do Artificial",
"Grau do Artificial em livre",

"Comprimento",
"Número de enfiadas"
} ;



int routeDialog( Route *r ) 
{
   char fap[2048] ;
   fap[0] = 0 ;
   if( IupGetParam("Via", NULL, NULL,
      "Nome %s\n"
      "Conquistadores (c1 ; c2 ; ...)%m\n"
      "Data da conquista %s\n"
      "Grau geral %l|-|1|2|3|4|5|6|7|8|9|10|11|12|\n" 
      "Grau do crux %l|I|Isup|II|IIsup|III|IIIsup|IV|IVsup|V|Vsup|VI|VIsup|VIIa|VIIb|VIIc|VIIIa|VIIIb|VIIIc|IXa|IXb|IXc|Xa|Xb|Xc|XIa|XIb|XIc|XIIa|XIIb|XIIc|\n" 
      "Grau do artificial %l|-|A0|A1|A2|A2+|A3|A3+|A4|A4+|A5|\n" 
      "Grau do artificial em livre %l|-|I|Isup|II|IIsup|III|IIIsup|IV|IVsup|V|Vsup|VI|VIsup|VIIa|VIIb|VIIc|VIIIa|VIIIb|VIIIc|IXa|IXb|IXc|Xa|Xb|Xc|XIa|XIb|XIc|XIIa|XIIb|XIIc|\n" 
      "Grau de exposição %l|E1|E2|E3|E4|E5|E6|E7|\n"
      "Duração %l|Esportiva|D1 (1-3h)|D2 (3-4h)|D3 (4-6h)|D4 (1 dia)|D5 (1-2 dias)|D6 (2+ dias)|\n"
      "Comprimento %i\n"
      "Número de enfiadas %i\n", r->_name, fap, r->_first_ascent_date,
      &(r->_overall_grade), &(r->_crux_grade), &(r->_artificial_grade), &(r->_free_artificial_grade),
      &(r->_exposure_rating), &(r->_duration), &(r->_length), &(r->_num_pitches) ) )
   {
      r->setFirstAscentParty( fap ) ;
      return 1 ;
   }
   return 0 ;
}








