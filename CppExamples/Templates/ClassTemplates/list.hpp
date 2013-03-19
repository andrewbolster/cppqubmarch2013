#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>

using std::cout;
using std::endl;

template<typename T> class Node {
public:
	~Node();
	Node(T item) ;
	Node(T item, Node<T> * next, Node<T> * prev);
	Node<T> * getNext();
	void setNext(Node<T> * next);
	Node<T> * getPrev();
	void setPrev(Node<T> * prev);
	T getItem();
private:
	Node<T> * next;
	Node<T> * prev;
	T item;
};

template<typename T> Node<T>::~Node() {
	cout << "End of node holding "
			<< item << endl;
}
template<typename T> Node<T>::Node(T item) {
	this->item = item;
	next = prev = 0;
}
template<typename T> Node<T>::Node(T item, Node<T> * next,
		  Node<T> * prev) {
	this->item = item;
	this->next = next;
	this->prev = prev;
}
template<typename T> Node<T> * Node<T>::getNext() {
	return next;
}
template<typename T> void Node<T>::setNext(Node<T> * next) {
	this->next = next;
}
template<typename T> Node<T> * Node<T>::getPrev() {
	return prev;
}
template<typename T> void Node<T>::setPrev(Node<T> * prev) {
	this->prev = prev;
}
template<typename T> T Node<T>::getItem() {
	return item;
}

template<typename T> class List {
public:
	List();
	~List();
	void add(T item);
	void print();
	void remove(int index);
	T get(int index);
private:
	int size;
	Node<T> * first;
};

template<typename T> List<T>::List() : size(0), first(0) {
}
template<typename T> List<T>::~List() {
	Node<T> * toDie = first;
	while(toDie) {
		Node<T> * tmp = toDie;
		toDie = toDie->getNext();
		delete tmp;
	}
}
template<typename T> void List<T>::add(T item) {
	if(size == 0) {
		first = new Node<T>(item);
	} else {
		Node<T> * tmp = first;
		while(tmp->getNext() != 0) {
			tmp = tmp->getNext();
		}
		tmp->setNext(new Node<T>(item,0,tmp));
	}
	size++;
}
template<typename T> void List<T>::print() {
	if(size == 0) {
		cout << "list is empty" << endl;
	} else {
		cout << "contents are:" << endl;
		Node<T> * tmp = first;
		while(tmp) {
			cout << tmp->getItem() << endl;
			tmp = tmp->getNext();
		}
	}
}
template<typename T> T List<T>::get(int index) {
	Node<T> * tmp = first;
	for(int i=0;i<index;i++) {
		tmp = tmp->getNext();
	}
	return tmp->getItem();
}
template<typename T> void List<T>::remove(int index) {
	Node<T> * tmp = first;
	if(index == 0) {
		first = first->getNext();
		if(first != 0) {
			first->setPrev(0);
		}
	} else {
		for(int i=0;i<index;i++) {
			tmp = tmp->getNext();
		}
		if(tmp->getNext() == 0) {
			tmp->getPrev()->setNext(0);
		} else {
			Node<T> * before = tmp->getPrev();
			Node<T> * after = tmp->getNext();
			before->setNext(after);
			after->setPrev(before);
		}
	}
	delete tmp;
	size--;
}

#endif //LIST_HPP