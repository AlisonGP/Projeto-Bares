BaresException::BaresException(std::string ifile, std::string ofile){
	baresIO = BaresIO(ifile, ofile);
}
BaresException::BaresException(std::string ifile){
	baresIO = BaresIO(ifile);
}
BaresException::BaresException(){

}
BaresException::~BaresException(){
	std::cout << "Destrutor BaresException" << std::endl; 
}
bool BaresException::invalidNumericConstantException(std::string operand){
	if(atoi(operand.c_str()) > 32767){
	std::string message = "Operando fora da faixa permitida\nFaixa de valores permetido: -32767 a 32767.";
	baresIO.writeFile(message);
	return false;
	}
	return true;
}
bool BaresException::invalidNumericConstantException(int operand){
	if(operand > 32767){
	std::string message = "Operando fora da faixa permitida\nFaixa de valores permetido: -32767 a 32767.";
	baresIO.writeFile(message);
	return false;
	}
	return true;
}
bool BaresException::operandFaultException(){
	std::string message = "Operando não encontrado na coluna: i.";
	baresIO.writeFile(message);
}
bool BaresException::invalidOperand(std::string operand, int pos){
	if(isdigit(atoi(operand.c_str()))){
		return false;
	}else{
		std::stringstream ss;
		ss << pos;
		std::string str = ss.str();
		std::string message = "coluna"+ str + "operando invalido.\n";// += 'coluna '+pos+': operando invalido.\n';
		baresIO.writeFile(message);
		return true;
	}
	
}
bool BaresException::invalidOperator(std::string oper){
	std::string message = "Operador invalido na coluna: i.";
	baresIO.writeFile(message);
}
bool BaresException::operatorFault(std::string oper){
	std::string message = "Operador não encontrado na coluna: i.";
	baresIO.writeFile(message);
}
bool BaresException::invalidScopeClosing(){
	std::string message = "Parenteses de fechamento não encontrado na coluna: i.";
	baresIO.writeFile(message);
}
bool BaresException::openScope(){
	std::string message = "Parenteses de abertura não encontrado na coluna: i.";
	baresIO.writeFile(message);
}
bool BaresException::divideByZero(){
	std::string message = "Expressão resulta em uma divisão por zero na coluna i.";
	baresIO.writeFile(message);
}