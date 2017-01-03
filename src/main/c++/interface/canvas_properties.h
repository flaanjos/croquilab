#ifndef _CANVAS_PROPERTIES__H__
#define _CANVAS_PROPERTIES__H__ 1

class CanvasProperties
{
public :
   CanvasProperties()
   {
      _size_x = 600 ;
      _size_y = 600 ;

      _min_viewport_x = 0 ;
      _min_viewport_y = 0 ;
      _max_viewport_x = 600 ;
      _max_viewport_y = 600 ;

      _min_worldwindow_x = 0 ;
      _min_worldwindow_y = 0 ;
      _max_worldwindow_x = 600 ;
      _max_worldwindow_y = 600 ;

      _zoom_level = 1 ;
   }
   ~CanvasProperties() ;

public:
   float SizeX() { return _size_x ; } ;
   float SizeY() { return _size_y ; } ;

   float MinViewportX() { return _min_viewport_x ; } ;
   float MinViewportY() { return _min_viewport_y ; } ;
   float MaxViewportX() { return _max_viewport_x ; } ;
   float MaxViewportY() { return _max_viewport_y ; } ;

   float MinWorldwindowX() { return _min_worldwindow_x ; } ;
   float MinWorldwindowY() { return _min_worldwindow_y ; } ;
   float MaxWorldwindowX() { return _max_worldwindow_x ; } ;
   float MaxWorldwindowY() { return _max_worldwindow_y ; } ;

   void WorldWindow( float min_x, float max_x, float min_y, float max_y )
   {
    _min_worldwindow_x = min_x ;
    _min_worldwindow_y = min_y ;
    _max_worldwindow_x = max_x ;
    _max_worldwindow_y = max_y ;
   } ;

   float ZoomLevel() { return _zoom_level ; } ;
   void ZoomLevel( float zl ) { _zoom_level = zl ; } ;

private:
   float _size_x ;
   float _size_y ;

   float _min_viewport_x ;
   float _min_viewport_y ;
   float _max_viewport_x ;
   float _max_viewport_y ;

   float _min_worldwindow_x ;
   float _min_worldwindow_y ;
   float _max_worldwindow_x ;
   float _max_worldwindow_y ;

   float _zoom_level ;

} ;

#endif