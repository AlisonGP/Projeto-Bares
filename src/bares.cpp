	Bares::Bares(std::string expression){
		/**
			code here
		*/
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
		/**
			code here
		*/
	}
	
	void Bares::infTOposFix(){
		/**
			code here
		*/
	}
	
	void Bares::parse(){
		/**
			code here
		*/
	}
	
	bool Bares::isOperator(std::string symb){
		if(symb == "+" || symb == "-" || symb == "*" || symb == "/" || symb == "^")
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
	
	bool Bares::isBinary(){
		/**
			code here
		*/
		return true;
	}

	bool Bares::prcd(){
		/**
			code here
		*/
		return true;
	}
	
	void Bares::printResult(){
		/**
			code here
		*/
	}

	void Bares::init(){
		/**
			code here
		*/
	}
