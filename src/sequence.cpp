//#include "sequence.hpp"
#include <iostream>
template <typename TYPE>
void Sequence<TYPE>::swap(Node *n1, Node *n2){
	//std::cout << "swap" << std::endl;
	Node *nextaux, *prevaux;

	if(list.next == n1){
		list.next = n2;
	}else if(list.next == n2){
		list.next = n1;
	}
	
	if(list.prev == n1){
		list.prev = n2;
	}else if(list.prev == n2){
		list.prev = n1;
	}
	
	Node *prevN1;
	Node *prevN2;
	Node *nextN1;
	Node *nextN2;
	

	if(n1->next == n2   ||   n2->next == n1){
		if(n2->next == n1){
			Node *aux = n1;
			n1 = n2;
			n2 = aux;
		}
		//std::cout<<" faca isso";
		prevN1 = n1->prev;
		nextN1 = n1->next->next;
		prevN2 = n2->prev->prev;
		nextN2 = n2->next;
		
		//std::cout<<"entrei assim n1="<<n1->data<< " n1->prev="<<prevN1->data<< " n1->prev->next="<<prevN1->next->data << " n1->next="<<nextN1->data<< " n1->next->prev="<<nextN1->prev->data<< std::endl;
		//std::cout<<"             n2="<<n2->data<< " n2->prev="<<prevN2->data<< " n2->prev->next="<<prevN2->next->data << " n2->next="<<nextN2->data<< " n2->next->prev="<<nextN2->prev->data<< std::endl;

		n1->next = nextN2;
		n1->prev = n2;
		n2->next = n1;
		n2->prev = prevN1;
		
		if(prevN1 != nullptr)
		prevN1->next = n2;
		if(nextN2 != nullptr)
		nextN2->prev = n1;
	
	}
	/*else if( n2->next == n1){
		std::cout<<" nao faça isso";
		prevN1 = n1->prev->prev;
		nextN1 = n1->next;
		prevN2 = n2->prev;
		nextN2 = n2->next->next;
		
		//std::cout<<"entrei assim n1="<<n1->data<< " n1->prev="<<prevN1->data<< " n1->prev->next="<<prevN1->next->data << " n1->next="<<nextN1->data<< " n1->next->prev="<<nextN1->prev->data<< std::endl;
		//std::cout<<"             n2="<<n2->data<< " n2->prev="<<prevN2->data<< " n2->prev->next="<<prevN2->next->data << " n2->next="<<nextN2->data<< " n2->next->prev="<<nextN2->prev->data<< std::endl;

		
		n1->next = n2;
		n1->prev = prevN2;
		n2->next = nextN1;
		n2->prev = n1;
		
		if(prevN2 != nullptr)
		prevN2->next = n1;
		if(nextN1 != nullptr)
		nextN1->prev = n2;

			
	}*/else{
		prevN1 = n1->prev;
		nextN1 = n1->next;
		prevN2 = n2->prev;
		nextN2 = n2->next;
		
		//std::cout<<"entrei assim n1="<<n1->data<< " n1->prev="<<prevN1->data<< " n1->prev->next="<<prevN1->next->data << " n1->next="<<nextN1->data<< " n1->next->prev="<<nextN1->prev->data<< std::endl;
		//std::cout<<"             n2="<<n2->data<< " n2->prev="<<prevN2->data<< " n2->prev->next="<<prevN2->next->data << " n2->next="<<nextN2->data<< " n2->next->prev="<<nextN2->prev->data<< std::endl;


		n1->next = nextN2;
		n1->prev = prevN2;
		n2->next = nextN1;
		n2->prev = prevN1;
		
		if(prevN1 != nullptr)
		prevN1->next = n2;
		if(nextN1 != nullptr)
		nextN1->prev = n2;
		
		if(prevN2 != nullptr)
		prevN2->next = n1;
		if(nextN2 != nullptr)
		nextN2->prev = n1;
	}
	
/*	
	n1->next = nextN2;
	n1->prev = prevN2;
	n2->next = nextN1;
	n2->prev = prevN1;
	
	if(prevN1 != nullptr)
	prevN1->next = n2;
	if(prevN2 != nullptr)
	prevN2->next = n1;
	
	if(nextN1 != nullptr)
	nextN1->prev = n2;
	if(nextN2 != nullptr)
	nextN2->prev = n1;

	*/
	//std::cout<<"fiquei assim n1="<<n1->data<< " n1->prev="<<prevN1->data<< " n1->prev->next="<<prevN1->next->data << " n1->next="<<nextN1->data<< " n1->next->prev="<<nextN1->prev->data<< std::endl;
	//std::cout<<"             n2="<<n2->data<< " n2->prev="<<prevN2->data<< " n2->prev->next="<<prevN2->next->data << " n2->next="<<nextN2->data<< " n2->next->prev="<<nextN2->prev->data<< std::endl;
		
	/*
	std::cout<<" entrei aqui n1="<<n1->data<< " n1->prev="<<n1->prev->data<< " n1->prev->next="<<n1->prev->next->data << std::endl;
	std::cout<<"             n2="<<n2->data<< " n2->prev="<<n2->prev->data<< " n2->prev->next="<<n2->prev->next->data << std::endl;
	if(n1->prev != nullptr){	
	
		n1->prev->next = n2;
	}
	if(n2->prev != nullptr)
		n2->prev->next = n1;
	if(n1->next != nullptr)
		n1->next->prev = n2;
	if(n2->next != nullptr)
		n2->next->prev = n1;
	
	
	
	nextaux = n1->next;
	prevaux = n1->prev;
	
	n1->next = n2->next;
	n1->prev = n2->prev;
	
	n2->next = nextaux;
	n2->prev = prevaux;
	
	std::cout<<"agora fiquei n1="<<n1->data<< " n1->prev="<<n1->prev->data<< " n1->prev->next="<<n1->prev->next->data << std::endl;
	std::cout<<"             n2="<<n2->data<< " n2->prev="<<n2->prev->data<< " n2->prev->next="<<n2->prev->next->data << std::endl;
	*/
}

