#ifndef _IMG_DROP_DOWN_LIST__H_
#define _IMG_DROP_DOWN_LIST__H_
#include "iup.h"

struct ImgDropDownListContent
{
   int _num_itens ;
   char **_list_images_on ;
   char **_list_images_off ;
   char **_label_images ;
   char **_list_titles ;
} ;


class ImgDropDownListImp ;

class ImgDropDownList
{
public:
   
   typedef int (*IDDLcallback)(int i);

   ImgDropDownList( const ImgDropDownListContent& content, IDDLcallback cb ) ;
   ~ImgDropDownList() ;

   operator Ihandle*()   
                 { return box() ; } ;

   int selectedItem() ;
   void selectedItem( int i ) ;
   void active( bool ) ;

private:
  Ihandle* box() ;
  ImgDropDownListImp *_imp ;
};

#endif