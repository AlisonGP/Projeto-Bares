#include <iostream>

#include "../include/bares.hpp"
//#include "../include/baresIO.hpp"
#define nullptr 0

int main(int argc, char const *argv[])
{
	std::string input, output;

	
	if(argc <= 1 || argc > 3)
		std::cout << "Erro: parametros incorretos." <<std::endl;
	else{
		input = argv[1];
		if(argc == 3)
			output = argv[2];
		
		Bares bares;
		bares.init(input, output);
	}
	
	/*
	 * 
32767 *  4
5+ t
32768-1


3
3 + 6
3 - 2
3 * 2
3 / 2
3 % 2
3 ^ 2
- 2
3 + 2 - 4
(1 +   2)*	5

	 * */
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
	//Bares bares("3 % 2 * 4"); // 3 2 % 4 *
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


	
	
	return 0;
}