template <typename TYPE>
Sequence<TYPE>::Sequence() {
	//std::cout << "construtor" << std::endl;
}

template <typename TYPE>
Sequence<TYPE>::Sequence(const Sequence<TYPE> &s){
	//std::cout<<"construtor de copia"<<std::endl;
	//Node *aux = &list;
	
	//aux->next = 
	//Node aux = new Node(nullptr, nullptr);
	Node *aux = &s.list;
	while(aux->next != nullptr){
		addLast(aux->next->data);
		aux = aux->next;
	}
	//print();
}

template <typename TYPE>
Sequence<TYPE>::~Sequence() {
	//std::cout << "destrutor" << std::endl;
	Node *node = list.next;
	Node *aux;
	if(list.next!= nullptr){
		while(node->next!= nullptr){
			aux = node->next;
			delete node;
			node = aux;
		}
		delete list.prev;
	}
}

template <typename TYPE>
bool Sequence<TYPE>::operator==( Sequence<TYPE> &s){
	//std::cout<< "operador de comparacao"<< std::endl;
	if(getSize() != s.getSize())
		return false;
	else{
		Node *n1 = &list;
		Node *n2 = &(s.list);
		
		while(n1->next != nullptr){
			if(n1->next->data != n2->next->data)
				return false;
			n1 = n1->next;
			n2 = n2->next;
		}
		return true;
	}
}

template <typename TYPE>
bool Sequence<TYPE>::isEmpty() {
	//std::cout << "isEmpty()"<<std::endl;
	if(list.next == nullptr && list.prev == nullptr)
		return true;
	else
		return false;
}

template <typename TYPE>
int Sequence<TYPE>::getSize() {
	//std::cout << "getSize"<<std::endl;
	if(list.next == nullptr && list.prev == nullptr)
	{
			return 0;
	}else{
		int i=0;
		Node *aux = list.next;
		while(aux != nullptr){
			aux = aux->next;
			i++;
		}
		return i;
	}
	
}

