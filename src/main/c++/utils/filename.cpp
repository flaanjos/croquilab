/**
 * @file filename.cpp
 * @brief Module for the manipulation of strings containing file names
 * @detailed Defines the namespace FileName with methods for the manupulation
             of NULL terminated strigs representing a filename. The filename
             can be formed by three parts: path, name and extension.
 * @author Sergio Alvares Mafra (sam@tecgraf.puc-rio.br)
 */


#include "filename.h"
#include <cstring>
#include <ctype.h>
#include "stdlib.h"
#include <algorithm>

void FileName::appendExtension( std::string& filename, std::string extension )
{
    // Garante que a nova extensão começa com um ponto
    std::string new_extension = extension;
    if (extension[0] != '.' )
    {
        new_extension = ".";
        new_extension += extension;
    }


    // Procura a extensão atual
    size_t found = filename.find_last_of(".");

    // Caso o nome nao tenha extensão nenhuma simplesmente adiciona
    if (found == std::string::npos )
    {
        filename += new_extension;
    }
    else
    {
        // Se tem extensão pega um ponteiro pra ela, esse ponteiro sempre vem com o ponto na posição 0
        std::string cur_extension = filename.substr( found );


        if (new_extension == cur_extension)
        {
            // Se a extensão é a mesma não faz nada
            return;
        }
        else
        {
            // se a extensão é diferente então adiciona uma nova no final. O nome fica com 2 extensoes pq este método é a APEND extension, se o efeito desejado nao for esse use a CHANGE extension
            filename += new_extension;
        }
    }
}



void FileName::changeExtension( std::string& filename, std::string extension )
{
    // Garante que a nova extensão começa com um ponto
    std::string new_extension = extension;
    if (extension[0] != '.' )
    {
        new_extension = ".";
        new_extension += extension;
    }

   size_t found = filename.find_last_of(".");
   if (found == std::string::npos)
   {
       // se nao tinha extensao adiciona a nova
       filename += new_extension;
       return;
   }

   // se tinha apaga a extensao, inclusive o ponto, e adiciona a nova
   filename.erase( found );
   filename += new_extension;
}



bool FileName::getFullName( std::string path, std::string& name )
{
   size_t found = path.find_last_of("/\\");
   if (found == std::string::npos)
   {
       return false;
   }
   path.erase( 0,found+1 );
   name = path;
   return true;
}



bool FileName::getName( std::string path, std::string& name )
{
   bool status = FileName::getFullName( path, name );
   if (status == false)
   {
       return false;
   }
   size_t found = name.find_last_of(".");
   if (found == std::string::npos)
   {
       return false;
   }
   name.erase( found );
   return true;
}



bool FileName::getExtension( std::string path, std::string& extension )
{
   std::string fullName;
   FileName::getFullName( path, fullName );
   size_t found = fullName.find_last_of(".");
   if (found == std::string::npos)
   {
       return false;
   }
   fullName.erase( 0, found );
   extension = fullName;
   return true;
}


bool FileName::getUpperExtension( std::string path, std::string& extension )
{
   bool status = FileName::getExtension( path, extension) ;
   if (status == false)
   {
       return false;
   }
   std::transform( extension.begin(), extension.end(), extension.begin(), toupper );
   return true;
}



bool FileName::getDirectory( std::string path, std::string& directory )
{
   size_t found = path.find_last_of("/\\");
   if (found == std::string::npos)
   {
       return false;
   }
   path.erase( found+1 );
   directory = path;
   return true;
}

bool FileName::getDirectoryAndName( std::string path, std::string& name )
{
   size_t found = path.find_last_of(".");
   if (found == std::string::npos)
   {
       name = path;
       return true;
   }
   path.erase( found );
   name = path;
   return true;
}



void FileName::split( std::string path, std::string& fullName, std::string& directory )
{
   FileName::getFullName( path, fullName );
   FileName::getDirectory( path, directory );
}

/*
* Splits the path into two components: full name and directory
* - result strings be long enough to hold the directory's name
*/
void FileName::split( std::string path, std::string& name, std::string& extension, std::string& directory )
{
   FileName::getName( path, name );
   FileName::getExtension( path, extension );
   FileName::getDirectory( path, directory );

}

std::string FileName::getName( std::string path )
{
   std::string name;
   FileName::getName( path, name );
   return name;
}
/* Update the slashes to the current system
*/
void FileName::updateSlashes( std::string& path )
{
#ifdef WIN32
   for( unsigned int i = 0; i< path.size(); i++)
   {
      if( path[i] == '/' )
      {
         path[i] = '\\' ;
      }
   }
#else
   for( unsigned int i = 0; i< path.size(); i++)
   {
      if( path[i] == '\\' )
      {
         path[i] = '/' ;
      }

   }
#endif
}
