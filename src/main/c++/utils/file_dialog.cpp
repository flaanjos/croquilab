#include "FileDialog.h"
#include <cstdlib>
#include <cstring>
//#include <fileutils.h>
#include "filename.h"
#include "stdio.h"

bool existsFile( const char *file_name )
{
   FILE* f = fopen( file_name, "r" );
   if( f )
   {
      fclose( f );
      return true;
   }
   return false;
}


FileDialog::FileDialog ()
{
    _iupFileDialog = IupFileDlg ();
    _isExtensionMandatory = false;
    _extension = "";
    IupSetAttribute( _iupFileDialog, "NOCHANGEDIR", "NO" );
    IupSetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT", "NO" );
}

FileDialog::~FileDialog()
{
    IupDestroy (_iupFileDialog);
}

void FileDialog::setChangeDir( bool changeDir )
{

    if (changeDir == false)
    {
        IupSetAttribute( _iupFileDialog, "NOCHANGEDIR", "YES" );
    }
    else
    {
        IupSetAttribute( _iupFileDialog, "NOCHANGEDIR", "NO" );
    }

}

void FileDialog::setOverwritePrompt (bool overwritePrompt)
{
    if (overwritePrompt == false)
    {
        IupSetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT", "YES" );
    }
    else
    {
        IupSetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT", "NO" );
    }

}

void FileDialog::setInitialDir (const std:: string & initialDir)
{
    IupStoreAttribute( _iupFileDialog, "DIRECTORY", initialDir.c_str() );
}

int FileDialog::promptForSaving (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo)
{
    int status = -1;
    IupStoreAttribute( _iupFileDialog, "DIALOGTYPE", "SAVE" );
    IupStoreAttribute( _iupFileDialog, "TITLE", title.c_str() );
    IupStoreAttribute( _iupFileDialog, "FILE",  file.c_str());
    IupStoreAttribute( _iupFileDialog, "FILTER", filter.c_str() );
    IupStoreAttribute( _iupFileDialog, "FILTERINFO", filterInfo.c_str() );

    _fileName = file;

    if (!_isExtensionMandatory)
    {
        IupPopup( _iupFileDialog, IUP_CENTER, IUP_CENTER );        
        status = IupGetInt( _iupFileDialog, "STATUS" );
        if( status == -1 )
            return status;

        _fileName = IupGetAttribute( _iupFileDialog, "VALUE" );
    }
    else
    {
        // guarda o valor original de noovewriteprompt e modifica pra n�o perguntar
        std::string noOverwritePrompt = IupGetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT" );
        IupSetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT", "YES");

        bool isFileSelected = false;

        while (!isFileSelected)
        {
            IupPopup( _iupFileDialog, IUP_CENTER, IUP_CENTER );
            status = IupGetInt( _iupFileDialog, "STATUS" );
            if (status == -1)
                return status;

            _fileName = IupGetAttribute( _iupFileDialog, IUP_VALUE );
            FileName::appendExtension( _fileName, _extension );

            if (noOverwritePrompt == "NO" && existsFile( _fileName.c_str() ))
            {
                std::string message = _fileName;
                message += "  j� existe.\n\nDeseja sobrescrever?\n";
                int option = IupAlarm( title.c_str(), message.c_str(), "Sim", "N�o", NULL);
                if (option == 1)
                {
                    isFileSelected = true;
                }
            }
            else
            {
                isFileSelected = true;
            }
        }

        status = 0;

        // restaura o valor original de noovewriteprompt
        IupSetAttribute( _iupFileDialog, "NOOVERWRITEPROMPT", noOverwritePrompt.c_str() );

        IupSetAttribute( _iupFileDialog, "FILE", _fileName.c_str() );
        IupSetAttribute( _iupFileDialog, IUP_VALUE, _fileName.c_str() );
    }

    return status;
}

int FileDialog::promptForOpening (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo)
{
    IupSetAttribute( _iupFileDialog, "DIALOGTYPE", "OPEN" );
    IupSetAttribute( _iupFileDialog, "TITLE", title.c_str() );
    IupSetAttribute( _iupFileDialog, "FILE", file.c_str() );
    IupSetAttribute( _iupFileDialog, "FILTER", filter.c_str() );
    IupSetAttribute( _iupFileDialog, "FILTERINFO", filterInfo.c_str() );

    IupPopup( _iupFileDialog, IUP_CENTER, IUP_CENTER );
    int status = IupGetInt( _iupFileDialog, "STATUS" );    
    if( status == -1 )
        return status;

    _fileName = IupGetAttribute( _iupFileDialog, "VALUE" );
    return status;
}

int FileDialog::promptForDirectory( const std::string& title, const std::string& dir )
{
    IupSetAttribute( _iupFileDialog, "DIALOGTYPE", "DIR" );
    IupSetAttribute( _iupFileDialog, "TITLE", title.c_str() );
    IupSetAttribute( _iupFileDialog, "FILE", dir.c_str() );

    IupPopup( _iupFileDialog, IUP_CENTER, IUP_CENTER );;
    int status = IupGetInt( _iupFileDialog, "STATUS" );
    if( status == -1 )
        return status;

    _fileName = IupGetAttribute( _iupFileDialog, "VALUE" );
    return status;
}

void FileDialog::setExtensionMandatory (bool extensionMandatory, const std::string& extension)
{
    _isExtensionMandatory = extensionMandatory;
    _extension = extension;
}

std::string FileDialog::getFileName ()
{
    return _fileName;
//    std::string value = IupGetAttribute( _iupFileDialog, "VALUE" );
//    return value;
}


