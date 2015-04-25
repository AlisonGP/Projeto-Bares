	Bares::Bares(std::string expr){
		expression = expr;

		std::cout << "BARES:construtor" << std::endl;
		expressionPOS.enqueue("3");
		expressionPOS.enqueue("0");
		expressionPOS.enqueue("+");
	    expressionPOS.enqueue("2");
		expressionPOS.enqueue("4");
	    expressionPOS.enqueue("-");
	 	expressionPOS.enqueue("*");
		expressionPOS.print();
		avaliate();
	}
	Bares::~Bares(){
		/**
			code here
		*/
		std::cout << "BARES:destrutor" << std::endl;
	}

	void Bares::tokenize(){
		int tam = expression.size();
		std::string a = "";

		for(int i = 0; i < tam; i++){
			std::cout << "I: " << i << std::endl;
			if(expression[i] != ' ' )
				a = a + expression[i];
			while(!isOperator(""+expression[i+1]) && i < tam){
				i++;
				if(expression[i] != ' ')
					a = a + expression[i];
			}
			expressionINF.enqueue(a);
		}

	}
	
	void Bares::infTOposFix(){
		std::string aux = "";
		while(!expressionINF.isEmpty()){
			if(!isOperator(expressionINF.front())){
				aux = aux+expressionINF.dequeue();
				expressionPOS.enqueue(aux);
			}else{
				aux = expressionINF.dequeue();
				while(!operators.isEmpty() && prcd(operators.top(), aux)){
					//std::cout << "While interno 1" << aux << std::endl;
					if(prcd(operators.top(), aux)){
						if(operators.top() != ")" && operators.top() != "(")
							expressionPOS.enqueue(operators.pop());
					}
				}
				//std::cout << "While interno 2" << aux << std::endl;
				operators.push(aux);
			}				
		}
		while(!operators.isEmpty()){
			expressionPOS.enqueue(operators.pop());
		}
	}
	
	void Bares::parse(){
		/**
			code here
		*/
	}
	
	bool Bares::isOperator(std::string symb){
		if(symb == "+" || symb == "-" || symb == "*" || symb == "/" || symb == "^" || symb == "%" || symb == "(" || symb == ")")
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
		if(oper == "/")
			return division(opnd1, opnd2);
		if(oper == "^")
		{	
			return exponentiation(opnd1, opnd2);
		}	
	}
	
	void Bares::avaliate(){
		std::cout<< "BARES:avaliate" << std::endl ;
		std::string  symb;
		int opnd1, opnd2;
		int resultado;
	int aux;

		while(!expressionPOS.isEmpty()){
			symb = expressionPOS.dequeue();
			
			if(!isOperator(symb)){
				aux= atoi(symb.c_str());
				operands.push(aux);
			}else{
				opnd1 = operands.pop();
				opnd2 = operands.pop();
				resultado = calculate(symb,opnd2, opnd1);
				operands.push(resultado);
			}
		}
		resultado = operands.pop();
		std::cout <<"resultado " <<resultado << std::endl;
	}
	
	//Verifica se o operador é binário ou unário.
	bool Bares::isBinary(){
		//Verifica se a pilha de operadores está vazia e se a fila de operandos tamém está vazia.
		if(operators.isEmpty() && expressionPOS.isEmpty())
			return false;
		//Verifica se a pila de operadores possui mais elementos que a fila de operandos. 
		if(operators.getSize() >= expressionPOS.getSize())
			return false;		

		return true;
	}

	//Verifica qual o operador com maior precedência
	bool Bares::prcd(std::string opr1, std::string opr2){
		int op1, op2;

		// Converte o operador 1 em um número apartir da sua precedência.
		if(opr1 == "+"){
			op1 = 0;
		}else if(opr1 == "-"){
			if(isBinary()){
				op1 = 0;
			}else{
				op1 = 2;
			}
		}else if(opr1 == "*" || opr1 == "/" || opr1 == "%"){
			op1 = 1;
		}else if(opr1 == "^"){
        	op1 = 3;
        }else if (opr1 == "(" || opr1 == ")"){
        	op1 = 4;
        }
        //Converte o operador 2 em um número a partir de sua precedência.
        if(opr2 == "+"){
			op2 = 0;
		}else if(opr2 == "-"){
			if(isBinary()){
				op2 = 0;
			}else{
				op2 = 2;
			}
		}else if(opr2 == "*" || opr2 == "/" || opr2 == "%"){
			op2 = 1;
		}else if(opr2 == "^"){
        	op2 = 3;
        }else if (opr2 == "(" || opr2 == ")"){
        	op2 = 4;
        }
        //Compara se o operador 1 possui maior precedência sobre o operador 2.
		if(op1 >= op2)
			return true;
		return false;
	}
	
	void Bares::printResult(){
		/**
			code here
		*/
	}

	void Bares::init(){
		/**
			fazndo um teste
		*/
			tokenize();
			std::cout << "1: ";
			expressionINF.print();
			infTOposFix();
			std::cout << "2: ";
			expressionPOS.print();

	}
