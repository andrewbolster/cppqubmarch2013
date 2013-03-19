#include<iostream>
#include<string>
#include "list.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;
using demo::LinkedList;

void printMenu();

string itemToBeInserted;
int indexIntoList;

int main() {
	LinkedList<string> list;
	while(true) {
		printMenu();
		string choice;
		cin >> choice;
		if(choice == "add") {
			cout << "Enter a string to add" << endl;
			cin >> itemToBeInserted;
			list.add(itemToBeInserted);
		} else if(choice == "get") {
			cout << "Enter an index" << endl;
			cin >> indexIntoList;
			cout << "Item at " << indexIntoList << " is " << list.get(indexIntoList) << endl;
		} else if(choice == "remove") {
			cout << "Enter an index" << endl;
			cin >> indexIntoList;
			cout << "Item " << list.remove(indexIntoList) << " removed from position " << indexIntoList << endl;
		} else if(choice == "print") {
			cout << "Contents of list are: ";
			for(int i=0;i<list.length();i++) {
				cout << list.get(i) << " "; 
			}
			cout << endl;
		} else if(choice == "quit")  {
			cout << "Thanks for playing!" << endl;
			break;
		}
	}
}

void printMenu() {
	cout << "Choose an option:" << endl;
	cout << "\t [add] a string to the list" << endl;
	cout << "\t [get] a string at a specified position" << endl;
	cout << "\t [remove] a string from a specified position" << endl;
	cout << "\t [print] the current contents of the list" << endl;
	cout << "\t [quit] the program" << endl;
	cout << endl;
}