template <typename TYPE>
bool Sequence<TYPE>::addFirst(const TYPE &value) {
	//std::cout << "addFirst()" << std::endl;
	
	Node *novo = new Node;
	if(novo == nullptr)
		return false;
	
	novo->data = value;
	novo->next = list.next;
	list.next = novo;
		
	if(novo->next != nullptr)
		novo->next->prev = novo;

	if(list.prev == nullptr)
		list.prev = novo;
	
	return true;
	
}

template <typename TYPE>
bool Sequence<TYPE>::addLast(const TYPE &value) {
	//std::cout << "addLast()" << std::endl;
	
	Node *novo = new Node;
	if(novo == nullptr)
		return false;
	
	novo->data = value;
	
	
	if(list.next == nullptr && list.prev == nullptr)
		list.next = novo;

		
	if(list.prev != nullptr)	
		list.prev->next = novo;
	
	list.prev = novo;

	return true;
}

template <typename TYPE>
bool Sequence<TYPE>::add(const TYPE &value, int pos) {
	//std::cout << "add" << std::endl;
	if(pos<0){
		return addFirst(value);
	}else if(pos> getSize()-1){
		return addLast(value);
	}else{
		Node *aux = &list;
		while(pos>0 && aux != nullptr){
			pos--;
			aux = aux->next;
		}
		
		Node *novo = new Node;
		if(novo == nullptr)
			return false;
			
		novo->data = value;
		novo->next = aux->next;
		novo->prev = aux;
		
		aux->next = novo;
		novo->next->prev = novo;
		return true;
		
	}
}

template <typename TYPE>
TYPE Sequence<TYPE>::removeFirst() {
	//std::cout << "RemoveFirst()" << std::endl;
	if(isEmpty()){
		//std::cout << "Não foi possível remover, lista vazia" << std::endl;
	}else{
		TYPE data;
		if(getSize() == 1)
		{
			data = list.next->data;
			delete list.next;
			list.next = nullptr;
			list.prev = nullptr;
		}
		else{
			Node *remove = list.next;
			remove->next->prev = nullptr;
			
			list.next = remove->next;
			data = remove->data;
			delete remove;
			
		}
		return data;
	}
}

template <typename TYPE>
TYPE Sequence<TYPE>::removeLast() {
	//std::cout << "RemoveLast()" << std::endl;
	if(isEmpty()){
		//std::cout << "Não foi possível remover, lista vazia" << std::endl;
	}else{
		TYPE data;
		if(getSize() == 1)
		{
			data = list.next->data;
			delete list.next;
			list.next = nullptr;
			list.prev = nullptr;
		}
		else{
			Node *aux = &list;
			while(aux->next->next != nullptr){
				aux = aux->next;
			}
			Node *toRemove = aux->next;
			list.prev = aux;
			aux->next = nullptr;
			TYPE value = toRemove->data;
			delete toRemove;
			
		}
		return data;
	}
}

template <typename TYPE>
TYPE Sequence<TYPE>::remove(int pos) {
	//std::cout << "remove" << std::endl;
	if(pos<0 || pos>getSize()-1){
		//std::cout << "nao foi possivel remover, fora do intervalo" <<std::endl;
	}else{
		
		if(pos == 0)
			return removeFirst();
		else if(pos == getSize()-1)
			return removeLast();
		else{
				Node *aux = &list;
				while(pos>0 && aux->next != nullptr){
					pos--;
					aux = aux->next;
				}
				
				Node *toRemove = aux->next;
				aux->next = toRemove->next;
				toRemove->next->prev = aux;
				
				TYPE value = toRemove->data;
				delete toRemove;
				return value;
					
			}
		
		
		
			
			
	
	}
}

template <typename TYPE>
TYPE Sequence<TYPE>::getFirst() {
	//std::cout << "getFirst:" << std::endl;
	if(!isEmpty())
		return list.next->data;
}

template <typename TYPE>
TYPE Sequence<TYPE>::getLast() {
	//std::cout << "getLast:" << std::endl;
	if(!isEmpty()){
		Node *node = &list;
		while(node->next != nullptr){
			node = node->next;
		}
		return node->data;
	}
}

