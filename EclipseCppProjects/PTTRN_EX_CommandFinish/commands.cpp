#include "commands.h"
#include <iostream>

using namespace std;

CommandManager::CommandManager(vector<string> *list) {
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


Command::Command(vector<string> *list) {
	this->list = list;
}
GetCommand::GetCommand(vector<string> *list) : Command(list) {
	index = 0;
}
AddCommand::AddCommand(vector<string> *list) : Command(list) {
	item = "";
}
RemoveCommand::RemoveCommand(vector<string> *list) : Command(list) {
	item = "";
	index = 0;
}
PrintCommand::PrintCommand(vector<string> *list) : Command(list) {}

/*
	Methods for AddCommand
*/
void AddCommand::execute() {
	cout << "Enter a string to add" << endl;
	cin >> item;
	list->push_back(item);
}
void AddCommand::undo() {
	list->pop_back();
}
void AddCommand::redo() {
	list->push_back(item);
}
/*
	Methods for GetCommand
*/
void GetCommand::execute() {
	cout << "Enter an index" << endl;
	cin >> index;
	cout << "Item at " << index << " is " << (*list)[index] << endl;
}
void GetCommand::undo() {
	cout << "A get cannot be undone..." << endl;
}
void GetCommand::redo() {
	cout << "Item at " << index << " is " << (*list)[index] << endl;
}
/*
	Methods for RemoveCommand
*/
void RemoveCommand::execute() {
	cout << "Enter an index" << endl;
	cin >> index;
	vector<string>::iterator iter = list->begin() + (index - 1);
	string tmp = *iter;
	list->erase(iter);
	cout << "Item " << tmp << " removed from position " << index << endl;
}
void RemoveCommand::undo() {
	//TODO - insert should really be used here...
	list->push_back(item);
}
void RemoveCommand::redo() {
	vector<string>::iterator iter = list->begin() + (index - 1);
	string tmp = *iter;
	list->erase(iter);
	cout << "Item " << tmp << " removed from position " << index << endl;
}
/*
	Methods for PrintCommand
*/
void PrintCommand::execute() {
	cout << "Contents of list are: ";
	for(unsigned int i=0;i<list->size();i++) {
		cout << (*list)[i] << " ";
	}
	cout << endl;
}
void PrintCommand::undo() {
	cout << "A print cannot be undone..." << endl;
}
void PrintCommand::redo() {
	if(list->size() == 0) {
		cout << "List is empty!" << endl;
	} else {
		cout << "Contents of list are: ";
		for(unsigned int i=0;i<list->size();i++) {
			cout << (*list)[i] << " ";
		}
		cout << endl;
	}
}


