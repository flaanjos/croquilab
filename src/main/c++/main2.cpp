#include "iup.h"
#include "iupcontrols.h"
#include "additionalCursors.h"
#include "main_window_class.h"
#include "cd.h"

//char *obj[] = {
//"RoundBolt",
//"SharpBolt",
//"Piton",
//"Screw",
//"OptStation",
//"Rapel",
//"Expo",
//"Text",
//"Crystal",
//"Hole",
//"Block",
//"Tree",
//"PalmTree",
//"Bush",
//"Cactus",
//"Grass",
//"Elliptical",
//"Box",
//"Brace",
//"Cable",
//"Chimney",
//"Dihedral",
//"Arete",
//"Crack",
//"OffWidth",
//"Oposition",
//"Stations",
//"Arrow",
//"Polygonal",
//"RouteLine",
//"FreeLine",
//};
#include <string>
#include <sstream>

int main( int argc, char** argv ) 
{
   IupOpen( &argc, &argv ) ;

   std::string fileName;
   if( argc >= 2 )
   {
      fileName = argv[1];
   }

   IupControlsOpen() ;  
   LoadAdditionalCursors();

   MainWindow *main_window = new MainWindow( fileName ) ;

   IupMainLoop() ;

   delete main_window ;

  // IupControlsClose() ;
   IupClose();
   return 0;
}

