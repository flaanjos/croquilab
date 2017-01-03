#include "img_drop_down_list.h"
#include "stdlib.h"
#include <vector>
#include <string>




class ImgDropDownListImp
{
public:
   ImgDropDownListImp( const ImgDropDownListContent& content, ImgDropDownList::IDDLcallback cb) ;
   ~ImgDropDownListImp() ;

   Ihandle *box() ;

   int selectedItem() ;
   void selectedItem( int i ) ;
   void active( bool a) ;

   static int cbItem( Ihandle *itm ) ;
   static int cbButton( Ihandle *bt ) ;


   Ihandle *_button ;
   Ihandle *_box ;
   Ihandle *_menu ;
   Ihandle **_itens ;
   std::vector< std::string > _label_images ;

   int _selected_item ;

   ImgDropDownList::IDDLcallback _callback ;

   int _num_itens ;
} ;


int  ImgDropDownListImp::cbItem( Ihandle *itm )
{
   ImgDropDownListImp* panel = (ImgDropDownListImp*)IupGetAttribute( itm, "ImgDropDownList" ) ;
   int key = IupGetInt( itm, IUP_KEY ) ;
   if( panel->_callback )
   {
      if( panel->_callback( key ) )
      {
            panel->selectedItem( key ) ;
      }
   }
   return IUP_DEFAULT ;
}


int  ImgDropDownListImp::cbButton( Ihandle *bt ) 
{
   ImgDropDownListImp* panel = (ImgDropDownListImp*)IupGetAttribute( bt, "ImgDropDownList" ) ;
   IupPopup( panel->_menu, IUP_MOUSEPOS, IUP_MOUSEPOS ) ;
   return IUP_DEFAULT ;
}

ImgDropDownListImp::ImgDropDownListImp(const ImgDropDownListContent& content, ImgDropDownList::IDDLcallback cb) 
{
   _num_itens = content._num_itens ;
   if( _num_itens<1 )
      throw ;

 
   _callback = cb ;

   _selected_item = 0 ;


   /* CREATING THE MENU */
   _menu = IupMenu( NULL ) ;
   _itens = new Ihandle*[ _num_itens ] ;
   for( int i=0 ; i<_num_itens ; i++ )
   {
      _itens[i] = IupItem( content._list_titles[i], NULL ) ;
      IupSetAttribute( _itens[i], IUP_IMAGE, content._list_images_on[i] ) ;
      IupSetAttribute( _itens[i], IUP_IMPRESS, content._list_images_off[i] ) ;
      IupSetAttribute( _itens[i], IUP_VALUE, IUP_OFF ) ;
      IupSetfAttribute( _itens[i], IUP_KEY, "%d", i ) ;
      IupSetAttribute( _itens[i], IUP_EXPAND, IUP_NO ) ;
      IupSetAttribute( _itens[i], "ImgDropDownList", (char*)this ) ;
      IupSetCallback( _itens[i], IUP_ACTION, (Icallback)cbItem ) ;
      IupAppend( _menu, _itens[i] ) ;

      _label_images.push_back( content._label_images[i] ) ;

   }
   IupSetAttribute( _itens[_selected_item], IUP_VALUE, IUP_ON ) ;


   _button = IupButton( NULL, NULL ) ;
   IupSetAttribute( _button, IUP_EXPAND, IUP_NO ) ;
   IupSetAttribute( _button, IUP_IMAGE, content._label_images[_selected_item] ) ;
   IupSetCallback( _button, IUP_ACTION, (Icallback)cbButton ) ;
   IupSetAttribute( _button, "FLAT", IUP_YES ) ;
   IupSetAttribute( _button, "ImgDropDownList", (char*)this ) ;

   _box = IupHbox( _button, _button, NULL ) ;
   IupSetAttributes( _box, "MARGIN=0x0, GAP=0, EXPAND=NO, ALIGNMENT=ACENTER" );
}

ImgDropDownListImp::~ImgDropDownListImp()
{
}


Ihandle *ImgDropDownListImp::box()
{
   return _box ;
}


int ImgDropDownListImp::selectedItem()
{
   return _selected_item ;
}
void ImgDropDownListImp::selectedItem( int i )
{
   if( i<0 || i>=_num_itens )
      return ;

   IupSetAttribute( _itens[_selected_item] , IUP_VALUE, IUP_OFF ) ;
   IupSetAttribute( _itens[i] , IUP_VALUE, IUP_ON ) ;
   IupSetAttribute( _button , IUP_IMAGE, (char*)(_label_images[i].c_str()) ) ;
   _selected_item = i ;
}
void ImgDropDownListImp::active( bool a )
{
   IupSetAttribute( _button , IUP_ACTIVE, (a)?IUP_YES:IUP_NO ) ;
}




Ihandle *ImgDropDownList::box()
{
   return _imp->box() ;
}

int ImgDropDownList::selectedItem()
{
   return _imp->selectedItem() ;
}

void ImgDropDownList::selectedItem( int i )
{
   _imp->selectedItem(i);
}


   ImgDropDownList::ImgDropDownList( const ImgDropDownListContent& content, IDDLcallback cb ) 
   {
      _imp = new ImgDropDownListImp( content, cb ) ; 
   }
   ImgDropDownList::~ImgDropDownList() 
   {
      delete _imp ;
   };

   void ImgDropDownList::active( bool a)
   {
      _imp->active( a ) ;
   };