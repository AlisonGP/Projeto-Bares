BaresIO::BaresIO(std::string inputS, std::string outputS){
	inputSFile = inputS;
	outputSFile = outputS; 
}
BaresIO::BaresIO(std::string inputS){
	inputSFile = inputS;
	stdOutput = true;
}
BaresIO::~BaresIO(){
	std::cout << "BARESIO Destrutor";
}
void BaresIO::writeFile(std::string result){
	std::FILE *outputFile;
	outputFile = fopen(outputSFile.c_str(),"a");

	if(outputFile != NULL){
		const char * c = result.c_str();
		fputs(c, outputFile);
		fclose(outputFile);
	}else if(stdOutput){
		std::cout << result << std::endl;
	}else{
		std::cout << "Arquivo de saida não existe" << std::endl;
	}
}
void BaresIO::readFile(Queue<std::string> &expressions){
	std::FILE  *inputFile;
	std::string line = "";
	char c;
	inputFile = fopen(inputSFile.c_str(), "r");
	if(inputFile != NULL){
		while((c = fgetc(inputFile)) != EOF){
			if(c == '\n'){
				expressions.enqueue(line);
				line = "";
			}
			line = line + c;
		}
		fclose(inputFile);
	}else{
		std::cout << "Arquivo não encontrado." << std::endl;
	}
}