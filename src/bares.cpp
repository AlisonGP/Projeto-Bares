	Bares::Bares(){
		//std::cout << "BARES:construtor default" << std::endl;
	}
	
	/*Bares::Bares(std::string expr){
		expressionsQueue.enqueue( expr);

		//std::cout << "BARES:construtor" << std::endl;
		//expressionPOS.enqueue("3");
		//expressionPOS.enqueue("~");
		//expressionPOS.enqueue("2");
	    //expressionPOS.enqueue("~");
		//expressionPOS.enqueue("+");
	    //expressionPOS.enqueue("-");
	 	//expressionPOS.enqueue("*");
		//expressionPOS.print();
		//avaliate();
	}*/
	Bares::~Bares(){
		/**
			code here
		*/
		//std::cout << "BARES:destrutor" << std::endl;
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
			//std::cout << "pode ser unario \n";
			if(i==0){
				//std::cout << "SIM! \n";
				return true;
			}else{
				std::string aux = expression.substr(i-1,1);
				if( isSymbol(aux) ){
					//std::cout << "SIM! \n";
					return true;
				}
				else{
					//std::cout << "NAO! \n";
					return false;
				}
			}
		}else{
			//std::cout << "definitivamente nao e unario \n";
			return false;
		}
	}
	void Bares::tokenize(std::string expression){
		//std::cout << "TOKENIZE ";
		
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
					//std::cout << "\"" << a << "\"" << std::endl;
					//std::cout <<"\"" << aux << "\""<< std::endl;
				}else{
					//std::cout << "\"" << aux << "\""<< std::endl;
				}
				
				//std::cout << "operador unario:" <<isUnary(expression,i) << std::endl;
				a = "";
				if(isUnary(expression,i))
					expressionINF.enqueue("~");
				else
				expressionINF.enqueue(aux);
				
			}
			i++;
		}
		if(a != ""){
			//std::cout << "\"" << a << "\"" << std::endl;
			expressionINF.enqueue(a);
		}
	}
	
/* Baseado no algoritmo de Stefan
 * http://stackoverflow.com/questions/12684086/convert-from-an-infix-expression-to-postfix-c-using-stacks
 * */
	void Bares::infTOpostFix(){
		//std::cout  << "INFTOPOSTFIX ";
		operators.push("(");
		std::string current;// = expressionINF.front();
		
		int countOperators = 0;
		
		int pos = 1;
		while(!expressionINF.isEmpty()){
			current = expressionINF.front();
			
			//std::cout << "." << current <<". "  ;
			if("(" == current) { //se é um parentese aberto, coloca na pilha de operadores
				//std::cout << "parentese aberto" << std::endl ;
				operators.push(expressionINF.dequeue());
			}else if(")" == current) { // se é um parentese fechado
				//std::cout << "parentese fechado" << std::endl ;
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
				//std::cout << "operador" << std::endl ;
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
		
		// Started with a left paren, now close it:
		// While top of stack is not a left paren
		while(!operators.isEmpty() && "(" != operators.top()) { //??
			expressionPOS.enqueue(operators.pop() );
		}
		
		// Discard the left paren
		operators.pop();
    
	
		
		/*
		//std::cout << "2 antes: ";
		expressionPOS.print();
		
		bool parentese = false;
		
		
		std::string aux = "";
		while(!expressionINF.isEmpty()){
			//std::cout << "while " << expressionINF.front();
			if(!isOperator(expressionINF.front())){
				//std::cout <<" operando" << std::endl; 
				//aux = aux+expressionINF.dequeue();
				//aux = expressionINF.dequeue();
				//expressionPOS.enqueue(aux);
				expressionPOS.enqueue(expressionINF.dequeue());
			}else{
				
			//std::cout << "expressionPOS: ";
			expressionPOS.print();
				//std::cout <<" operador:"; 
				aux = expressionINF.dequeue();
				//std::cout << "operts.isEmpty():" << operators.isEmpty();
				if( aux!= "(" && aux != ")")	{
					if(parentese == true){
						operators.push(aux);
						parentese = false; 
						
					}else{
						while(!operators.isEmpty() && prcd(operators.top(), aux)   && aux != "~"){
							//std::cout << " prcd("<<operators.top()<<", " << aux<<"):" << prcd(operators.top(), aux);
							//std::cout << "While interno 1" << aux << std::endl;
							if(prcd(operators.top(), aux)){
								//if(operators.top() != ")" && operators.top() != "(")	
									expressionPOS.enqueue(operators.pop());
								
							}
						}
						operators.push(aux);
					}
				}
				if(aux == "("){
					parentese = true;
					//expressionINF.dequeue();
					}
				if(aux == ")"){
					
				}
				//operators.push(aux);
				//std::cout << " oprts:" ;
				operators.print();
			}				
		}
		while(!operators.isEmpty()){
			expressionPOS.enqueue(operators.pop());
		}
		
			//std::cout << "expressionPOS: ";
			expressionPOS.print();
		*/
	}
	
	void Bares::parse(){
		/**
			code here
		*/
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
		
			//std::cout<< "AVALIATE " ;
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
						//opnd2 = operands.pop();
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
			//std::cout <<"resultado " <<str << std::endl;
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
        /*else if (opr1 == "(" || opr1 == ")"){
        	op1 = 4;
        }*/
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
        /*else if (opr2 == "(" || opr2 == ")"){
        	op2 = 4;
        }*/
        
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
		//std::cout << "\"" <<aux << "\":" << std::endl;
		tokenize(aux);
		//expressionINF.print();
		infTOpostFix();
		//expressionPOS.print();
		avaliate();
		if(!baresEx.error == true){
			
			baresio.writeFile(expResult);
		}
		//reseta variaveis temporarias para trabalhar co nova expressão
		//std::cout <<std::endl;
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
