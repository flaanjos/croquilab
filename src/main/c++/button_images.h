//#include "chamine_bt.h"
//#include "cabo_bt.h"
//#include "aresta_bt.h"
//#include "fendaMeioCorpo_bt.h"
//#include "grampoP_bt.h"
//#include "parafuso_bt.h"
//#include "piton_bt.h"
//#include "parada_bt.h"
//#include "paradaOpcional_bt.h"
//#include "rapel_bt.h"      
//#include "expo_bt.h"
//#include "diedro_bt.h"           
//#include "fenda_bt.h"      
//#include "oposicao_bt.h"      
//#include "rampa_bt.h"
//#include "cristal_bt.h"
//#include "buraco_bt.h"
//#include "bloco_bt.h"
//#include "arvore_bt.h"
//#include "arbusto_bt.h"
//#include "cactus_bt.h"
//#include "grama_bt.h"
//#include "linha_bt.h"
//#include "texto_bt.h"
//#include "seta_bt.h"
//#include "chapeleta_bt.h"
//#include "chave_bt.h"
//#include "livre_bt.h"
//#include "palm_tree_bt.h"

#include "image_builder.h"
#include "tree_builder.h"
#include "palm_tree_builder.h"
#include "crystal_builder.h"
#include "hole_builder.h"
#include "BlockBuilder.h"
#include "dihedral_builder.h"
#include "cable_builder.h"
#include "crack_builder.h"
#include "AreteBuilder.h"
#include "oposition_builder.h"
#include "chimney_builder.h"
#include "off_width_builder.h"
#include "bush_builder.h"
#include "grass_builder.h"
#include "round_bolt_builder.h"
#include "sharp_bolt_builder.h"
#include "sharp_bolt_with_ring_builder.h"
#include "chainsBuilder.h"
#include "piton_builder.h"
#include "screw_builder.h"
#include "braces_builder.h"
#include "rapel_builder.h"
#include "expo_builder.h"
#include "opt_station_builder.h"
#include "ArrowBuilder.h"
#include "route_line_builder.h"
#include "cactus_builder.h"
#include "stations_builder.h"
#include "text_builder.h"
#include "elliptical_builder.h"
#include "box_builder.h"
#include "polygonal_builder.h"
#include "free_line_builder.h"
#include "pine_tree_builder.h"

char *
image_names[] =
{
   "Image_bt_img",
   "RoundBolt_bt_img",
   "SharpBolt_bt_img",
   "SharpBoltWithRing_bt_img",
   "Chains_bt_img",
   "Piton_bt_img",
   "Screw_bt_img",
   "Crystal_bt_img",
   "Hole_bt_img",
   "Block_bt_img",
   "Cable_bt_img",
   "Chimney_bt_img",
   "Dihedral_bt_img",
   "Arete_bt_img",
   "Crack_bt_img",
   "OffWidth_bt_img",
   "Oposition_bt_img",
  // "Blank_bt_img",
   "Tree_bt_img",
   "PalmTree_bt_img",
   "PineTree_bt_img",
   "Bush_bt_img",
   "Cactus_bt_img",
   "Grass_bt_img",
   "RouteLine_bt_img",
   "Stations_bt_img",
   "OptStation_bt_img",
   "Rapel_bt_img",
   "Expo_bt_img",
   "Text_bt_img",
   "Arrow_bt_img",
   "Brace_bt_img",
   "Elliptical_bt_img",
   "Box_bt_img",
   "Polygonal_bt_img",
   "FreeLine_bt_img"
} ;
char *
image_names_press[] =
{
   "Image_sel_bt_img",
   "RoundBolt_sel_bt_img",
   "SharpBolt_sel_bt_img",
   "SharpBoltWithRing_sel_bt_img",
   "Piton_sel_bt_img",
   "Screw_sel_bt_img",
   "Crystal_sel_bt_img",
   "Hole_sel_bt_img",
   "Block_sel_bt_img",
   "Cable_sel_bt_img",
   "Chimney_sel_bt_img",
   "Dihedral_sel_bt_img",
   "Arete_sel_bt_img",
   "Crack_sel_bt_img",
   "OffWidth_sel_bt_img",
   "Oposition_sel_bt_img",
  // "Blank_sel_bt_img",
   "Tree_sel_bt_img",
   "PalmTree_sel_bt_img",
   "PineTree_sel_bt_img",
   "Bush_sel_bt_img",
   "Cactus_sel_bt_img",
   "Grass_sel_bt_img",
   "RouteLine_sel_bt_img",
   "Stations_sel_bt_img",
   "OptStation_sel_bt_img",
   "Rapel_sel_bt_img",
   "Expo_sel_bt_img",
   "Text_sel_bt_img",
   "Arrow_sel_bt_img",
   "Brace_sel_bt_img",
   "Elliptical_sel_bt_img",
   "Box_sel_bt_img",
   "Polygonal_sel_bt_img",
   "FreeLine_sel_bt_img"
} ;

