	Bares::Bares(){
	}
	Bares::~Bares(){
	}
	
	void Bares::removeCharacter(std::string& str, char c){
		unsigned int i =0;
		while(i<str.size()){
			if(str[i] == c)
				str = str.erase(i,1);
			else
				i++;
		}
	}
	
	bool Bares::isUnary(std::string expression, int i){
		if(expression[i] == '-' || expression[i] == '~'){
			if(i==0){
				return true;
			}else{
				std::string aux = expression.substr(i-1,1);
				if( isSymbol(aux) ){
					return true;
				}
				else{
					return false;
				}
			}
		}else{
			return false;
		}
	}
	void Bares::tokenize(std::string expression){
		
		int tam = expression.size();
		
		
		std::string a = "";
		std::string aux;

		int i = 0;
		while(i < tam ){
			
			aux = expression[i];
			if( !isSymbol(aux) )
			{	
				a = a +aux;
				
			}
			else{
				
				if(a != ""){
					expressionINF.enqueue(a);
				}
				a = "";
				if(isUnary(expression,i))
					expressionINF.enqueue("~");
				else
				expressionINF.enqueue(aux);
				
			}
			i++;
		}
		if(a != ""){
			expressionINF.enqueue(a);
		}
	}
	
/* Baseado no algoritmo de Stefan
 * http://stackoverflow.com/questions/12684086/convert-from-an-infix-expression-to-postfix-c-using-stacks
 * */
	void Bares::infTOpostFix(){
		operators.push("(");
		std::string current;
		
		int countOperators = 0;
		
		int pos = 1;
		while(!expressionINF.isEmpty()){
			current = expressionINF.front();
			
			if("(" == current) { //se é um parentese aberto, coloca na pilha de operadores
				operators.push(expressionINF.dequeue());
			}else if(")" == current) { // se é um parentese fechado
				while(!operators.isEmpty() && "(" != operators.top()) { //enquanto o topo da pilha não for um parentese fechado, esvazia a pilha
					expressionPOS.enqueue(operators.pop() );
				}
				// Descarta o parentese aberto
				operators.pop();
				expressionINF.dequeue();
			}else if(isOperator(current)) { // se é um operador, coloca na pilha conforme a sua precedencia
				if(current != "~"){
					countOperators++;
					if(expressionPOS.isEmpty() || expressionINF.getSize() == 1 || countOperators == 2)
						baresEx.operandFault(pos);

				}
				while(!operators.isEmpty() && isOperator(operators.top()) && prcd(operators.top(), current) && current != "~") {
					expressionPOS.enqueue(operators.pop() );
				}
				operators.push(expressionINF.dequeue());
			}else if(!isOperator( current )){ // se é um operando, coloca em expressionPOS
				countOperators = 0;
				if(!baresEx.invalidOperand(current, pos)){
					baresEx.invalidNumericConstant(current, pos);
				}
				expressionPOS.enqueue(expressionINF.dequeue());

			}
			
			pos++;
		}
		
		// Desempilha os operadores enquanto não encontrar um parentese de abertura.
		while(!operators.isEmpty() && "(" != operators.top()) {
			expressionPOS.enqueue(operators.pop() );
		}
		
		// Remove o parentese que sobrou.
		operators.pop();
    
	}
	
	void Bares::parse(){

	}
	
	
	
	bool Bares::isSymbol(std::string symb){
		if(symb == "+" || symb == "-" || symb == "*" || symb == "/" || symb == "^" || symb == "%" || symb == "(" || symb == ")" || symb == "~")
				return true;
		return false;
		
	}
	
	
	bool Bares::isOperator(std::string symb){
		if(symb == "+" || symb == "-" || symb == "*" || symb == "/" || symb == "^" || symb == "%" || symb == "~")
				return true;
		return false;
		
	}
	
	
	int Bares::addition(int a, int b){
		return a + b;
	}

	int Bares::subtraction(int a, int b){
		return a - b;
	}

	int Bares::multiplication(int a, int b){
		return a * b;
	}

	int Bares::division(int a, int b){
		return a/b;
	}

	int Bares::modulo(int a, int b){
		return a%b;
	}

	int Bares::exponentiation(int a, int b){
		int i, aux=1;
		for(i=0; i<b; i++){
			aux = aux * a;
		}
		return aux;
	}

	int Bares::additiveInverse(int a){
		return -a;
	}

	
	
	int Bares::calculate(std::string oper, int opnd1, int opnd2){
		if(oper == "+")
			return addition(opnd1, opnd2);
		if(oper == "-")
			return subtraction(opnd1, opnd2);
		if(oper == "*")
			return multiplication(opnd1, opnd2);
		if(oper == "/"){
			return division(opnd1, opnd2);
		}
		if(oper == "%")
			return modulo(opnd1, opnd2);
		if(oper == "^")
		{	
			return exponentiation(opnd1, opnd2);
		}	
		if(oper == "~")
		{	
			return additiveInverse(opnd1);
		}	
	}
	
	void Bares::avaliate(){
		if(!baresEx.error == true){
		
			std::string  symb;
			int opnd1, opnd2;
			int resultado;
			int aux;
			int pos = 1;

			while(!expressionPOS.isEmpty()){
				symb = expressionPOS.dequeue();
				
				if(!isOperator(symb)){
					aux= atoi(symb.c_str());
					operands.push(aux);
				}else{
					if(symb == "~"){
						opnd1 = operands.pop();
						resultado = calculate(symb, opnd1);
						operands.push(resultado);
					
					}else{
						
							opnd1 = operands.pop();
							opnd2 = operands.pop();
							

							if(!baresEx.divideByZero(symb,opnd1, pos))
								resultado = calculate(symb,opnd2, opnd1);
							operands.push(resultado);
						
					}
				}
				
				pos++;
			}
			
			resultado = operands.pop();
			//converte resultado (int) para string, com ajuda da biblioteca sstream 
			std::ostringstream ss;
			ss << resultado;
			std::string str = ss.str();
			expResult =  str;
		}
	}
	

	//Verifica se operador1 tem maior precedencia que operador2 
	bool Bares::prcd(std::string opr1, std::string opr2){
		int op1, op2;

		// Converte o operador 1 em um número apartir da sua precedência.
		if(opr1 == "+" || opr1 == "-"){
			op1 = 0;
		}else if(opr1 == "*" || opr1 == "/" || opr1 == "%"){
			op1 = 1;
		}else if(opr1 == "^"){
			op1 = 2;
		}else if(opr1 == "~"){
        	op1 = 3;
        }
        
        //Converte o operador 2 em um número a partir de sua precedência.
        if(opr2 == "+" || opr2 == "-"){
			op2 = 0;
		}else if(opr2 == "*" || opr2 == "/" || opr2 == "%"){
			op2 = 1;
		}else if(opr2 == "^"){
			op2 = 2;
		}else if(opr2 == "~"){
        	op2 = 3;
        }
        
        //Compara se o operador 1 possui maior precedência sobre o operador 2.
		if(op1 >= op2)
			return true;
		return false;
	}
	

void Bares::init(std::string input, std::string output){
	
	BaresIO baresio;
	if(output.empty()){
		baresio = BaresIO(input);
		baresEx = BaresException(input);
	}else{
		baresio = BaresIO(input, output);
		baresEx = BaresException(input, output);
	}
		
		
	baresio.readFile(expressionsQueue);

	std::string aux;
	while(!expressionsQueue.isEmpty()){
		aux = expressionsQueue.dequeue();
		tokenize(aux);
		infTOpostFix();
		avaliate();
		if(!baresEx.error == true){
			
			baresio.writeFile(expResult);
		}
		//reseta variaveis temporarias para trabalhar co nova expressão
		baresEx.error = false;
		while(!expressionINF.isEmpty()){
			expressionINF.dequeue();
		}
		while(!expressionPOS.isEmpty()){
			expressionPOS.dequeue();
		}
		while(!operators.isEmpty()){
			operators.pop();
		}
		while(!operands.isEmpty()){
			operands.pop();
		}
		
	}
}
