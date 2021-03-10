#include "EditWideSegmentedWidth.h"


EditWideSegmentedWidth::EditWideSegmentedWidth( WideSegmented* o, float new_w, float old_w )
{
   _objects.push_back( o );
   _object = o ;
   _new_w = new_w ;  
   _old_w = old_w ;
}


EditWideSegmentedWidth::~EditWideSegmentedWidth()
{
}


void EditWideSegmentedWidth::redo()
{
   _object->width( _new_w ) ; 
}


void EditWideSegmentedWidth::undo()
{
   _object->width( _old_w ) ; 
}


