#ifndef COMMANDS_H
#define COMMANDS_H

#include<map>
#include<string>
#include "list.h"

using std::map;
using std::string;
using demo::LinkedList;

class Command;

class CommandManager {
public:
	CommandManager(LinkedList<string> *list);
	~CommandManager();
	Command * getCommand(const string & name);
private:
	map<string,Command *> commands;
};

class Command {
public:
	Command(LinkedList<string> * list);
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
protected:
	LinkedList<string> * list;
};

class AddCommand : public Command {
public:
	AddCommand(LinkedList<string> * list);
	void execute();
	void undo();
	void redo();
private:
	string item;
};

class GetCommand : public Command {
public:
	GetCommand(LinkedList<string> * list);
	void execute();
	void undo();
	void redo();
private:
	int index;
};

class RemoveCommand : public Command {
public:
	RemoveCommand(LinkedList<string> * list);
	void execute();
	void undo();
	void redo();
private:
	string item;
	int index;
};

class PrintCommand : public Command {
public:
	PrintCommand(LinkedList<string> * list);
	void execute();
	void undo();
	void redo();
private:
};




#endif //COMMANDS_H