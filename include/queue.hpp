#ifndef __QUEUE__
#define __QUEUE__

#include "sequence.hpp"


template <typename TYPE>
class Queue {
	Sequence<TYPE> seq;

public:
	Queue()  {}
	~Queue() {}

	TYPE front() {
		//std::cout <<"QUEUE:front()"<<std::endl;
		return seq.getFirst();
	}
	bool enqueue(TYPE value) {
		//std::cout <<"QUEUE:enqueue()"<<std::endl;
		return seq.addLast(value);
	}
	TYPE dequeue() {
		//std::cout <<"QUEUE:dequeue()"<<std::endl;
		return seq.removeFirst();
	}

	bool isEmpty() {
		//std::cout <<"QUEUE:isEmpty()"<<std::endl;
		return seq.isEmpty();
	}
	void print() {
		//std::cout <<"QUEUE:print()"<<std::endl;
		seq.print();
	}
};

#endif
