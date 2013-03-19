#include<iostream>
#include<string>
#include "list.h"
#include "array.h"

using std::string;
using std::cout;
using std::endl;
using demo::List;
using demo::LinkedList;
using demo::ArrayList;

template<typename T> void printList(List<T> & list) {
	cout << "Contents of " << typeid(T).name() << " list are: ";
	for(int i=0;i<list.length();i++) {
		cout << list.get(i) << " "; 
	}
	cout << endl;
}

void testLinkedList();
void testArrayList();

int main() {
	testLinkedList();
	testArrayList();
}

void testLinkedList() {
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

void testArrayList() {
	ArrayList<int> listOfInt(2);
	ArrayList<string> listOfString(2);

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