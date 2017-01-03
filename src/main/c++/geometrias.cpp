void cdParada( int p, int x, int y )
{
   char numero[24] ;
   sprintf( numero, "%d", p ) ;

   cdInteriorStyle( CD_SOLID ) ;
   cdSector( 0+x, 0+y, 50, 50, 0, 360 ) ; 


   cdTextAlignment (CD_CENTER ) ;

   if( p >=100 )
      cdFont( CD_HELVETICA, CD_PLAIN, 20 );
   else if( p>=10 )
      cdFont( CD_HELVETICA, CD_PLAIN, 32 );
   else
      cdFont( CD_HELVETICA, CD_PLAIN, 44 );

   cdForeground( CD_WHITE ) ;
   cdText( x,y, numero ) ; 

   cdForeground( CD_BLACK ) ;
}

void grampoP( int tx, int ty, int s )
{
   wdBegin( CD_OPEN_LINES ) ;
   wdVertex( 16*s+tx, 6*s+ty+.5 ) ;
   wdVertex( 16*s+tx, 4*s+ty ) ;
   wdVertex(  0*s+tx, 4*s+ty ) ;
   wdVertex(  0*s+tx, 0*s+ty ) ;
   wdVertex( 30*s+tx, 0*s+ty ) ;
   wdVertex( 30*s+tx, 4*s+ty ) ;
   wdVertex( 28*s+tx, 4*s+ty ) ;
   wdVertex( 28*s+tx, 6*s+ty+.5 ) ;
   wdEnd() ;

   wdBegin( CD_OPEN_LINES ) ;
   wdVertex( 20*s+tx, 6*s+ty+.5 ) ;
   wdVertex( 20*s+tx, 4*s+ty ) ;
   wdVertex( 24*s+tx, 4*s+ty ) ;
   wdVertex( 24*s+tx, 6*s+ty+.5 ) ;
   wdEnd() ;

   wdArc( 22*s+tx, 6*s+ty, 12*s, 12*s, 0, 180 ) ;
   wdArc( 22*s+tx, 6*s+ty, 4*s, 4*s, 0, 180 ) ;
}
void cdgrampoP( int tx, int ty, float s )
{
   cdBegin( CD_OPEN_LINES ) ;
   cdVertex( 16*s+tx, 6*s+ty+.5 ) ;
   cdVertex( 16*s+tx, 4*s+ty ) ;
   cdVertex(  0*s+tx, 4*s+ty ) ;
   cdVertex(  0*s+tx, 0*s+ty ) ;
   cdVertex( 29*s+tx, 0*s+ty ) ;
   cdVertex( 29*s+tx, 4*s+ty ) ;
   cdVertex( 28*s+tx, 4*s+ty ) ;
   cdVertex( 28*s+tx, 6*s+ty+.5 ) ;
   cdEnd() ;

   cdBegin( CD_OPEN_LINES ) ;
   cdVertex( 20*s+tx, 6*s+ty+.5 ) ;
   cdVertex( 20*s+tx, 4*s+ty ) ;
   cdVertex( 24*s+tx, 4*s+ty ) ;
   cdVertex( 24*s+tx, 6*s+ty+.5 ) ;
   cdEnd() ;

   cdArc( 22*s+tx, 6*s+ty, 12*s, 12*s, 0, 180 ) ;
   cdArc( 22*s+tx, 6*s+ty, 4*s, 4*s, 0, 180 ) ;
}

