
BARESIO::BARESIO(std::string inFile, std::string outFile){
	inputFile.open(inFile);
	outputFile.open(outFile, ofstream::app);
}
BARESIO::BARESIO(std::string inFile){
	inputFile.open(inFile);
	defaultOutput = true;
}
BARESIO::~BARESIO(){
	std::cout << "BARESIO Destrutor";
}
void BARESIO::writeFile(string result){
	if(outputFile.is_open() && outputFile.good()){
		outputFile << result;
		outputFile.close();
	}
}
Queue<string> BARESIO::readFile(){
	Queue<string> expressions;
	string line;
	if(inputFile.is_open() && inputFile.good()){
		while(inputFile.getline(line)){
			expressions.enqueue(line);
		}
		inputFile.close();
	}
	return expressions;
}