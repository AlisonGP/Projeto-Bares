#ifndef __BARESEXCEPTION__
#define	__BARESEXCEPTION__

#include <iostream>
#include <sstream>
#include "baresIO.hpp"
/**
* @autor Alison Jhonas
* @version 1.0
* @since April 30, 2015
*/
class BaresException
{
	BaresIO baresIO;
	
public:
	bool error;
	BaresException(std::string ifile, std::string ofile);
	BaresException(std::string ifile);
	BaresException();
	~BaresException();
	/**
	* Verifica se o operando está dentro do intervalo inteiro.
	* recebe um operando e testa se ele é maior que 32767.
	* @param operand operando string ou inteiro que será avaliado.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	* @see avaliate()
	*/
	bool invalidNumericConstant(std::string operand, int pos);
	bool invalidNumericConstant(int operand);
	
	/**
	* Verifica se a operação unária ou binária possui a quantidade correta de operandos.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	* @see avaliate()
	*/
	bool operandFaultException();
	
	/**
	* Verifica se o parâmetro é um operando inválido.
	* recebe uma string e verifica se é um operando válido.
	* @param operand string que será avaliada.
	* @param pos posição do operando na expressão
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
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool divideByZero(std::string oper,int opnd, int pos);
};

#include "../src/baresException.cpp"
#endif
