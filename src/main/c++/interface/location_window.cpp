#include "iup.h"
#include "iupcontrols.h"
#include "main_window.h"
#include "stdio.h"
#include "route_window.h"
#include "stdlib.h"
#include "string.h"
#include "route.h"
#include <vector>

std::vector<Route*> __routes ;
Route *selected_route = 0 ;
static char st_country[512] ;
static char st_state[512] ;
static char st_city[512] ;
static char st_area[512] ;
static char st_mountain[512] ;
static char st_face[512] ;
static char st_section[512] ;
static char st_new_route_name[512] ;

Ihandle *location_dlg = NULL ;

char *location_window_title = "Localização do Croqui" ;
char *location_labels[] = { "País", "Estado", "Cidade", "Área", "Montanha", "Face", "Setor" } ;
char *face_list[] = { "Norte", "Sul", "Leste", "Oeste", "Nordeste", "Noroeste", "Sudeste", "Sudoeste" } ;
char *list_button_labels[] = { "adicionar", "editar", "remover", "subir", "descer" } ;

Ihandle* location_texts[7] ;
Ihandle* list_buttons[5] ;
Ihandle *route_list = NULL ;

int edit_country(Ihandle *self, int c, char *after)
{
   strcpy( st_country, after ) ;
   return IUP_DEFAULT ;
}
int edit_state(Ihandle *self, int c, char *after)
{
    strcpy( st_state, after ) ;
   return IUP_DEFAULT ;
}
int edit_city(Ihandle *self, int c, char *after)
{
   strcpy( st_city, after ) ; 
   return IUP_DEFAULT ;
}
int edit_area(Ihandle *self, int c, char *after)
{
   strcpy( st_area, after ) ;
   return IUP_DEFAULT ;
}
int edit_mountain(Ihandle *self, int c, char *after)
{
   strcpy( st_mountain, after ) ;
   return IUP_DEFAULT ;
}
int edit_face(Ihandle *self, int c, char *after)
{
   strcpy( st_face, after ) ;
   return IUP_DEFAULT ;

}
int edit_section(Ihandle *self, int c, char *after)
{
   strcpy( st_section, after ) ;;
   return IUP_DEFAULT ;
}

int edit_route_name(Ihandle *self, int c, char *after)
{
   if( strlen( after ) > 0 )
   {
      strcpy( st_new_route_name, after ) ;
      IupSetAttribute(list_buttons[0], IUP_ACTIVE, IUP_YES) ;
   }
   else
   {
      IupSetAttribute(list_buttons[0], IUP_ACTIVE, IUP_NO) ;
  }

   return IUP_DEFAULT ;
}
int select_route_list (Ihandle *self, char *t, int i, int v)
{
   printf( "%s\n\n", t ) ;
   if( v )
   {
      selected_route =  __routes[i-1] ;
      for( int i=1 ; i<5 ; i++ )
         IupSetAttribute(list_buttons[i], IUP_ACTIVE, IUP_YES) ;
   }
   return IUP_DEFAULT ;
};
Icallback edit_location_callbacks[] = { (Icallback)edit_country, (Icallback)edit_state,(Icallback)edit_city,(Icallback)edit_area, (Icallback)edit_mountain,(Icallback)edit_face, (Icallback)edit_section};


int add_route( Ihandle* self )
{
   static int countx =1;
   char num[16] ;
   sprintf( num, "%d", countx ) ;


   Route *r= new Route( st_new_route_name ) ;
   if( routeDialog( r ) )
   {countx++;
      printf(  "add\n\n") ;
      __routes.push_back( r ) ;
      IupSetAttribute( route_list, num, r->_name ) ;
   }
   else
   {
      delete r ;
   }

   return IUP_DEFAULT ;
}
int edit_route( Ihandle* self )
{
   if( selected_route )
   {
      routeDialog( selected_route) ;
   }
   printf(  "edit\n\n") ;
   return IUP_DEFAULT ;
}
int remove_route( Ihandle* self )
{
   printf(  "remove\n\n") ;
   return IUP_DEFAULT ;
}
int up_route( Ihandle* self )
{
   printf(  "up\n\n") ;
   return IUP_DEFAULT ;
}
int down_route( Ihandle* self )
{
   printf(  "down\n\n") ;
   return IUP_DEFAULT ;
}

