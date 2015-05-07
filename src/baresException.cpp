BaresException::BaresException(std::string ifile, std::string ofile){
	baresIO = BaresIO(ifile, ofile);
	error = false;
}
BaresException::BaresException(std::string ifile){
	baresIO = BaresIO(ifile);
	error = false;
}
BaresException::BaresException(){
	error = false;
}
BaresException::~BaresException(){
	
}
bool BaresException::invalidNumericConstant(std::string operand, int pos){
	
	if(atoi(operand.c_str()) > 32767){
		std::stringstream ss;
		ss << pos;
		std::string str = ss.str();
		std::string message = "Erro! coluna "+ str + ": constante numérica inválida.";
		baresIO.writeFile(message);
		
		//sinalizador da classe BaresException (recebe true quando algum erro foi encontrado)
		error = true;
		return true;
	}
	return false;
}

void BaresException::operandFault(int pos){
	std::stringstream ss;
	ss << pos;
	std::string str = ss.str();
	std::string message = "Erro! coluna "+ str + ": falta de operando.";
	baresIO.writeFile(message);
	
	//sinalizador da classe BaresException (recebe true quando algum erro foi encontrado)
	error = true;
	
}
bool BaresException::invalidOperand(std::string operand, int pos){
	for(int i=0; i<operand.length(); i++){
		if(!isdigit(operand[i]))
		{	
			std::stringstream ss;
			ss << pos;
			std::string str = ss.str();
			std::string message = "Erro! coluna "+ str + ": operando inválido.";// += 'coluna '+pos+': operando invalido.\n';
			baresIO.writeFile(message);
			
			//sinalizador da classe BaresException (recebe true quando algum erro foi encontrado)
			error = true;
			return true;
		}
		
	}
	return false;
	
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
bool BaresException::divideByZero(std::string oper, int opnd, int pos){
	if(oper == "/" && opnd == 0)
	{	
		std::stringstream ss;
		ss << pos;
		std::string str = ss.str();
		std::string message = "Erro! coluna "+ str + ": divisão por zero.";
		baresIO.writeFile(message);
		
		//sinalizador da classe BaresException (recebe true quando algum erro foi encontrado)
		error = true;
		return true;
	}else
		return false;
					
}
