#include "group_saver.h"




GroupSaver::GroupSaver( Group* g ) : _type_name( "Group" )
{
   _group = g ;
}

GroupSaver::GroupSaver( Group* g, const std::string &type_name ) : _type_name( type_name )
{
   _group = g ;
}

GroupSaver::GroupSaver()
{
   _group = NULL ;
}

GroupSaver::~GroupSaver()
{
}

Saver* GroupSaver::copy()
{
   return new GroupSaver() ;
}

Object* GroupSaver::object()
{
   return _group ;
}

void GroupSaver::object( Object* o ) 
{
   _group = (Group*)o ;
}

void GroupSaver::save( std::ostream& stream )
{
   if( _group )
   {
      for( unsigned int i = 0 ; i < _group->numObjects() ; i++ )
      {
         Saver* saver = _group->object( i )->saver() ;
         saver->save( stream );
      }
   }
}

