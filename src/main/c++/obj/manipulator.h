#ifndef __MANIPULATOR___H__
#define __MANIPULATOR___H__


class Manipulator
{
public:
   enum Type
   {
      NONE = 0,
      MOVE_ALL ,
      MOVE_POINT,
      RESIZE_N, 
      RESIZE_S, 
      RESIZE_NS, 
      RESIZE_W, 
      RESIZE_E, 
      RESIZE_WE, 
      RESIZE_NE, 
      RESIZE_SW, 
      RESIZE_NW, 
      RESIZE_SE, 
      ROTATE,
   }  ;

   Manipulator(){};
   ~Manipulator(){};

   bool pressButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   bool releaseButton( int button, double x, double y, bool shift, bool control, bool d_click) ; 
   virtual Manipulator::Type motion( double x, double y, bool shift, bool control ) =0;
   virtual bool pressKey( int c ) {return false ;};
   virtual bool releaseKey( int c ) {return false ;};
   virtual void draw() const {};
   virtual bool cancel(){return false ;} ;
   virtual bool manipulating() const {return false ;};

protected:

   virtual bool pressButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) = 0; 
   virtual bool releaseButtonImp( int button, double x, double y, bool shift, bool control, bool d_click) = 0; 
//   virtual bool pressKeyImp( int c ) {return false ;};
//   virtual bool releaseKeyImp( int c ) {return false ;};   

} ;
#endif