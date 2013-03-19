#include<iostream>
#include<string>
#include "list.h"
#include "equality_predicate.h"
#include "append_transformation.h"


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

	EqualityPredicate<string> predicateOne("qwe");
	cout << "Predicate found " << listOfString.collect(predicateOne) << " matches in string list" << endl;

	EqualityPredicate<int> predicateTwo(30);
	cout << "Predicate found " << listOfInt.collect(predicateTwo) << " matches in integer list" << endl;

	AppendTransformation<string> transformOne("XXX");
	listOfString.transform(transformOne);
	printList(listOfString);

	AppendTransformation<int> transformTwo(8);
	listOfInt.transform(transformTwo);
	printList(listOfInt);
}