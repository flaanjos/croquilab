#ifndef _SCROLL_COLOR_BAR_H_
#define _SCROLL_COLOR_BAR_H_
#include "iup.h"


class ScrollColorBar
{
public:

	typedef int (*SCBcallback)( long color );

	ScrollColorBar( SCBcallback click_callback ) ;
   ~ScrollColorBar() {};

   operator Ihandle*() {return _cells;};

private:
	Ihandle* _cells;
	SCBcallback _callback ;

	static int mouseclickCallback( Ihandle* handle, int button, int pressed, int line, int column, int x, int y, char* status )  ;
	static int drawCallback(Ihandle* h, int i, int j, int xmin, int xmax, int ymin, int ymax) ;
	static int nLinesCallback( Ihandle* h );
	static int nColumnsCallback( Ihandle* h );
	static int cellHeightCallback( Ihandle* h, int i );
	static int cellWidthCallback( Ihandle* h, int j );

	static long colors[ 2000 ];
   static int nColors;
};

#endif