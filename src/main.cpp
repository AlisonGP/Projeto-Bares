#include <iostream>

#include "../include/bares.hpp"
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
	return 0;
}
