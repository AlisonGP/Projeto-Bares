#ifndef __BARESIO__
#define	__BARESIO__

#include <iostream>
#include <fstream>
class BARESIO
{

	std::ifstream inputFile;
	std::ofstream outputFile;
	bool defaultOutput;
public:
	BARESIO(std::string inFile, std::string outFile);
	BARESIO(std::string inFile);
	~BARESIO();
	void writeFile();
	Queue<string> readFile();
};

#include "../src/baresIO.cpp"
#endif