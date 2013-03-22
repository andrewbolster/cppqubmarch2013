#ifndef COMMANDS_H
#define COMMANDS_H

#include<map>
#include<string>
#include<vector>

using namespace std;

class Command;

class CommandManager {
public:
	CommandManager(vector<string> *list);
	~CommandManager();
	Command * getCommand(const string & name);
private:
	map<string,Command *> commands;
};

class Command {
public:
	Command(vector<string> * list);
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
protected:
	vector<string> * list;
};

class AddCommand : public Command {
public:
	AddCommand(vector<string> * list);
	void execute();
	void undo();
	void redo();
private:
	string item;
};

class GetCommand : public Command {
public:
	GetCommand(vector<string> * list);
	void execute();
	void undo();
	void redo();
private:
	int index;
};

class RemoveCommand : public Command {
public:
	RemoveCommand(vector<string> * list);
	void execute();
	void undo();
	void redo();
private:
	string item;
	int index;
};

class PrintCommand : public Command {
public:
	PrintCommand(vector<string> * list);
	void execute();
	void undo();
	void redo();
private:
};

#endif //COMMANDS_H
