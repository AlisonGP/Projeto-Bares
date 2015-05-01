#ifndef __BARESEXCEPTION__
#define	__BARESEXCEPTION__

#include <iostream>
/**
* @autor Alison Jhonas
* @version 1.0
* @since April 30, 2015
*/
class BaresException
{
public:
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
	bool invalidNumericConstantException(string operand);
	bool invalidNumericConstantException(int operand);
	
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
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool invalidOperand(String operand);

	/**
	* Verifica se o parâmetro é um operador inválido.
	* recebe uma string e verifica se é um operador válido.
	* @param operator string que será avaliada.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool invalidOperator(String operator);

	/**
	* Verifica se o parâmetro é um operador inválido.
	* recebe uma string e verifica se é um operador válido.
	* @param operator string que será avaliada.
	* @return retorna verdadeiro caso haja erro e falso caso não haja.
	* @see tokenize()
	*/
	bool operatorFault(String operator);
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
	bool divideByZero();
};

#include "../src/baresException.cpp"
#endif