cdOposicao( double ax, double ay,  double bx, double by )
{
   double p1x, p1y ;
   double p2x, p2y ;
   p1x =  (bx - ax) * 16 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 16  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   p2x = -p1y / 16 * 20 ;
   p2y =  p1x / 16 * 20 ;

   double tam_linha = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   cdLine( ax, ay, bx, by ) ;
   cdLine( bx, by, bx+p2x, by+p2y ) ;
   for( int i=0 ; i<tam_linha ; i+=16 )
   {
      cdLine( ax, ay, ax+p2x, ay+p2y ) ;
      ax += p1x ;
      ay += p1y ;
   }
}
cdCristais( double ax, double ay,  double bx, double by )
{
   double p1x, p1y ;
   double p2x, p2y ;

   p1x =  (bx - ax) * 12 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 12  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

  double p3x =  (bx - ax) * 6 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
 double  p3y =  (by - ay) * 6 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;


   p2x = -p1y ;
   p2y =  p1x ;

   double tam_linha = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   //cdLine( ax, ay, bx, by ) ;
  // cdLine( bx, by, bx+p2x, by+p2y ) ;

   for( int i=0 ; i<tam_linha ; i+=36 )
   {
      //cdLine( ax, ay, ax+p2x, ay+p2y ) ;

      cdLine( ax-(1.45*p1x), ay-(1.45*p1y), ax-p3x+p2x, ay-p3y+p2y ) ;
      cdLine( ax+(.5*p1x), ay+(.5*p1y),   ax-p3x+p2x, ay-p3y+p2y ) ;

      cdLine( ax+(1.45*p1x), ay+(1.45*p1y), ax+p3x+p2x, ay+p3y+p2y ) ;
      cdLine( ax-(.5*p1x), ay-(.5*p1y),   ax+p3x+p2x, ay+p3y+p2y ) ;

      ax += p1x*3 ;
      ay += p1y*3 ;
   }
}
void cdCristal( double x, double y, double s )
{
   cdLine( x-3*s, y+3*s, x-1*s, y+3*s ) ;
   cdLine( x-1*s, y+3*s, x-1*s, y+1*s ) ;
   cdLine( x-2*s, y+2*s, x,   y+2*s ) ;
   cdLine( x,   y+2*s, x,   y   ) ;
}
void cdCristais2( double ax, double ay,  double bx, double by ) 
{
   double p1x, p1y ;
   double p2x, p2y ;
   p1x =  (bx - ax) * 5*4.3 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 5*4.3 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   double tam_linha = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   for( int i=0 ; i<tam_linha ; i+=8 )
   {
      cdCristal( ax, ay, 5 ) ;
      ax += p1x ;
      ay += p1y ;
   }
}
void cdAderencia( double ax, double ay,  double bx, double by ) 
{
   unsigned char stiple[100] = {
1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0 } ;
    cdStipple( 10, 10, stiple );


  // double p1x, p1y, p2x, p2y ;

   cdInteriorStyle( CD_STIPPLE  );  
   //cdHatch( CD_VERTICAL );
   if( ay < by )
   {
      if( ay+4*(by-ay)/6 < by-40 )
      {
         cdBegin(CD_FILL) ;
         cdVertex( ax,ay ) ;
         cdVertex( bx,by ) ;         
         cdVertex( bx, ay+4*(by-ay)/6) ;
         cdVertex( ax,ay-40 ) ;
         cdEnd() ;
      }
      else
      {
         cdBegin(CD_FILL) ;
         cdVertex( bx,by ) ;
         cdVertex( ax,ay ) ;         
         cdVertex( ax,ay-40 ) ;
         cdVertex( bx, by-40) ;
         cdEnd() ;
      }
   }
   else
   {
      if( by+4*(ay-by)/6 < ay-40 )
      {
         cdBegin(CD_FILL) ;
         cdVertex( ax,ay ) ;
         cdVertex( bx,by ) ;
         cdVertex( bx,by-40 ) ;
         cdVertex( ax,  by+4*(ay-by)/6) ;
         cdEnd() ;
      }
      else
      {
         cdBegin(CD_FILL) ;
         cdVertex( ax,ay ) ;
         cdVertex( bx,by ) ;
         cdVertex( bx,by-40 ) ;
         cdVertex( ax, ay-40) ;
         cdEnd() ;
      }
   }
        cdLineStyle( CD_CONTINUOUS );
   cdLine( ax, ay, bx, by ) ;
/*
   p1x =  (bx - ax) * 8 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 8 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   p2x =  (bx - ax) * 4 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p2y =  (by - ay) * 4 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;


   double tam_linha = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   cdLine( ax, ay, bx, by) ;
   for( int i=0 ; i<tam_linha ; i+=8 )
   {
      cdLine( ax, ay, ax, ay-7 ) ;
      cdLine( ax+p2x, ay+p2y-5, ax+p2x, ay-12 ) ;
      cdLine( ax+p1x, ay+p2y-10, ax+p1x, ay-17 ) ;

      ax += p1x ;
      ay += p1y ;
   }
*/
}

