#ifndef _FILE_DIALOG_H
#define _FILE_DIALOG_H
/*---------------------------------------------------------------------------*/
/**
* @file FileDialog.h
* Declaracoes da classe FileDialog
*
*
* @author Flavia (flaanjso@tecgraf.puc-rio.br)
* @date 12/03/2009
*/
/*---------------------------------------------------------------------------*/

#include <string>
#include "iup.h"


/** @class FileDialog
* Classe para selecionar arquivo atravez de uma janela.
*/

class FileDialog
{
public :
    /**
    * Construtor padrao.
    */
    FileDialog();

    /**
    * Destrutor padrao.
    */
    ~FileDialog();


    /**
    * Define se o diret�rio inicial da pr�xima utiliza��o do m�dulo deve ser modificado para
    * corresponder ao diret�rio selecionado na �ltima navega��o.
    * A op��o s� � v�lida para esta instancia da classe, mas o diret�rio, se alterado, ser� alterado
    * em qualquer inst�ncia da classe.
    * @param changeDir [true] se deve modificar, [false] se n�o deve.
    */
    void setChangeDir( bool changeDir );

    /**
    * Define se o m�todo promptForSaving deve abrir uma janela consultando sobre o desejo de sobrescrever o
    * arquivo selecionado quando este j� existe.
    * @param overwritePrompt [true] se deve modificar, [false] se n�o deve.
    */
    void setOverwritePrompt (bool overwritePrompt);

    /**
    * Define o diret�rio inicial da janela quando aberta. S� vale para esta inst�ncia da classe.
    * arquivo selecionado quando este j� existe.
    * @param initialDir Diret�rio inicial
    */
    void setInitialDir (const std:: string & initialDir);

    /**
    * Abre uma janela para sele��o de um arquivo de escrita. Permite sele��o de arquivos n�o existentes e, se configurado assim, pergunta sobre o desejo de sobrescrever um arquivo j� existente.
    * Tamb�m, se configurado assim, imp�em uma extens�o ao arquivo novo.
    * @param title T�tulo da janela
    * @param file Sugest�o de nome que aparece inicialmente na janela. Se o nome tiver um diret�rio ent�o a janela ira iniciar neste diret�rio ignorando o que tenha sido passado em setInitialDir.
    * @param filter Filtros para sele��o do nome. Mais de um filtro pode ser passado na mesma string desde que estejam separados por ';'. Ex: "*.bmp;*.jpg"
    * @param filterInfo Descri��o do filtro. Mais de uma descri��o pode ser passada na mesma string desde que estejam separadas por ';'. Ex: "Bitmap file;JPEG file"
    * @return [-1] para cancelamento da janela, [0] para sele��o de arquivo pr�-existente, [1] para sele��o de arquivo novo.
    */
    int promptForSaving (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo);

    /**
    * Abre uma janela para sele��o de um arquivo de escrita. S� permite a sele��o de arquivos pr�-existentes
    * @param title T�tulo da janela
    * @param file Sugest�o de nome que aparece inicialmente na janela. Se o nome tiver um diret�rio ent�o a janela ira iniciar neste diret�rio ignorando o que tenha sido passado em setInitialDir.
    * @param filter Filtros para sele��o do nome. Mais de um filtro pode ser passado na mesma string desde que estejam separados por ';'. Ex: "*.bmp;*.jpg"
    * @param filterInfo Descri��o do filtro. Mais de uma descri��o pode ser passada na mesma string desde que estejam separadas por ';'. Ex: "Bitmap file;JPEG file"
    * @return [-1] para cancelamento da janela, [0] para sele��o de arquivo pr�-existente.
    */
    int promptForOpening (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo);

    /**
    * Abre uma janela para sele��o de um diret�rio. S� permite a sele��o de diret�rios pr�-existentes embora, em alguns sistemas, tenha op��o de criar um diret�rio novo e selecion�-lo em seguida.
    * @param title T�tulo da janela
    * @param dir Sugest�o de diret�rio inicial. Se n�o for vazio ent�o a janela ir� iniciar neste diret�rio ignorando o que tenha sido passado em setInitialDir.
    * @return [-1] para cancelamento da janela, [0] para sele��o de diret�rio pr�-existente.
    */
    int promptForDirectory( const std::string& title, const std::string& dir );

    /**
    * Define se a fun��o promptForSaving deve impor uma extens�o ao arquivo selecionado.
    * @param extensionMandatory [true] se a extens�o deve ser imposta, [false] caso contr�rio.
    * @param extension String que ser� concatenada ao arquivo selecionado caso este j� n�o termine desta forma. Ignorado se a op��o for false.
    */
    void setExtensionMandatory( bool extensionMandatory, const std::string& extension );

     /**
    * Retorna o arquivo ou diret�rio selecionado em uma chamada pr�via de promptFor_x_x_x_ .
    * @return Arquivo ou diret�rio selecionado, se n�o houve chamada pr�via a promptFor_x_x_x_ ou se houve e ela foi cancelada ent�o o conte�do do retorno � imprevis�vel.
    */
    std::string getFileName ();

private:

    Ihandle* _iupFileDialog;

    bool _isExtensionMandatory;

    std::string _extension;

    std::string _fileName;

};


#endif

