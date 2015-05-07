#ifndef __BARESIO__
#define	__BARESIO__

#include <iostream>
#include <cstdio>
#include "queue.hpp"
/**
* @author Alison Jhonas & Gilmar Andrade
* @version 1.1
* @since April 29, 2015
*/
/**
* Classe BaresIO.
* Permite ler arquivos e escrever em arquivos ou na saída padrão. 
*
*/
class BaresIO
{

	/**
	* Nome do arquivo de entrada.
	*/
	std::string inputSFile;
	/**
	* Nome do arquivo de saída.
	*/
	std::string outputSFile;
	/**
	* Variavel de controle. 
	* Quando o varlor é true, os dados são escritos na saída padrão. Quando é false, os dados são escritos no arquivo de saída.
	*/
	bool stdOutput;
public:
	/**
	* Método construtor da classe BaresIO.
	* Recebe os nomes dos arquivos de entrada e saída utilizados pela classe.
	* @param inputS string como o nome do arquivo de entrada
	* @param outputS string como o nome do arquivo de saida
	* @see Bares::init()
	* @return
	*/
	BaresIO(std::string inputS, std::string outputS);
	/**
	* Método construtor da classe BaresIO.
	* Recebe o nome do arquivo de entrada utilizado pela classe e define a saída como saída padrão.
	* @param inputS string como o nome do arquivo de entrada
	* @see Bares::init()
	* @return
	*/
	BaresIO(std::string inputS);
	/**
	* Método construtor da classe BaresIO.
	* Construtor default.
	* @see Bares::init()
	* @see BaresException
	* @return
	*/
	BaresIO();
	/**
	* Método destrutor da classe BaresIO.
	* @return
	*/
	~BaresIO();
	/**
	* Apaga todos os dados do arquivo de saída.
	* @see BaresIO()
	* @return void
	*/
	void clearFile();

	/**
	* Escreve em um arquivo informado pelo usuário o resultado do cálculo do bares ou um mensagem de erro.
	* @param result string com o resultado do cálculo do bares ou a mensagem de erro.
	* @see Bares::init()
	* @return void
	*/
	void writeFile(std::string result);
	/**
	* Lê as expressões aritiméticas de um arquivo informado pelo usuário e armazena em uma lista de expressões(string).
	* @param expressions lista do tipo string que conterá as expressões lidas do arquivo.
	* @see Bares::init()
	* @return void
	*/
	void readFile(Queue<std::string> &expressions);
	
	/**
	 * Remove todas as ocorrências do caractere c na string str.
	 * @param str a string de onde serão removidas todas as ocorrências de um determinado caractere.
	 * @param c caractere que terá todas as ocorrências removidas da string str.
	 * @see readFile()
	 * @return void
	 */
	void removeCharacter(std::string& str, char c);
	
};

#include "../src/baresIO.cpp"
#endif
