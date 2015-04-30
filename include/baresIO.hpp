#ifndef __BARESIO__
#define	__BARESIO__

#include <iostream>
#include <cstdio>
#include "queue.hpp"
class BaresIO
{

	std::string inputSFile;
	std::string outputSFile;
	bool stdOutput;
public:
	BaresIO(std::string inputS, std::string outputS);
	BaresIO(std::string inputS);
	~BaresIO();
	void writeFile(std::string result);
	void readFile(Queue<std::string> &expressions);
};

#include "../src/baresIO.cpp"
#endif