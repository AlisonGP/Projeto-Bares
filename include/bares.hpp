#ifndef __BARES__
#define	__BARES__

#include <string>
class Bares{
	//Atributos
	string expression;
	Queue expressionINF;
	Queue expressionPOS;
	Stack operators;
	Stack operands;
	Queue messageError;

	//Métodos

	Bares(string expression);
	~Bares();

	/**
	* Transforma uma string de estrada em uma expressão expressão IN-fix.*/
	void tokenize();
	/** Transforma experssão infixa em pos-fixa.*/
	void infTOposFix();
	/** Verifica erros na expresão.*/
	void parse();
	/** Calcula o resultado da expressão.*/
	void calculate();
	/** Verifica se a operação é binária ou unária.*/
	bool isBinary();
	/** Verifica se o operando tem mais precedência que outro.*/
	prcd();
	/** Imprime o resultado no terminal ou em um arquivo de texto.*/
	printResult();
public:
	/** Chama os métodos necessários para resolver a expressão*/
	init();

};

#include "../src/bares.cpp"
#endif