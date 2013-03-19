#include<iostream>
#include<string>
#include "list.h"

using std::string;
using std::cout;
using std::endl;

using namespace demo;

template<typename T> void printList(List<T> & list) {
	cout << "Contents of list are: ";
	for(int i=0;i<list.length();i++) {
		cout << list.get(i) << " "; 
	}
	cout << endl;
}

int main() {
	LinkedList<int> listOfInt;
	LinkedList<string> listOfString;

	listOfInt.add(10);
	listOfInt.add(30);
	listOfInt.add(20);
	listOfInt.add(30);
	listOfInt.add(30);
	listOfInt.add(40);
	listOfInt.add(50);
	listOfInt.add(30);

	listOfString.add("abc");
	listOfString.add("qwe");
	listOfString.add("def");
	listOfString.add("ghi");
	listOfString.add("qwe");
	listOfString.add("jkl");
	listOfString.add("mno");
	listOfString.add("qwe");

	printList(listOfString);
	printList(listOfInt);
}