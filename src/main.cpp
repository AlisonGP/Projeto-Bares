#include <iostream>

#include "../include/bares.hpp"
#define nullptr 0

int main(int argc, char const *argv[])
{
	//int i;
	//std::cout << "ANALISE DOS ARGUMENTOS" <<std::endl;
	//for(i =0; i< argc; i++){
	//	std::cout << i << ": " <<argv[i] << std::endl;
	//}
	
	//Bares bares("3"); // 3
	//Bares bares("3 + 2"); // 3 2 +
	//Bares bares("3 - 2"); // 3 2 -
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
	Bares bares(" - - - 7 - 4 - - -9"); // 7 ~ ~ ~ 4  - 9 ~ ~ - 
	//Bares bares(" (3 * 2)");
	//Bares bares("	- 32 + 20 15- 49 /( -   10 % 2 )	 * 3 ^ 2 ");
	//Bares bares("	- 10 + 6 * 2 - 2"); // 10 ~ 6 2 * + 2 -
	//Bares bares("12 / 5 + 4^	2 * 1"); // 12 5 / 4 2 ^ 1 * + 
	
	//Bares bares("	- 33 + (-6 * - - 5 - 7) ");
	//Bares bares("	8+ 74 -( 9^ ( -666) *52)/1%~456");
	
	bares.init();
	return 0;
}
