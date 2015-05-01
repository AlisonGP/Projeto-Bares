#include <iostream>

#include "../include/bares.hpp"
#include "../include/baresIO.hpp"
#define nullptr 0
/**
 * criei o metodo isSymbol que é diferente de isOperator. isSymbol inclui parenteses, ja isOperator não considera parentesis.
 * */
int main(int argc, char const *argv[])
{
	//int i;
	//std::cout << "ANALISE DOS ARGUMENTOS" <<std::endl;
	//for(i =0; i< argc; i++){
	//	std::cout << i << ": " <<argv[i] << std::endl;
	//}
	
	//Bares bares("3"); // 3
	//Bares bares("3 + 2"); // 3 2 +  = 5 
	//Bares bares("3 - 2"); // 3 2 -  = 1
	//Bares bares("3 * 2"); // 3 2 *
	//Bares bares("3 / 2"); // 3 2 /
	//Bares bares("3 % 2"); // 3 2 %
	//Bares bares("3 ^ 2"); // 3 2 ^
	//Bares bares("3 ~ 2"); // erro
	//Bares bares("3 + 2 - 4"); // 3 2 + 4 -
	Bares bares("3 % 2 * 4"); // 3 2 % 4 *
	//Bares bares("3 * 2 +1 "); // 3 2 * 1 +
	//Bares bares("3 + 2 * 1"); // 3 2 1 * +
	//Bares bares("-3"); // 3 ~
	//Bares bares("--3"); // 3 ~ ~	
	//Bares bares("--3 + -5"); // 3 ~ ~ 5 ~ +
	//Bares bares("--3 - -5"); // 3 ~ ~ 5 ~ -
	//Bares bares("	- 32 + 20 15* 49 / -   10 % 2	 * 3 ^ 2 "); // 32 ~ 2015 49 * 10 ~ / 2 % 3 2 ^  * +  
	//Bares bares(" - - - 7 - 4 - - -9"); // 7 ~ ~ ~ 4  - 9 ~ ~ - 
	
	//Bares bares(" (3 * 2)"); //3 2 *
	//Bares bares(" (3 * 2 + 1)"); // 3 2 * 1 + 
	//Bares bares(" (3 + 2 * 1)"); // 3 2 1 * +
	//Bares bares(" 5 + (3 + 2 )"); // 5 3 2 + + 
	//Bares bares(" 5 * (3 + 2 * 1)"); // 5 3 2 1 * + *
	//Bares bares("(3 + 2 * 1) + 5"); //  3 2 1 * + 5 + 
	//Bares bares(" (3 + 2 * 1) * 5"); // 3 2 1 * + 5 *
	
	//Bares bares("	- 32 + 20 15- 49 /( -   10 % 2 )	 * 3 ^ 2 "); // 32 ~ 2015 + 49 10 ~ 2 % / 3 2 ^ * - // da erro!!
	//Bares bares("	- 10 + 6 * 2 - 2"); // 10 ~ 6 2 * + 2 -  = 0
	//Bares bares("12 / 5 + 4^	2 * 1"); // 12 5 / 4 2 ^ 1 * + 
	
	//Bares bares("	- 33 + (-6 * - - 5 - 7) "); // 33 ~ 6 ~ 5 ~ ~ * 7 - +   
	//Bares bares("	8+ 74 -( 9^ ( -666) *52)/1%~456");// 8 74 + 9 666 ~ ^ 52 * 1 / 456 ~ % -
	//Bares bares("3 + 6 * ( 4 ^ 3) / ( 3 + (-3 * 2))");  // 3 6 4 3 ^ * 3 3 ~ 2 *  + / +
	 //Bares bares("1 +  2 /3 %4 -5 *6 *7 +8 ^9 ");
	//Bares bares("(1 +  2 /3) %4 -5 *6 *7 +8 ^9 ");


//Exemplo criado para testar a leituera e escrita de arquivos.
	Queue<std::string> fila;
	std::string aux;
	//quando você passa só o arquivo de entrada ele joga diretamente na saída padrão.
	//se passar dois parâmetros o segundo será o arquivo de saida.
	BaresIO baresio = BaresIO("data/entrada.txt");
	baresio.readFile(fila);
	while(!fila.isEmpty()){
		aux = fila.dequeue();
		baresio.writeFile(aux);
	}

	//bares.init();
	return 0;
}
