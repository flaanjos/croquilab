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
#include <iup.h>


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
    * Define se o diretório inicial da próxima utilização do módulo deve ser modificado para
    * corresponder ao diretório selecionado na última navegação.
    * A opção só é válida para esta instancia da classe, mas o diretório, se alterado, será alterado
    * em qualquer instância da classe.
    * @param changeDir [true] se deve modificar, [false] se não deve.
    */
    void setChangeDir( bool changeDir );

    /**
    * Define se o método promptForSaving deve abrir uma janela consultando sobre o desejo de sobrescrever o
    * arquivo selecionado quando este já existe.
    * @param overwritePrompt [true] se deve modificar, [false] se não deve.
    */
    void setOverwritePrompt (bool overwritePrompt);

    /**
    * Define o diretório inicial da janela quando aberta. Só vale para esta instância da classe.
    * arquivo selecionado quando este já existe.
    * @param initialDir Diretório inicial
    */
    void setInitialDir (const std:: string & initialDir);

    /**
    * Abre uma janela para seleção de um arquivo de escrita. Permite seleção de arquivos não existentes e, se configurado assim, pergunta sobre o desejo de sobrescrever um arquivo já existente.
    * Também, se configurado assim, impõem uma extensão ao arquivo novo.
    * @param title Título da janela
    * @param file Sugestão de nome que aparece inicialmente na janela. Se o nome tiver um diretório então a janela ira iniciar neste diretório ignorando o que tenha sido passado em setInitialDir.
    * @param filter Filtros para seleção do nome. Mais de um filtro pode ser passado na mesma string desde que estejam separados por ';'. Ex: "*.bmp;*.jpg"
    * @param filterInfo Descrição do filtro. Mais de uma descrição pode ser passada na mesma string desde que estejam separadas por ';'. Ex: "Bitmap file;JPEG file"
    * @return [-1] para cancelamento da janela, [0] para seleção de arquivo pré-existente, [1] para seleção de arquivo novo.
    */
    int promptForSaving (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo);

    /**
    * Abre uma janela para seleção de um arquivo de escrita. Só permite a seleção de arquivos pré-existentes
    * @param title Título da janela
    * @param file Sugestão de nome que aparece inicialmente na janela. Se o nome tiver um diretório então a janela ira iniciar neste diretório ignorando o que tenha sido passado em setInitialDir.
    * @param filter Filtros para seleção do nome. Mais de um filtro pode ser passado na mesma string desde que estejam separados por ';'. Ex: "*.bmp;*.jpg"
    * @param filterInfo Descrição do filtro. Mais de uma descrição pode ser passada na mesma string desde que estejam separadas por ';'. Ex: "Bitmap file;JPEG file"
    * @return [-1] para cancelamento da janela, [0] para seleção de arquivo pré-existente.
    */
    int promptForOpening (const std::string& title, const std::string& file, const std::string& filter, const std::string& filterInfo);

    /**
    * Abre uma janela para seleção de um diretório. Só permite a seleção de diretórios pré-existentes embora, em alguns sistemas, tenha opção de criar um diretório novo e selecioná-lo em seguida.
    * @param title Título da janela
    * @param dir Sugestão de diretório inicial. Se não for vazio então a janela irá iniciar neste diretório ignorando o que tenha sido passado em setInitialDir.
    * @return [-1] para cancelamento da janela, [0] para seleção de diretório pré-existente.
    */
    int promptForDirectory( const std::string& title, const std::string& dir );

    /**
    * Define se a função promptForSaving deve impor uma extensão ao arquivo selecionado.
    * @param extensionMandatory [true] se a extensão deve ser imposta, [false] caso contrário.
    * @param extension String que será concatenada ao arquivo selecionado caso este já não termine desta forma. Ignorado se a opção for false.
    */
    void setExtensionMandatory( bool extensionMandatory, const std::string& extension );

     /**
    * Retorna o arquivo ou diretório selecionado em uma chamada prévia de promptFor_x_x_x_ .
    * @return Arquivo ou diretório selecionado, se não houve chamada prévia a promptFor_x_x_x_ ou se houve e ela foi cancelada então o conteúdo do retorno é imprevisível.
    */
    std::string getFileName ();

private:

    Ihandle* _iupFileDialog;

    bool _isExtensionMandatory;

    std::string _extension;

    std::string _fileName;

};


#endif