void cdAderencia2( double ax, double ay,  double bx, double by ) 
{
   double p1x, p1y, p2x, p2y ;

   p1x = (bx - ax) * 12 / fabs(bx-ax) ; 
   p1y = (by - ay) * 12 / fabs(bx-ax) ;

   p2x = (bx - ax) * 3 / fabs(bx-ax) ;
   p2y = (by - ay) * 3 / fabs(bx-ax) ;


   double intervalo = sqrt( p1x*p1x + p1y*p1y ) ;
   double tam_linha = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   cdLine( ax, ay, bx, by) ;
   if( bx>ax)
   for( int i=ax ; i<bx ; i+=p1x )
   {
      cdLine( ax+p2x, ay+p2y,    ax+p2x, ay+p2y-14 ) ;
      cdLine( ax-p2x, ay-p2y-10, ax-p2x, ay-p2y-24 ) ;
      cdLine( ax+p2x, ay+p2y-20, ax+p2x, ay+p2y-34 ) ;

      ax += p1x ;
      ay += p1y ;
   }
   else
   {
   for( int i=ax ; i>bx ; i+=p1x )
   {
      cdLine( ax+p2x, ay+p2y,    ax+p2x, ay+p2y-14 ) ;
      cdLine( ax-p2x, ay-p2y-10, ax-p2x, ay-p2y-24 ) ;
      cdLine( ax+p2x, ay+p2y-20, ax+p2x, ay+p2y-34 ) ;

      ax += p1x ;
      ay += p1y ;
   }
   }
  // cdLine( bx, by-10, bx, by-24 ) ;
}

cdDiedro( double ax, double ay,  double bx, double by ) 
{
   double px, py ;

   px =  bx - (bx - ax) * 40 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   py =  by - (by - ay) * 40  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   double px2, py2 ;
   px2 =  ax - (bx - ax) * 40 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   py2 =  ay - (by - ay) * 40  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   cdMark( px, py );
   cdBegin( CD_CLOSED_LINES );

   //(by-py), (bx-px)
      cdVertex( (int)(px - (by-py)), (int)(py + (bx-px) ) );
      cdVertex( (int)bx, (int)by ) ;
      cdVertex( (int)(px + (by-py)), (int)(py - (bx-px) ) );



      cdVertex( (int)(px2 + (ay-py2)), (int)(py2 - (ax-px2) ) );
      cdVertex( (int)ax, (int)ay ) ;
      cdVertex( (int)(px2 - (ay-py2)), (int)(py2 + (ax-px2) ) );

      cdEnd() ;
      cdLine(  (int)ax, (int)ay ,  (int)bx, (int)by ) ;

cdMark( px2, py2 );
//   x = px - by-py ;
//   y = py + bx-px ;
}

