void BaresIO::removeCharacter(std::string& str, char c){
		unsigned int i =0;
		while(i<str.size()){
			if(str[i] == c)
				str = str.erase(i,1);
			else
				i++;
		}
	}

BaresIO::BaresIO(std::string inputS, std::string outputS){
	inputSFile = "data/"+inputS;
	outputSFile = "data/"+outputS;

	clearFile(); 
}
BaresIO::BaresIO(std::string inputS){
	inputSFile = "data/"+inputS;
	stdOutput = true;
}
BaresIO::BaresIO(){
}
BaresIO::~BaresIO(){
	//std::cout << "Destrutor BaresIO" << std::endl;
}
void BaresIO::clearFile(){
	std::FILE *outputFile;
	outputFile = fopen(outputSFile.c_str(),"w");

	if(outputFile != NULL){
		//const char * c;
		fputs("", outputFile);
		fclose(outputFile);
	}else{
		std::cout << "Arquivo de saida não existe" << std::endl;
	}
}
void BaresIO::writeFile(std::string result){
	result = result + "\n";
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
				removeCharacter(line, 32); //espaço
				removeCharacter(line, 9); //tabulação
				removeCharacter(line, 10); //nova linha
				if(!line.empty())
					expressions.enqueue(line);
				line = "";
			}
			line = line + c;
		}

		if(!line.empty()){
			removeCharacter(line, 32); //espaço
			removeCharacter(line, 9); //tabulação
			removeCharacter(line, 10); //nova linha
			if(!line.empty())
				expressions.enqueue(line);
		}
		fclose(inputFile);
	}else{
		std::cout << "Arquivo de entrada não encontrado." << std::endl;
	}
}