char *
button_image_files[] =
{
   "button_images\\obj\\normal\\Image_bt_img.led",
   "button_images\\obj\\normal\\RoundBolt_bt_img.led",   "button_images\\obj\\normal\\SharpBolt_bt_img.led","button_images\\obj\\normal\\SharpBoltWithRing_bt_img.led",   "button_images\\obj\\normal\\Chains_bt_img.led",   "button_images\\obj\\normal\\Piton_bt_img.led",   "button_images\\obj\\normal\\Screw_bt_img.led",
   "button_images\\obj\\normal\\Crystal_bt_img.led",   "button_images\\obj\\normal\\Hole_bt_img.led",   "button_images\\obj\\normal\\Block_bt_img.led",
   "button_images\\obj\\normal\\Cable_bt_img.led",   "button_images\\obj\\normal\\Chimney_bt_img.led",  "button_images\\obj\\normal\\Dihedral_bt_img.led",   "button_images\\obj\\normal\\Arete_bt_img.led",
   "button_images\\obj\\normal\\Crack_bt_img.led",   "button_images\\obj\\normal\\OffWidth_bt_img.led",   "button_images\\obj\\normal\\Oposition_bt_img.led", /*  "button_images\\obj\\normal\\_Blank_bt_img.led",*/
   "button_images\\obj\\normal\\Tree_bt_img.led",   "button_images\\obj\\normal\\PalmTree_bt_img.led", "button_images\\obj\\normal\\PineTree_bt_img.led",  "button_images\\obj\\normal\\Bush_bt_img.led",   "button_images\\obj\\normal\\Cactus_bt_img.led",   "button_images\\obj\\normal\\Grass_bt_img.led",
   "button_images\\obj\\normal\\RouteLine_bt_img.led",   "button_images\\obj\\normal\\Stations_bt_img.led",   "button_images\\obj\\normal\\OptStation_bt_img.led",   "button_images\\obj\\normal\\Rapel_bt_img.led",
   "button_images\\obj\\normal\\Expo_bt_img.led",   "button_images\\obj\\normal\\Text_bt_img.led",   "button_images\\obj\\normal\\Arrow_bt_img.led",   "button_images\\obj\\normal\\Brace_bt_img.led",
   "button_images\\obj\\normal\\Elliptical_bt_img.led",   "button_images\\obj\\normal\\Box_bt_img.led",   "button_images\\obj\\normal\\Polygonal_bt_img.led",   "button_images\\obj\\normal\\FreeLine_bt_img.led"
};