Icallback list_callbacks[] = { (Icallback)add_route, (Icallback)edit_route,(Icallback)remove_route,(Icallback)up_route, (Icallback)down_route};


Ihandle* location_box()
{ 
   Ihandle *v_box = IupVbox( NULL ) ;


   for( int i=0 ; i<7 ; i++ )
   {
      Ihandle* label    = IupLabel( location_labels[i] ) ;
      location_texts[i] = IupText( NULL ) ;//callback[i] ) ;

      IupSetAttribute( label, IUP_SIZE, "50x" ) ;
      IupSetAttribute( location_texts[i], IUP_SIZE, "250x" ) ;

      IupSetCallback( location_texts[i], IUP_ACTION, edit_location_callbacks[i] ) ;

      IupAppend( v_box, IupHbox( label, location_texts[i], NULL ) ) ;
   }
   
   IupSetAttribute( v_box, IUP_MARGIN, "3x3" ) ;

   return v_box ;
}



Ihandle* route_box()
{ 
   Ihandle *v_box = IupVbox( NULL ) ;


   for( int i=0 ; i<5 ; i++ )
   {
      list_buttons[i]  = IupButton( list_button_labels[i], NULL ) ;
      IupSetAttribute( list_buttons[i], IUP_EXPAND, IUP_VERTICAL ) ;
      IupSetAttribute( list_buttons[i], IUP_SIZE, "50x" ) ;
      IupSetCallback( list_buttons[i], IUP_ACTION, list_callbacks[i] ) ;
      IupAppend( v_box, list_buttons[i] ) ;
      IupSetAttribute(list_buttons[i], IUP_ACTIVE, IUP_NO);
   }

   IupSetAttribute( v_box, IUP_GAP, "2x2" ) ;

   Ihandle* label    = IupLabel( "Nome" ) ;
   Ihandle* text_box = IupText( NULL ) ;  
   IupSetAttribute( text_box, IUP_EXPAND, IUP_YES ) ;
   IupSetAttribute( label, IUP_SIZE, "50x" ) ;
   Ihandle *route_name_box = IupHbox( label, text_box, NULL ) ;
  
   IupSetCallback( text_box, IUP_ACTION, (Icallback)edit_route_name ) ;
   
   route_list = IupList( NULL ) ;
   IupSetAttribute( route_list, IUP_EXPAND, IUP_YES ) ;
   IupSetAttribute( route_list, IUP_VISIBLE_ITEMS, "6" ) ;
  IupSetCallback( route_list, IUP_ACTION, (Icallback)select_route_list ) ;
   Ihandle *route_list_box = IupHbox( route_list, v_box, NULL ) ;

   Ihandle *v_box_2 = IupVbox( route_name_box, route_list_box, NULL ) ;
   IupSetAttribute( v_box_2, IUP_MARGIN, "3x3" ) ;
   Ihandle*frame = IupFrame( v_box_2 );

   IupSetAttribute( frame, IUP_TITLE, "Vias" ) ;

   return frame ;

}

void clearLocationDialog()
{
  st_country[0] =0;
  st_state[0] =0;
  st_city[0] =0;
  st_area[0] =0;
  st_mountain[0] =0;
  st_face[0] =0;
  st_section[0] =0;
  for( int i=0; i<7 ; i++)
  {
     IupSetAttribute( location_texts[i], IUP_VALUE, "" ) ;
  }
}
void createLocationDialog()
{
   Ihandle * b =  IupVbox( location_box(), route_box(), NULL) ;
 
   IupSetAttribute( b, IUP_MARGIN, "3x3" ) ;
   location_dlg = IupDialog( b );

   IupSetAttribute( location_dlg, IUP_TITLE, location_window_title ) ;   

}
void showLocationDialog()
{
   IupPopup(location_dlg, IUP_MOUSEPOS, IUP_MOUSEPOS ) ;
}

