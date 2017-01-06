#include "project.h"

bool save( Project *project )
{
   int n =  project->_editor.numObjects();

   for( int i=0 ; i<n ; i++ )
   {
      Object *o = project->_editor.select( i );
      Saver *s = o->saver();
      if( s )
      {
         s->save();
      }
   }
}