#ifndef __BARESIO__
#define	__BARESIO__

#include <iostream>
#include <cstdio>
#include "queue.hpp"
/**
* @autor Alison Jhonas
* @version 1.1
* @since April 29, 2015
*/
class BaresIO
{

	std::string inputSFile;
	std::string outputSFile;
	bool stdOutput;
public:
	/**
	* Método construtor da classe BaresIO.
	* Recece os nomes dos arquivos de entrada e saida utilizados pela clsse.
	* @param inputS string como o nome do arquivo de entrada
	* @param outputS string como o nome do arquivo de saida
	* @see init()
	* @return
	*/
	BaresIO(std::string inputS, std::string outputS);
	/**
	* Método construtor da classe BaresIO.
	* Recebe o nome do arquivo de entrada utilizado pela classe e define a saida como saida padrão.
	* @param inputS string como o nome do arquivo de entrada
	* @see init()
	* @return
	*/
	BaresIO(std::string inputS);
	/**
	* Método construtor da classe BaresIO.
	* Construtor default.
	* @see init()
	* @see BaresException()
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
	* Escreve em um arquivo informado pelo usuário o resultado do calculo do bares ou um mensagem de erro.
	* @param result string como resultado do calculo do bares ou a mensagem de erro.
	* @see init()
	* @return void
	*/
	void writeFile(std::string result);
	/**
	* Lê as expressões aritiméticas de um arquivo informado pelo usuário e armazena em uma lista de expressões(string).
	* @param expresseions lista do tipo string que conterá as expressões lidas do arquivo.
	* @see init()
	* @return void
	*/
	void readFile(Queue<std::string> &expressions);
	
	/**remove todas as ocorrências do caractere c na string str*/
	void removeCharacter(std::string& str, char c);
	
};

#include "../src/baresIO.cpp"
#endif
