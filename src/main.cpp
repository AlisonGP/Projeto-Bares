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
	
	Bares bares("3 + 2 + 4");
	
	bares.init();
	return 0;
}
