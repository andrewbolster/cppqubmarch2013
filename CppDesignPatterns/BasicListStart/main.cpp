#include<iostream>
#include<string>
#include "list.h"


using std::string;
using std::cout;
using std::endl;
using demo::LinkedList;

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

	cout << "Contents of int list are: ";
	for(int i=0;i<listOfInt.length();i++) {
		cout << listOfInt.get(i) << " ";
	}
	cout << endl;

	cout << "Contents of string list are: ";
	for(int i=0;i<listOfString.length();i++) {
		cout << listOfString.get(i) << " ";
	}
	cout << endl;
}