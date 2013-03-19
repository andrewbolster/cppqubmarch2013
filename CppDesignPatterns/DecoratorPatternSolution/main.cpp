#include<iostream>
#include<string>
#include "list.h"
#include "array.h"
#include "decorator.h"


using std::string;
using std::cout;
using std::endl;
using demo::List;
using demo::LinkedList;
using demo::ArrayList;
using demo::UnmodifiableList;

void testList(List<string> & list) {
	cout << "Contents of list are: ";
	for(int i=0;i<list.length();i++) {
		cout << list.get(i) << " "; 
	}
	cout << endl;
	try {
		list.add("ZZZ");
		cout << "Call to add successful!" << endl;
	} catch(string & ex) {
		cout << "Call to add threw " << ex << endl;
	}
	try {
		list.remove(0);
		cout << "Call to remove successful!" << endl;
	} catch(string & ex) {
		cout << "Call to remove threw " << ex << endl;
	}
}

int main() {
	LinkedList<string> linkedList;
	ArrayList<string> arrayList(5);

	linkedList.add("abc");
	linkedList.add("def");
	linkedList.add("ghi");
	linkedList.add("jkl");
	linkedList.add("mno");

	arrayList.add("pqr");
	arrayList.add("stu");
	arrayList.add("vwx");
	arrayList.add("yza");
	arrayList.add("bcd");

	UnmodifiableList<string> wrapper1(linkedList);
	UnmodifiableList<string> wrapper2(arrayList);

	cout << endl << "----- Testing Unmodifiable Linked List -----" << endl;
	testList(wrapper1);
	cout << endl << "----- Testing Unmodifiable Array List -----" << endl;
	testList(wrapper2);

}