void cdBuraco2( double ax, double ay )
{
cdLine(280/15, 423/15, 308/15, 487/15);
cdLine(357/15, 406/15, 367/15, 473/15);
cdLine(443/15, 418/15, 425/15, 486/15);
cdLine(522/15, 463/15, 458/15, 513/15);
cdLine(561/15, 553/15, 487/15, 558/15);
cdLine(563/15, 601/15, 495/15, 599/15);
cdLine(527/15, 695/15, 479/15, 659/15);
cdLine(518/15, 749/15, 454/15, 690/15);
cdLine(448/15, 775/15, 411/15, 718/15);
cdLine(349/15, 794/15, 366/15, 724/15);
cdLine(268/15, 752/15, 304/15, 708/15);
cdLine(202/15, 700/15, 269/15, 676/15);
cdLine(186/15, 595/15, 241/15, 596/15);
cdLine(209/15, 481/15, 262/15, 529/15);
}
void cdBuraco( double x, double y )
{ 
   cdLine( x+10, y+18, x+ 7, y+12 ) ;
   cdLine( x+ 2, y+20, x+ 1, y+12 ) ;
   cdLine( x- 7, y+19, x- 5, y+11 ) ;
   cdLine( x-15, y+14, x- 9, y+ 8 ) ;
   cdLine( x-19, y+ 5, x-12, y+ 4 ) ;
   cdLine( x-20, y+ 0, x-13, y- 1 ) ;
   cdLine( x-16, y-10, x-11, y- 7 ) ;
   cdLine( x-15, y-15, x- 8, y-10 ) ;
   cdLine( x- 8, y-18, x- 4, y-13 ) ;
   cdLine( x+ 3, y-20, x+ 1, y-13 ) ;
   cdLine( x+11, y-16, x+ 7, y-12 ) ;
   cdLine( x+18, y-10, x+11, y- 9 ) ;
   cdLine( x+19, y+ 1, x+14, y+ 0 ) ;
   cdLine( x+17, y+12, x+11, y+ 7 ) ;
}
void cdCabo( double ax, double ay, double bx, double by )
{
   cdLineWidth( 3 ); 
   cdForeground( CD_BLACK) ;
   cdBegin(CD_BEZIER) ;
   cdVertex( 0, 0) ;

   cdVertex( 0, 0) ;
   cdVertex( 100, 0) ;

   cdVertex( 100, 100) ;

   cdVertex( 100, 300) ;
   cdVertex( 0, 100) ;

   cdVertex( 0, 300) ;

   cdVertex( 0, 380) ;
   cdVertex( 70, 300) ;

   cdVertex( 70, 380) ;

   cdVertex( 70, 430) ;
   cdVertex( 80, 380) ;

   cdVertex( 80, 430) ;
   cdEnd() ;

   cdLineWidth( 1 ); 
   cdForeground( CD_WHITE) ;
   cdBegin(CD_BEZIER) ;
   cdVertex( 0, 0) ;

   cdVertex( 0, 0) ;
   cdVertex( 100, 0) ;

   cdVertex( 100, 100) ;

   cdVertex( 100, 300) ;
   cdVertex( 0, 100) ;

   cdVertex( 0, 300) ;

   cdVertex( 0, 380) ;
   cdVertex( 70, 300) ;

   cdVertex( 70, 380) ;

   cdVertex( 70, 430) ;
   cdVertex( 80, 380) ;

   cdVertex( 80, 430) ;
   cdEnd() ;
   cdForeground( CD_BLACK) ;
}

cdFenda( double ax, double ay,  double bx, double by )
{
   double p1x, p1y ;
   double p2x, p2y ;

   p1x =  (bx - ax) * 4 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 4  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   p2x = -p1y * 3 / 4 ;
   p2y =  p1x * 3 / 4 ;


   double p3x =  ax + (bx - ax) / 2  ;
   double p3y =  ay + (by - ay) / 2  ;


     cdLine( ax, ay, p3x+p2x+p1x, p3y+p2y+p1y ) ;
      cdLine( bx, by, p3x-p2x-p1x, p3y-p2y-p1y ) ;

      cdLine( p3x-p2x-p1x, p3y-p2y-p1y ,   p3x+p2x+p1x, p3y+p2y+p1y ) ;

}

cdFendaMeioCorpo( double ax, double ay,  double bx, double by )
{
   double p1x, p1y ;
   double p2x, p2y ;

   p1x =  (bx - ax) * 4 / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;
   p1y =  (by - ay) * 4  / sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) ;

   p2x = -p1y * 3 / 4 ;
   p2y =  p1x * 3 / 4 ;

  double p4x = -p1y / 3 ;
  double p4y =  p1x / 3 ;


   double p3x =  ax + (bx - ax) / 2  ;
   double p3y =  ay + (by - ay) / 2  ;

   cdLine( ax +p4x, ay +p4y, p3x+p2x+(4/3)*p1x +p4x, p3y+p2y+(4/3)*p1y +p4y ) ;
   cdLine( bx +p4x, by +p4y, p3x-p2x/*-p1x*/ +p4x, p3y-p2y/*-p1y*/ +p4y ) ;

   cdLine( p3x-p2x/*-p1x*/ +p4x, p3y-p2y/*-p1y*/ +p4y ,   p3x+p2x+(4/3)*p1x +p4x, p3y+p2y+(4/3)*p1y +p4y ) ;

   cdLine( ax -p4x, ay -p4y, p3x+p2x/*+p1x*/ -p4x, p3y+p2y/*+p1y*/ -p4y ) ;
   cdLine( bx -p4x, by -p4y, p3x-p2x-(4/3)*p1x -p4x, p3y-p2y-(4/3)*p1y -p4y ) ;

   cdLine( p3x-p2x-(4/3)*p1x -p4x, p3y-p2y-(4/3)*p1y -p4y ,   p3x+p2x/*+p1x*/ -p4x, p3y+p2y/*+p1y*/ -p4y ) ;
}