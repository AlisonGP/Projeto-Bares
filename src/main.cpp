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
	
	//Bares bares("32 + 2015 - 49 / ( - 10 % 2 ) * 3 ^ 2");
	Bares bares("32 + 2015 - 49 / ( 10 % 2 ) * 3 ^ 2");
	
	bares.init();
	return 0;
}
