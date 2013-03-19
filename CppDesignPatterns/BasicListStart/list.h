#ifndef LIST_H
#define LIST_H

namespace demo {

	template <typename T> class Node {
	public:
		Node(T item, Node<T> * next, Node<T> * prev)
					: item(item), next(next), prev(prev) {}
		Node<T> * getNext() { return next; }
		void setNext(Node<T> * node) { next  = node; }
		T & getItem() { return item; }
	private:
		Node<T> * next;
		Node<T> * prev;
		T item;
	};

	template <typename T> class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		void add(T item);
		T get(int index);
		int length();
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
		Node<T> * current = first;
		for(int i=0;i<index;i++) {
			current = current->getNext();
		}
		return current->getItem();
	}
}
#endif //LIST_H
