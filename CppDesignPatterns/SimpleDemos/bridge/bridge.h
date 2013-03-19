#include<string>

using std::string;

class StackImpl;

/*
	All the private members of Stack are encapsulated by StackImpl
*/

class Stack {
private:
	StackImpl* pimpl;
public:
	Stack();
	~Stack();
	void add(string item);
	int size();
	string removeLast();
	string get(int index);
};
