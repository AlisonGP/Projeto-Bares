#ifndef __BARES__
#define	__BARES__
#include "stack.hpp"
#include "queue.hpp"
#include <string>
#include <stdlib.h>
class Bares{
	//Atributos
	std::string expression;
	Queue<std::string> expressionINF;
	Queue<std::string> expressionPOS;
	Stack<std::string> operators;
	Stack<int> operands;
	Queue<std::string> messageError;

	//Métodos
	/**remove todas as ocorrências do caractere c na string str*/
	void Bares::removeCharacter(std::string& str, char c);
	/**
	* Transforma uma string de estrada em uma expressão expressão IN-fix.*/
	void tokenize();
	/** Transforma experssão infixa em pos-fixa.*/
	void infTOposFix();
	/** Verifica erros na expresão.*/
	void parse();
	/** avalia a expressão posfixa.*/
	void avaliate();
	
	/** retorna o resultado da adição.*/
	int addition(int a, int b);
	/** retorna o resultado da subtração.*/
	int subtraction(int a, int b);
	/** retorna o resultado da multiplicação.*/
	int multiplication(int a, int b);
	/** retorna o resultado da divisão.*/
	int division(int a, int b);
	/** retorna o resultado da exponenciação.*/
	int exponentiation(int a, int b);
	/** retorna o resultado da negação.*/
	int additiveInverse(int a);
	
	/** Calcula o resultado da expressão.*/
	int calculate(std::string oper, int opnd1, int opnd2 = 0);
	/** Verifica se a operação é binária ou unária.*/
	bool isBinary();
	/** Verifica se o simbolo é um opeador ou operando.*/
	bool isOperator(std::string symb);
	/** Verifica se o operando tem mais precedência que outro.*/
	bool prcd(std::string opr1, std::string opr2);
	/** Imprime o resultado no terminal ou em um arquivo de texto.*/
	void printResult();
	

public:
	/** Chama os métodos necessários para resolver a expressão*/
	void init();
	
	Bares(std::string expression);
	~Bares();


};

#include "../src/bares.cpp"
#endif
