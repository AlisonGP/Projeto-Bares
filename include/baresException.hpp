#ifndef __BARESEXCEPTION__
#define	__BARESEXCEPTION__

#include <iostream>
#include <sstream>
#include "baresIO.hpp"
/**
* @autor Alison Jhonas & Gilmar Andrade
* @version 1.1
* @since April 29, 2015
*/
/*
* Classe BaresException.
* Localiza erros nas expressões e exibe mensagens de erro na saída padrão, ou armazena no arquivo de saída.
*/
class BaresException
{
	/*
	* Objeto da classe BaresIO.
	* Usado para escrita em arquivo ou na saída padrão.
	*/
	BaresIO baresIO;
	
public:
	/**
	 * Variavel booleana, recebe true para indicar que algum erro foi encontrado na expressão.
	 */
	bool error;
	
	/*
	* Construtor.
	* Utilizado quando existe um arquivo se saída.
	* @param ifile nome do arquivo de entrada.
	* @param ofile nome do arquivo de saída.
	* @see init()
	*/
	BaresException(std::string ifile, std::string ofile);
	/*
	* Construtor.
	* Utilizado quando não existe um arquivo se saída.
	* @param ifile nome do arquivo de entrada.
	* @see init()
	*/
	BaresException(std::string ifile);
	/*
	* Construtor default.
	*/
	BaresException();
	/*
	* Destrutor default.
	*/
	~BaresException();
	/**
	* Verifica se o operando está dentro do intervalo inteiro.
	* recebe um operando e testa se ele é maior que 32767.
	* @param operand operando que será avaliado.
	* @param pos coluna do operando na expressão.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	* @see avaliate()
	*/
	bool invalidNumericConstant(std::string operand, int pos);
	
	
	/**
	* Verifica se a operação unária ou binária possui a quantidade correta de operandos.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	* @see avaliate()
	*/
	void operandFault(int pos);
	
	/**
	* Verifica se o parâmetro é um operando inválido.
	* recebe uma string e verifica se é um operando válido.
	* @param operand string que será avaliada.
	* @param pos coluna do operando na expressão
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool invalidOperand(std::string operand, int pos);

	/**
	* Verifica se o parâmetro é um operador inválido.
	* recebe uma string e verifica se é um operador válido.
	* @param operator string que será avaliada.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool invalidOperator(std::string oper);

	/**
	* Verifica se o parâmetro é um operador inválido.
	* recebe uma string e verifica se é um operador válido.
	* @param operator string que será avaliada.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool operatorFault(std::string oper);
	/**
	* Verifica se na expressão possui algum parenteses fechamento sem o seu correspondente de abertura.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool invalidScopeClosing();
	/**
	* Verifica se na expressão possui algum parenteses abertura sem o seu correspondente de fechamento.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool openScope();
	/**
	* Verifica se na expressão possui alguma divisão por zero.
	* Verifica se o operando corresponde a divisão. Se for uma divisão, verifica se o segundo operando é zero.
	* @param oper string que representa o operador.
	* @param opnd segundo operando.
	* @param pos coluna do segundo operando.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool divideByZero(std::string oper,int opnd, int pos);
};

#include "../src/baresException.cpp"
#endif
