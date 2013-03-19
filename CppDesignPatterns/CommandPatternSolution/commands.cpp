#include "commands.h"
#include <iostream>

using namespace std;

CommandManager::CommandManager(LinkedList<string> *list) {
	commands["add"] = new AddCommand(list);
	commands["get"] = new GetCommand(list);
	commands["remove"] = new RemoveCommand(list);
	commands["print"] = new PrintCommand(list);
}
CommandManager::~CommandManager() {
	map<string,Command *>::iterator iterator;
	for(iterator = commands.begin(); iterator != commands.end(); iterator++) {
		delete iterator->second;
	}
}
Command * CommandManager::getCommand(const string & name) {
	return commands[name];
}


Command::Command(LinkedList<string> *list) {
	this->list = list;
}
GetCommand::GetCommand(LinkedList<string> *list) : Command(list) {
	index = 0;
}
AddCommand::AddCommand(LinkedList<string> *list) : Command(list) {
	item = "";
}
RemoveCommand::RemoveCommand(LinkedList<string> *list) : Command(list) {
	item = "";
	index = 0;
}
PrintCommand::PrintCommand(LinkedList<string> *list) : Command(list) {}

/*
	Methods for AddCommand
*/
void AddCommand::execute() {
	cout << "Enter a string to add" << endl;
	cin >> item;
	list->add(item);
}
void AddCommand::undo() {
	int size = list->length();
	list->remove(size - 1);
}
void AddCommand::redo() {
	list->add(item);
}
/*
	Methods for GetCommand
*/
void GetCommand::execute() {
	cout << "Enter an index" << endl;
	cin >> index;
	cout << "Item at " << index << " is " << list->get(index) << endl;
}
void GetCommand::undo() {
	cout << "A get cannot be undone..." << endl;
}
void GetCommand::redo() {
	cout << "Item at " << index << " is " << list->get(index) << endl;
}
/*
	Methods for RemoveCommand
*/
void RemoveCommand::execute() {
	cout << "Enter an index" << endl;
	cin >> index;
	item = list->remove(index);
	cout << "Item " << item << " removed from position " << index << endl;
}
void RemoveCommand::undo() {
	//TODO - insert should really be used here...
	list->add(item);
}
void RemoveCommand::redo() {
	cout << "Item " << list->remove(index) << " removed from position " << index << endl;
}
/*
	Methods for PrintCommand
*/
void PrintCommand::execute() {
	cout << "Contents of list are: ";
	for(int i=0;i<list->length();i++) {
		cout << list->get(i) << " "; 
	}
	cout << endl;
}
void PrintCommand::undo() {
	cout << "A print cannot be undone..." << endl;
}
void PrintCommand::redo() {
	if(list->length() == 0) {
		cout << "List is empty!" << endl;
	} else {
		cout << "Contents of list are: ";
		for(int i=0;i<list->length();i++) {
			cout << list->get(i) << " "; 
		}
		cout << endl;
	}
}
