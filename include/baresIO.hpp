#ifndef __BARESIO__
#define	__BARESIO__

#include <iostream>
#include <fstream>
class BaresIO
{

	std::ifstream inputFile;
	std::ofstream outputFile;
	bool defaultOutput;
public:
	BaresIO(std::string inFile, std::string outFile);
	BaresIO(std::string inFile);
	~BaresIO();
	void writeFile();
	Queue<string> readFile();
};

#include "../src/baresIO.cpp"
#endif