#include<iostream>
#include<string>
#include "list.h"
#include "commands.h"


using std::string;
using std::cout;
using std::cin;
using std::map;
using std::endl;
using demo::LinkedList;

void printMenu();

int main() {
	LinkedList<string> list;
	CommandManager manager(&list);
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