template <typename TYPE>
TYPE Sequence<TYPE>::get(int pos) {
	//std::cout << "get:" << std::endl;
	if(pos>=0 && pos<getSize()){
			Node *node = &list;
			while(pos>0){
				pos--;
				node = node->next;
			}
			return node->next->data;

	}	
}

template <typename TYPE>
int Sequence<TYPE>::search(const TYPE &elm) {
	//std::cout << "search"<< std::endl;
	Node *node = &list;
	int pos = 0;
	while(node->next != nullptr){
		if(node->next->data == elm)
			return pos;
		node = node->next;
		pos++;
	}
	return -1;
}

template <typename TYPE>
bool Sequence<TYPE>::isEqual(Sequence<TYPE> &s) {
	//std::cout<< "isEqual"<< std::endl;
	/*std::cout<< "isEqual"<< std::endl;
	if(getSize() != s.getSize())
		return false;
	else{
		Node *n1 = &list;
		Node *n2 = &(s.list);
		
		while(n1->next != nullptr){
			if(n1->next->data != n2->next->data)
				return false;
			n1 = n1->next;
			n2 = n2->next;
		}
		return true;
	}*/
	return *this == s;
}

template <typename TYPE>
void Sequence<TYPE>::reverse() {
	//std::cout << "reverse" << std::endl;
	int i,j, posi, posj;
	Node *nodei, *nodej;
	for(i = 0, j=getSize()-1; i<getSize()/2; i++, j--){
		
		nodei = &list;
		posi=i;
		while(posi>0){
			nodei= nodei->next;
			posi--;
		}
		nodei = nodei->next;
		
		nodej = &list;
		posj=j;
		while(posj>0){
			nodej= nodej->next;
			posj--;
		}
		nodej = nodej->next;
		
		//std::cout << nodei->data << "  " << nodej->data << std::endl;
		swap(nodej, nodei);
		
		
	}

	
}

template <typename TYPE>
bool Sequence<TYPE>::isIncreasing(){
	//std::cout << "isIncreasing";
	
	Node *aux = &list;
	while(aux->next !=nullptr){
		if(aux->data <= aux->next->data)
		aux= aux->next;
		else
			return false;
	}
	return true;
}

template <typename TYPE>
bool Sequence<TYPE>::isDecreasing(){
	//std::cout << "isDecreasing";
	
	if(isIncreasing())
		return false;
	else
		return true;
}

template <typename TYPE>
void Sequence<TYPE>::bounds(TYPE &min, TYPE &max){
	//std::cout<<"bounds"<<std::endl;
	Node *node = &list;
	min = max= node->next->data;
	node = node->next;
	while(node->next != nullptr){
		if(node->next->data < min)
			min = node->next->data;
		if(node->next->data > max)
			max = node->next->data;
			
		node= node->next;
	}
}

template <typename TYPE>
void Sequence<TYPE>::sort() {
	//std::cout << "sort" << std::endl;
	int i,j, posA, posB;
	Node *nodeA, *nodeB;
	
	for(i=getSize(); i>0; i--){
		for(j=1; j<i; j++){
			
			posA = j-1;
			nodeA = &list;
			while(posA>0){
				nodeA = nodeA->next;
				posA--;
			}
			nodeA = nodeA->next;
			
			posB = j;
			nodeB = &list;
			while(posB>0){
				nodeB = nodeB->next;
				posB--;
			}
			nodeB = nodeB->next;
			
			
			if(nodeA->data > nodeB->data){
				//std::cout << nodeA->data << " " << nodeB->data << std::endl;
				swap(nodeA, nodeB);
				//std::cout<<"print";
				//print();
			}
		}
	}
}

template <typename TYPE>
void Sequence<TYPE>::print() {
	Node *aux = list.next;
	while(aux != nullptr){
		std::cout << aux->data<< ".";// << std::endl; 
		aux = aux->next;
	}
	std::cout<< std::endl; 
}

