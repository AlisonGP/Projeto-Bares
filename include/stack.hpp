#ifndef __STACK__
#define __STACK__

#include "sequence.hpp"


template <typename TYPE>
class Stack {
	Sequence<TYPE> seq;
	
public:
	Stack()  {};
	
	~Stack() {};

	TYPE top() {
		//std::cout<< "STACK:top()" << std::endl;
		return seq.getFirst();
	}
	TYPE push(TYPE value) {
		//std::cout<< "STACK:push()" << std::endl;
		return seq.addFirst(value);
	}
	TYPE pop() {
		//std::cout<< "STACK:pop()" << std::endl;
		return seq.removeFirst();
	}

	bool isEmpty() {
		//std::cout<< "STACK:isEmpty()" << std::endl;
		return seq.isEmpty();
	}
	void print()   {
		//std::cout<< "STACK:print()" << std::endl;
		seq.print();
	}
};

#endif
