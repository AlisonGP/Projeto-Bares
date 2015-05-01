BaresException::BaresException(std::string ifile, std::string ofile){
	baresIO = BaresIO(ifile, ofile);
}
BaresException::BaresException(std::string ifile){
	baresIO = BaresIO(ifile);
}
BaresException::~BaresException(){
	std::cout << "Destrutor BaresException" << std::endl; 
}
bool BaresException::invalidNumericConstantException(string operand){
	if(atoi(operand) > 32767){
	std::string message = "Operando fora da faixa permitida\nFaixa de valores permetido: -32767 a 32767.";
	baresIO.readFile(message);
	return false;
	}
	return true;
}
bool BaresException::invalidNumericConstantException(int operand){
	if(operand > 32767){
	std::string message = "Operando fora da faixa permitida\nFaixa de valores permetido: -32767 a 32767.";
	baresIO.readFile(message);
	return false;
	}
	return true;
}
bool BaresException::operandFaultException(){
	std::string message = "Operando não encontrado na coluna: i.";
	baresIO.readFile(message);
}
bool BaresException::invalidOperand(String operand){
	std::string message = "operadondo na coluna i invalido.";
	baresIO.readFile(message);
}
bool BaresException::invalidOperator(String operator){
	std::string message = "Operador invalido na coluna: i.";
	baresIO.readFile(message);
}
bool BaresException::operatorFault(String operator){
	std::string message = "Operador não encontrado na coluna: i.";
	baresIO.readFile(message);
}
bool BaresException::invalidScopeClosing(){
	std::string message = "Parenteses de fechamento não encontrado na coluna: i.";
	baresIO.readFile(message);
}
bool BaresException::openScope(){
	std::string message = "Parenteses de abertura não encontrado na coluna: i.";
	baresIO.readFile(message);
}
bool BaresException::divideByZero(){
	std::string message = "Expressão resulta em uma divisão por zero na coluna i.";
	baresIO.readFile(message);
}