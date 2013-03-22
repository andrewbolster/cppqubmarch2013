#include<iostream>
#include<string>
#include<vector>
#include "commands.h"


using namespace std;

void printMenu();

int main() {
	vector<string> strList;
	CommandManager manager(&strList);
	Command * currentCommand;
	while(true) {
		printMenu();
		string choice;
		cin >> choice;
		if(choice == "quit")  {
			cout << "Thanks for playing!" << endl;
			break;
		} else if(choice == "undo") {
			currentCommand->undo();
		} else if(choice == "redo") {
			currentCommand->redo();
		} else {
			currentCommand = manager.getCommand(choice);
			currentCommand->execute();
		}
	}
}
void printMenu() {
	cout << "Choose an option:" << endl;
	cout << "\t [add] a string to the list" << endl;
	cout << "\t [get] a string at a specified position" << endl;
	cout << "\t [remove] a string from a specified position" << endl;
	cout << "\t [print] the current contents of the list" << endl;
	cout << "\t [undo] the last command" << endl;
	cout << "\t [redo] the last command" << endl;
	cout << "\t [quit] the program" << endl;
	cout << endl;
}