char *
pressed_button_image_files[] =
{
   "button_images\\obj\\selected\\_Image_sel_bt_img.led",
   "button_images\\obj\\selected\\_RoundBolt_sel_bt_img.led",   "button_images\\obj\\selected\\_SharpBolt_sel_bt_img.led",   "button_images\\obj\\selected\\_SharpBolt_sel_bt_img.led",   "button_images\\obj\\selected\\_Piton_sel_bt_img.led",   "button_images\\obj\\selected\\_Screw_sel_bt_img.led",
   "button_images\\obj\\selected\\Crystal_sel_bt_img.led",   "button_images\\obj\\selected\\Hole_sel_bt_img.led",   "button_images\\obj\\selected\\_Block_sel_bt_img.led",
   "button_images\\obj\\selected\\Cable_sel_bt_img.led",   "button_images\\obj\\selected\\_Chimney_sel_bt_img.led",   "button_images\\obj\\selected\\_Dihedral_sel_bt_img.led",   "button_images\\obj\\selected\\_Arete_sel_bt_img.led",
   "button_images\\obj\\selected\\Crack_sel_bt_img.led",   "button_images\\obj\\selected\\OffWidth_sel_bt_img.led",   "button_images\\obj\\selected\\_Oposition_sel_bt_img.led", /*  "button_images\\obj\\selected\\_Blank_sel_bt_img.led",*/
   "button_images\\obj\\selected\\_Tree_sel_bt_img.led",   "button_images\\obj\\selected\\_PalmTree_sel_bt_img.led", "button_images\\obj\\selected\\_PineTree_sel_bt_img.led",   "button_images\\obj\\selected\\_Bush_sel_bt_img.led",   "button_images\\obj\\selected\\_Cactus_sel_bt_img.led",   "button_images\\obj\\selected\\_Grass_sel_bt_img.led",
   "button_images\\obj\\selected\\_RouteLine_sel_bt_img.led",   "button_images\\obj\\selected\\_Stations_sel_bt_img.led",   "button_images\\obj\\selected\\_OptStation_sel_bt_img.led",   "button_images\\obj\\selected\\_Rapel_sel_bt_img.led",
   "button_images\\obj\\selected\\_Expo_sel_bt_img.led",   "button_images\\obj\\selected\\_Text_sel_bt_img.led",   "button_images\\obj\\selected\\_Arrow_sel_bt_img.led",   "button_images\\obj\\selected\\_Brace_sel_bt_img.led",
   "button_images\\obj\\selected\\_Elliptical_sel_bt_img.led",   "button_images\\obj\\selected\\_Box_sel_bt_img.led",   "button_images\\obj\\selected\\_Polygonal_sel_bt_img.led",   "button_images\\obj\\selected\\_FreeLine_sel_bt_img.led"
};






char *
button_hints[] =
{
   "Imagem",
   "grampo P", "chapeleta", "Chapeleta com argola", "correntes", "piton", "parafuso",
   "cristal", "buraco", "bloco",
   "cabo", "chaminé", "diedro", "aresta",
   "fenda", "fenda de meio corpo", "oposição, teto ou platô", 
   "árvore", "palmeira", "pinheiro","arbusto", "cactus", "gramíneas",
   "linha da via", "paradas", "parada opcional", "rapel",
   "lance exposto", "texto", "seta", "chaves",
   "elípse", "retângulo", "polígono", "rabisco"
} ;



Icallback *
callbacks_buttons ;


Icallback *
callbacks_canvas ;


//unsigned char *
//button_images[] =
//{
//   imagem_pix,
//   grampoP_pix, chapetela_pix, piton_pix, screw_pix,
//   cristal_pix, buraco_pix, bloco_pix,
//   cabo_pix, chamine_pix, diedro_pix, aresta_pix,
//   fenda_pix, fendaMeioCorpo_pix, oposicao_pix, rampa_pix,
//   arvore_pix, palm_tree_pix, arbusto_pix, cactus_pix, grama_pix,
//   linha_pix, parada_pix, paradaOpcional_pix, rapel_pix,
//   expo_pix, texto_pix, seta_pix, chave_pix,
//   circle_pix, square_pix, polygon_pix, rabisco_pix
//  } ;

Builder *
button_builders[] =
{
   new ImageBuilder(),
   new RoundBoltBuilder(), new SharpBoltBuilder(), new SharpBoltWithRingBuilder(), new ChainsBuilder(),new PitonBuilder(), new ScrewBuilder(),
   new CrystalBuilder(), new HoleBuilder(), new BlockBuilder(),
   new CableBuilder(), new ChimneyBuilder(), new DihedralBuilder(), new AreteBuilder(),
   new CrackBuilder(), new OffWidthBuilder(), new OpositionBuilder(), 
   new TreeBuilder(), new PalmTreeBuilder(), new PineTreeBuilder(), new BushBuilder(), new CactusBuilder(), new GrassBuilder(),
   new RouteLineBuilder() , new StationsBuilder(), new OptStationBuilder(), new RapelBuilder(),
   new ExpoBuilder(), new TextBuilder(), new ArrowBuilder(), new BraceBuilder(),
   new EllipticalBuilder(), new BoxBuilder(), new PolygonalBuilder(), new FreeLineBuilder()
  } ;
