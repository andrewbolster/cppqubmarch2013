#include "bridge.h"

/*
	All the private members of Stack are encapsulated by StackImpl
*/


class Node{
private:
	string item;
	Node *next;
public:
	Node(string in):item(in),next(0){}

	void setNext(Node* n=0){ next=n; }
	Node* getNext(){ return next; }
	string getItem(){ return item; }
};

class StackImpl {
private:
	Node *first;
	int currentSize;
public:
	StackImpl();
	void add(string item);
	int size();
	string removeLast();
	string get(int index);
};

StackImpl::StackImpl() : first(0), currentSize(0) {}

int StackImpl::size(){
	return currentSize;
}

void StackImpl::add(string item){
	if(!first){
		first = new Node(item);
	}
	else {
		Node *ptr = first;
		while(ptr->getNext())
			ptr = ptr->getNext();
		ptr->setNext(new Node(item));
	}
	currentSize++;
}

string StackImpl::get(int index){
	if(!first) throw "no element";

	Node *ptr = first;

	for(int i=1; i<index; i++) {
		ptr = ptr->getNext();
		if(!ptr) throw "no element";
	}

	return ptr->getItem();
}

string StackImpl::removeLast(){
	Node *ptr = first;
	Node *before_ptr = 0;

	if(!first) throw "no element";

	while(ptr->getNext()){
		before_ptr = ptr;
		ptr = ptr->getNext();
	}

	string item = ptr->getItem();

	if(ptr != first) {
		delete ptr;
		before_ptr->setNext();
	}
	else {
		delete first;
		first = 0;
	}

	currentSize--;

	return item;
}

//All the members of Stack are implemented using StackImpl
Stack::Stack() {
	pimpl = new StackImpl();
}

Stack::~Stack() {
	delete pimpl;
}

void Stack::add(string item){
	pimpl->add(item);
}

string Stack::get(int index){
	return pimpl->get(index);
}

string Stack::removeLast(){
	return pimpl->removeLast();
}

int Stack::size(){
	return pimpl->size();
}
