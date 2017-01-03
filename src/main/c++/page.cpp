#include "page.h"

Page::Page() 
{
   paper_h = 29.7f;
   paper_w = 21.0f ;
   paper_left_margin = 1.5 ;
   paper_right_margin =1.5;
   paper_top_margin =1.5;
   paper_bottom_margin = 1.5;
   image_h_alignment = HCENTER ;
   image_v_alignment = VCENTER ;
   image_resolution =300;

}

void Page::fitImageInDots( double img_w, double img_h, int &xmin, int &xmax, int &ymin, int &ymax) 
{
   // avaiable width and height in the page
   double free_w = paper_w-paper_left_margin-paper_right_margin ; 
   double free_h = paper_h-paper_top_margin-paper_bottom_margin ; 

   // figures if maximum fit is limited by w or h
   double ratio = free_w / img_w ;
   if( ratio * img_h > free_h )
      ratio = free_h/img_h ;

   // Changes the image size according to maximum fit
   img_w = ratio * img_w ;
   img_h = ratio * img_h ;

   double xminf=0, xmaxf=0, yminf=0, ymaxf=0 ;
   // Positions the image
   if( image_h_alignment == HLEFT )
   {
      xminf = paper_left_margin ;
      xmaxf = paper_left_margin + img_w ;
   }
   else if( image_h_alignment == HRIGHT )
   {
      xminf = paper_w - paper_right_margin - img_w ;
      xmaxf = paper_w - paper_right_margin ;
   }
   else //if( image_h_alignment == HCENTER )
   {
      xminf = paper_w / 2 - img_w / 2 ;
      xmaxf = paper_w / 2 + img_w / 2 ;
   }

   if( image_v_alignment == VTOP )
   {
      ymaxf = paper_h - paper_top_margin ;
      yminf = paper_h - paper_top_margin - img_h ;
   }
   else if( image_v_alignment == VBOTTOM )
   {
      yminf = paper_bottom_margin  ;
      ymaxf = paper_bottom_margin + img_h;
   }
   else //if( image_v_alignment == VCENTER )
   {
      yminf = paper_h / 2 - img_h / 2 ;
      ymaxf = paper_h / 2 + img_h / 2 ;
   }

   // converts image position to dots
   xmin = (int)(xminf*(image_resolution/2.54)) ;
   xmax = (int)(xmaxf*(image_resolution/2.54)) ;
   ymin = (int)(yminf*(image_resolution/2.54)) ;
   ymax = (int)(ymaxf*(image_resolution/2.54)) ;
};

void Page::fitImageInCm( double img_w, double img_h, int &xmin, int &xmax, int &ymin, int &ymax) 
{
   // avaiable width and height in the page
   double free_w = paper_w-paper_left_margin-paper_right_margin ; 
   double free_h = paper_h-paper_top_margin-paper_bottom_margin ; 

   // figures if maximum fit is limited by w or h
   double ratio = free_w / img_w ;
   if( ratio * img_h > free_h )
      ratio = free_h/img_h ;

   // Changes the image size according to maximum fit
   img_w = ratio * img_w ;
   img_h = ratio * img_h ;

   double xminf=0, xmaxf=0, yminf=0, ymaxf=0 ;
   // Positions the image
   if( image_h_alignment == HLEFT )
   {
      xminf = paper_left_margin ;
      xmaxf = paper_left_margin + img_w ;
   }
   else if( image_h_alignment == HRIGHT )
   {
      xminf = paper_w - paper_right_margin - img_w ;
      xmaxf = paper_w - paper_right_margin ;
   }
   else //if( image_h_alignment == HCENTER )
   {
      xminf = paper_w / 2 - img_w / 2 ;
      xmaxf = paper_w / 2 + img_w / 2 ;
   }

   if( image_v_alignment == VTOP )
   {
      ymaxf = paper_h - paper_top_margin ;
      yminf = paper_h - paper_top_margin - img_h ;
   }
   else if( image_v_alignment == VBOTTOM )
   {
      yminf = paper_bottom_margin  ;
      ymaxf = paper_bottom_margin + img_h;
   }
   else //if( image_v_alignment == VCENTER )
   {
      yminf = paper_h / 2 - img_h / 2 ;
      ymaxf = paper_h / 2 + img_h / 2 ;
   }


   xmin = (int)xminf ;
   xmax = (int)xmaxf ;
   ymin = (int)yminf ;
   ymax = (int)ymaxf ;
};


void Page::setDimenisions( float w, float h )
{
   paper_h = h;
   paper_w = w;
}
void Page::setDimenisions( DefaultSizes dp, bool landscape )
{
   switch( dp )
   {
   case A0: paper_w=84.1f; paper_h=118.7f; break;
   case A1: paper_w=59.4f; paper_h=84.1f; break;
   case A2: paper_w=42.0f; paper_h=59.4f; break;
   case A3: paper_w=29.7f; paper_h=42.0f; break;
   case A4: paper_w=21.0f; paper_h=29.7f; break;
   case A5: paper_w=14.8f; paper_h=21.0f; break;
   case LETTER: paper_w=21.6f; paper_h=27.9f; break;
   case LEGAL: paper_w=21.6f; paper_h=35.6f; break;
   } ;
   if( landscape )
   {
      float x = paper_w ;
      paper_w = paper_h ;
      paper_h = x ;
   }
}
