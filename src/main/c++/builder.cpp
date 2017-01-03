class Builder
{
   Object *newObject( float x, float y ) ;
   bool finished( Object *o ) ;
   bool addPoint( Object *o, float x, float y ) ;
   bool moveLastPoint( Object *o, float x, float y  ) ;
}

// CLICK
{
if( single_click )
{
   if( !obj )
   {
      obj = builder->newObject( x, y ) ;
   }
   if( !builder->finished( obj ) ) 
   {
      builder->addPoint( x, y ) ;
   }
   if( builder->finished( obj ) )
   {
      obj = NULL ;
   }
}
if( double_click && obj )
{
   builder->moveLastPoint( obj, x, y  ) ;
   obj = NULL ;
}
}