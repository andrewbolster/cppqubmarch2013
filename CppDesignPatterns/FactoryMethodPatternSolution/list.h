#ifndef LIST_H
#define LIST_H

#include "interface.h"

namespace demo {

	template <typename T> class Node  {
	public:
		Node(T item, Node<T> * next, Node<T> * prev) 
					: item(item), next(next), prev(prev) {}
		Node<T> * getNext() { return next; }
		Node<T> * getPrev() { return prev; }
		void setNext(Node<T> * node) { next  = node; }
		void setPrev(Node<T> * node) { prev  = node; }
		T & getItem() { return item; }
	private:
		Node<T> * next;
		Node<T> * prev;
		T item;
	};

	template <typename T> class LinkedList : public List<T> {
	public:
		LinkedList();
		~LinkedList();
		void add(T item);
		T get(int index);
		int length();
		T remove(int index);
	private:
		T removeFirst();
		T removeLast();
		T removeFromMiddle(int index);
		Node<T> * walkToNode(int index);
	private:
		Node <T> * first;
		int size;
	};

	template <typename T> LinkedList<T>::LinkedList() : size(0), first(0) {
	}

	template <typename T> LinkedList<T>::~LinkedList() {
		Node<T> * current = first;
		while(current != 0) {
			Node<T> * tmp = current;
			current = current->getNext();
			delete tmp;
		}
	}

	template <typename T> int LinkedList<T>::length() {
		return size;
	}

	template <typename T> void LinkedList<T>::add(T item) {
		if(0 == first) {
			first = new Node<T>(item,0,0);
		} else {
			Node<T> * current = first;
			while(current->getNext() != 0) {
				current = current->getNext();
			}
			current->setNext(new Node<T>(item,0,current));
		}
		size++;
	}

	template <typename T> T LinkedList<T>::get(int index) {
		Node<T> * current = walkToNode(index);
		return current->getItem();
	}
	template <typename T> Node<T> * LinkedList<T>::walkToNode(int index) {
		Node<T> * current = first;
		for(int i=0;i<index;i++) {
			current = current->getNext();
		}
		return current;
	}

	template <typename T> T LinkedList<T>::remove(int index) {
		T item;
		if(index == 0) {
			item = removeFirst();
		} else if(index == (size -1)) {
			item = removeLast();
		} else {
			item = removeFromMiddle(index);
		}
		size--;
		return item;
	}

	template <typename T> T LinkedList<T>::removeFirst() {
		Node<T> * tmp = first;
		first = first->getNext();
		if(first != 0) {
			first->setPrev(0);
		}
		T value = tmp->getItem();
		delete tmp;
		return value;
	}

	template <typename T> T LinkedList<T>::removeLast() {
		Node<T> * last = walkToNode(size - 1);
		last->getPrev()->setNext(0);
		T value = last->getItem();
		delete last;
		return value;
	}

	template <typename T> T LinkedList<T>::removeFromMiddle(int index) {
		Node<T> * chosen = walkToNode(index);
		Node<T> * before = chosen->getPrev();
		Node<T> * after = chosen->getNext();
		before->setNext(after);
		after->setPrev(before);
		T value = chosen->getItem();
		delete chosen;
		return value;
	}
}
#endif //LIST_H
