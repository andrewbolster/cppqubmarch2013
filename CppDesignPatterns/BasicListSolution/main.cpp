#include<iostream>
#include<string>
#include "list.h"


using std::string;
using std::cout;
using std::endl;
using demo::LinkedList;

template<typename T> void printList(LinkedList<T> & list) {
	cout << "Contents of " << typeid(T).name() << " list are: ";
	for(int i=0;i<list.length();i++) {
		cout << list.get(i) << " "; 
	}
	cout << endl;
}

int main() {
	LinkedList<int> listOfInt;
	LinkedList<string> listOfString;

	listOfInt.add(10);
	listOfInt.add(20);
	listOfInt.add(30);
	listOfInt.add(40);
	listOfInt.add(50);

	listOfString.add("abc");
	listOfString.add("def");
	listOfString.add("ghi");
	listOfString.add("jkl");
	listOfString.add("mno");

	printList(listOfInt);
	listOfInt.remove(0);
	printList(listOfInt);
	listOfInt.remove(3);
	printList(listOfInt);
	listOfInt.remove(1);
	printList(listOfInt);

	printList(listOfString);
	listOfString.remove(0);
	printList(listOfString);
	listOfString.remove(3);
	printList(listOfString);
	listOfString.remove(1);
	printList(listOfString);
}