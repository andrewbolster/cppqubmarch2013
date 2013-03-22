#include "list.h"
#include<iostream>

using namespace std;

class Node {
public:
	~Node();
	Node(string item);
	Node(string item, Node * next, Node * prev);
	Node * getNext();
	void setNext(Node * next);
	Node * getPrev();
	void setPrev(Node * prev);
	string getItem();
private:
	Node * next;
	Node * prev;
	string item;
};

Node::~Node() {
	cout << "End of node holding "
			<< item << endl;
}
Node::Node(string item) {
	this->item = item;
	next = prev = 0;
}
Node::Node(string item, Node * next,
		  Node * prev) {
	this->item = item;
	this->next = next;
	this->prev = prev;
}
Node * Node::getNext() {
	return next;
}
void Node::setNext(Node * next) {
	this->next = next;
}
Node * Node::getPrev() {
	return prev;
}
void Node::setPrev(Node * prev) {
	this->prev = prev;
}
string Node::getItem() {
	return item;
}

List::List() : size(0), first(0) {
}
List::~List() {
	Node * toDie = first;
	while(toDie) {
		Node * tmp = toDie;
		toDie = toDie->getNext();
		delete tmp;
	}
}
void List::add(string item) {
	if(size == 0) {
		first = new Node(item);
	} else {
		Node * tmp = first;
		while(tmp->getNext() != 0) {
			tmp = tmp->getNext();
		}
		tmp->setNext(new Node(item,0,tmp));
	}
	size++;
}
void List::print() {
	if(size == 0) {
		cout << "list is empty" << endl;
	} else {
		cout << "contents are:" << endl;
		Node * tmp = first;
		while(tmp) {
			cout << tmp->getItem() << endl;
			tmp = tmp->getNext();
		}
	}
}
void List::remove(int index) {
	Node * tmp = first;
	if(index == 0) {
		//remove first node
		first = first->getNext();
		//avoid error on single item list
		if(first != 0) {
			first->setPrev(0);
		}
	} else {
		//walk to selected node
		for(int i=0;i<index;i++) {
			tmp = tmp->getNext();
		}
		if(tmp->getNext() == 0) {
			//remove last node
			tmp->getPrev()->setNext(0);
		} else {
			//remove node from middle
			Node * before = tmp->getPrev();
			Node * after = tmp->getNext();
			before->setNext(after);
			after->setPrev(before);
		}
	}
	delete tmp;
	size--;
}