#pragma once
#ifndef __PAGE__H__
#define __PAGE__H__ 0

class Page
{
public:
   Page() ;
   ~Page() {};

   enum H_Alignment
   {
      HCENTER,
      HLEFT,
      HRIGHT,
   } ;
   enum V_Alignment
   {
      VCENTER,
      VTOP,
      VBOTTOM,
   } ;
   enum DefaultSizes
   {
      A0,
      A1,
      A2,
      A3,
      A4,
      A5,
      LETTER,
      LEGAL
   } ;
   void fitImageInCm( double img_w, double img_h, int &xmin, int &xmax, int &ymin, int &ymax) ;
   void fitImageInDots( double img_w, double img_h, int &xmin, int &xmax, int &ymin, int &ymax) ;
   void setDimenisions( DefaultSizes dp, bool landscape=false ) ;
   void setDimenisions( float w, float h ) ;

public:
   float paper_h ;
   float paper_w ;
   float paper_left_margin ;
   float paper_right_margin ;
   float paper_top_margin ;
   float paper_bottom_margin ;
   H_Alignment image_h_alignment ;
   V_Alignment image_v_alignment ;
   int image_resolution ;
};
#endif
