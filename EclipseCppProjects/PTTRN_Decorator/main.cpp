#include<iostream>
#include<string>

using namespace std;

/* An Abstract Stack Template */

template<class T> class Stack {
public:
	virtual void add(T item) = 0;
	virtual T removeLast() = 0;
	virtual T get(int index) = 0;
};

/* A Simple Stack Implementation */

template <class T> class Node{
private:
	T item;
	Node *next;
public:
	Node(T in):item(in),next(0){}

	void setNext(Node* n=0){ next=n; }
	Node* getNext(){ return next; }
	T getItem(){ return item; }
};


template<class T> class SimpleStack : public Stack<T> {
private:
	Node<T> *first;
public:
	SimpleStack();
	void add(T item);
	T removeLast();
	T get(int index);
};

template<class T> SimpleStack<T>::SimpleStack() : first(0){}

template<class T> void SimpleStack<T>::add(T item){
	if(!first){
		first = new Node<T>(item);
	}
	else {
		Node<T> *ptr = first;
		while(ptr->getNext())
			ptr = ptr->getNext();
		ptr->setNext(new Node<T>(item));
	}
}

template<class T> T SimpleStack<T>::get(int index){
	if(!first) throw "no element";

	Node<T> *ptr = first;

	for(int i=1; i<index; i++) {
		ptr = ptr->getNext();
		if(!ptr) throw "no element";
	}

	return ptr->getItem();
}

template<class T> T SimpleStack<T>::removeLast(){
	Node<T> *ptr = first;
	Node<T> *before_ptr = 0;

	if(!first) throw "no element";

	while(ptr->getNext()){
		before_ptr = ptr;
		ptr = ptr->getNext();
	}

	T item = ptr->getItem();

	if(ptr != first) {
		delete ptr;
		before_ptr->setNext();
	}
	else {
		delete first;
		first = 0;
	}

	return item;
}

/* A Decorator Class Which Creates an Unmodifiable Stack */
/* Another example would be a thread safe stack */

template<class T> class UnmodifiableStack : public Stack<T> {
private:
	Stack<T>& stack;
public:
	UnmodifiableStack(Stack<T>& s);
	void add(T item);
	T removeLast();
	T get(int index);
};

template<class T> UnmodifiableStack<T>::UnmodifiableStack(Stack<T>& s) : stack(s) {}

template<class T> void UnmodifiableStack<T>::add(T item) {
	throw "stack cannot be modified";
}

template<class T> T UnmodifiableStack<T>::removeLast() {
	throw "stack cannot be modified";
}

template<class T> T UnmodifiableStack<T>::get(int index) {
	return stack.get(index);
}

void untrustedCode(Stack<string>& s) {
	cout << "item 4 is " << s.get(4) << endl;

	//illegal operation
	s.removeLast();
}

int main() {
	SimpleStack<string> stack;

	stack.add("abc");
	stack.add("def");
	stack.add("ghi");
	stack.add("jkl");
	stack.add("mno");
	stack.add("pqr");
	stack.add("stu");

	cout << "item 7 is " << stack.get(7) << endl;

	try {
		UnmodifiableStack<string> safeStack(stack);

		untrustedCode(safeStack);
	} catch(char *msg) {
		cout << "caught exception: " << msg << endl;
	}
}


