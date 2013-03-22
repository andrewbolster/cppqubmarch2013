#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printMenu();

string itemToBeInserted;
int indexIntoList;

int main() {
	vector<string> strList;
	while(true) {
		printMenu();
		string choice;
		cin >> choice;
		if(choice == "add") {
			cout << "Enter a string to add" << endl;
			cin >> itemToBeInserted;
			strList.push_back(itemToBeInserted);
		} else if(choice == "get") {
			cout << "Enter an index" << endl;
			cin >> indexIntoList;
			cout << "Item at " << indexIntoList << " is " << strList[indexIntoList] << endl;
		} else if(choice == "remove") {
			cout << "Enter an index" << endl;
			cin >> indexIntoList;
			vector<string>::iterator iter = strList.begin() + indexIntoList;
			string tmp = *iter;
			strList.erase(iter);
			cout << "Item " << tmp  << " removed from position " << indexIntoList << endl;
		} else if(choice == "print") {
			cout << "Contents of list are: ";
			for(unsigned int i=0;i<strList.size();i++) {
				cout << strList[i] << " ";
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
