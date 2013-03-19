#ifndef LIST_H
#define LIST_H

#include<string>

using std::string;

class Node;

class List {
public:
	List();
	~List();
	void add(string item);
	void print();
	void remove(int index);
private:
	int size;
	Node * first;
};

#endif //LIST_H