#ifndef __BARES__
#define	__BARES__
#include "stack.hpp"
#include "queue.hpp"
#include <string>
#include <sstream>
#include <stdlib.h>
#include "baresIO.hpp"
#include "baresException.hpp"
/**
* @autor Alison Jhonas & Gilmar Andrade
* @version 1.1
* @since April 21, 2015
*/
/**
 * Classe Bares. 
 * (Basic ARithmetic Expression Evaluator based on Stacks). Faz a tokenização, conversão de infixa para posfixa e avaliação de um conjunto de expressões aritméticas. 
 * 
 */
class Bares{
	/**
	 * Fila de strings.
	 * Cada string será convertida em uma expressão posfixa e avaliada. 
	 */
	Queue<std::string> expressionsQueue;
	/**
	 * Expressão infixa.
	 * Variavel axiliar. Fila que é usada para converter string em expressão infixa.
	 */
	Queue<std::string> expressionINF;
	/**
	 * Expressão Posfixa.
	 * Variável auxiliar. Fila que é usada para converter expressão infixa em posfixa.
	 */
	Queue<std::string> expressionPOS;
	/**
	 * Operadores.
	 * Variável auxiliar. Pilha de operadores utilizada na conversão expressão infixa em posfixa.
	 */
	Stack<std::string> operators;
	/**
	 * Operandos
	 * Variável auxiliar. Pilha de operandos utilizada na avaliação de expressão posfixa.
	 */
	Stack<int> operands;
	/**
	 * Objeto do tipo BaresException.
	 * Usado para tratamento de erros nas expressões.
	 */
	BaresException baresEx;
	/**
	 * Resultado da expressão.
	 * Variavel auxiliar. Armazena o resultado da avaliação de uma expressão posfixa.
	 */
	std::string expResult;
	
	/**
	 * Indica se um operador é unário.
	 * @param expression string que contem a expressão inteira.
	 * @param i posição do operador que se quer verificar se é unário. 
	 * @see tokenize()
	 * @return true se o operador é o primeiro caractere da expression ou se o caractere imediatamente antes dele é um operador*/
	bool isUnary(std::string expression, int i);
	
	/**
	* Transforma uma string de estrada em uma expressão infixa.
	* Coloca a expressão infixa no atributo expressionINF.
	* @param expression string que será convertida para expresão infixa.
	* @see init()
	* @return void
	* */
	void tokenize(std::string expression);
	
	/** 
	 * Transforma experssão infixa em posfixa.
	 * Converte o atributo expressionINF em uma fila de expressão posfixa, colocando a exxpressao posfixa o atributo expressionPOS.
	 * @see init();
	 * @return void
	 * */
	void infTOpostFix();
	
	/** 
	 * Verifica erros na expresão.
	 * Método não utilizado.
	 * @deprecated
	 * @return void
	 * */
	void parse();
	
	/**
	 * Avalia a expressão posfixa.
	 * Esvazia a fila de expressão posfixa e calcula o resultado da expressão.
	 * @see init()
	 * @return void
	 * */
	void avaliate();
	
	/** 
	 * Retorna o resultado da adição.
	 * @param a primeiro operando.
	 * @param b segundo operando.
	 * @see calculate()
	 * @return a + b
	 * */
	int addition(int a, int b);
	
	/** 
	 * Retorna o resultado da subtração.
	 * @param a primeiro operando.
	 * @param b segundo operando.
	 * @see calculate()
	 * @return a - b
	 * */
	int subtraction(int a, int b);
	
	/** 
	 * Retorna o resultado da multiplicação.
	 * @param a primeiro operando.
	 * @param b segundo operando.
	 * @see calculate()
	 * @return a * b
	 * */
	int multiplication(int a, int b);
	
	/** 
	 * Retorna o resultado da divisão.
	 * */
	int division(int a, int b);
	
	/** retorna o resultado do modulo a mod b.
	 * @param a primeiro operando.
	 * @param b segundo operando.
	 * @see calculate()
	 * @return a % b
	 */
	int modulo(int a, int b);
	
	/** 
	 * Retorna o resultado da exponenciação.
	 * @param a primeiro operando.
	 * @param b segundo operando.
	 * @see calculate()
	 * @return a ^ b
	 * */
	int exponentiation(int a, int b);
	
	/** 
	 * Retorna o resultado da negação.
	 * @param a primeiro operando.
	 * @see calculate()
	 * @return -a
	 * */
	int additiveInverse(int a);
	
	/** 
	 * Calcula o resultado da expressão.
	 * Chama outros metodos dependendo da string oper.
	 * @param oper string que armazena um operador.
	 * @param opnd1 primeiro operador.
	 * @param opnd2 segundo operador.
	 * @see avaliate()
	 * @return resultado da operação oper sobre os operandos.
	 * */
	int calculate(std::string oper, int opnd1, int opnd2 = 0);
	

	
	/**
	 * Verifica se a string é um símbolo.
	 * Um símbolo inclui operações e parenteses.
	 * @param symb string que contém o símbolo a ser verificado.
	 * @see isUnary()
	 * @see tokenize()
	 * @return true caso symb seja um dos simbolo: + - * / % ^ ~ ( ) 
	 */
	bool isSymbol(std::string symb);
	
	/** 
	 * Verifica se a string é um operador.
	 * Verifica se é um símbolo de operador vãlido, não considera parenteses.
	 * @param symb string que contém o elemento a ser verificado.
	 * @see infTOpostFix()
	 * @see avaliate()
	 * @return true se a string é um dos operadores: + - * / % ^ ~ 
	 * */
	bool isOperator(std::string symb);
	
	/** 
	 * Verifica se o operando tem mais precedência que outro.
	 * @param opr1 primeiro operando.
	 * @param opr2 segundo operando.
	 * @see infTOpostFix()
	 * @return true quando primeiro operador tem maior ou igual precedência do que segundo operador. 
	 * */
	bool prcd(std::string opr1, std::string opr2);
	
	
	

public:
	/** 
	 * Chama os métodos necessários para resolver a expressão.
	 * Chama os métodos tokenize(), infTOpostFix(), avaliate(), e inicializa objetos da classe BaresIO e BaresException.
	 * @param input nome do arquivo de entrada (obrigatoriamente dentro do diretório data).
	 * @param output nome do arquivo de saída (obrigatoriamente dentro do diretório data). Caso o arquivo de saída não seja definido, os resultado devem ser impressos na tela. 
	 * @return void
	 */
	void init(std::string input, std::string output = nullptr);
	
	/**
	 * Construtor default
	 * */
	Bares();
	/**
	 * Destrutor default
	 * */
	~Bares();


};
#include "../src/bares.cpp"
#endif
