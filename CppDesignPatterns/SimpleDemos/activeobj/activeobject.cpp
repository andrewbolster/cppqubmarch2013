#include<iostream>
#include "windows.h"

using namespace std;

class Interface;
class Implementation;

typedef void(Interface::*MethodPtr)();

class Interface {
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
	virtual void func3() = 0;
	virtual void func4() = 0;

};

class ActiveObject : public Interface {
public:
	ActiveObject(Interface& iptr);
	void func1();
	void func2();
	void func3();
	void func4();
private:
	Interface& imp;
};

class Implementation : public Interface {
public:
	void func1();
	void func2();
	void func3();
	void func4();
};

struct ThreadData {
	ThreadData(Interface* ptr, MethodPtr mp) : obj(ptr), mptr(mp) {}
	Interface* obj;
	MethodPtr mptr;
};

void startFunction(ThreadData& data) {
	(data.obj->*data.mptr)();
}

void Implementation::func1() {
	for(int i=0; i<100; i++) {
		printf("func1() loop %d\n",i);
		//cout << "func1() loop " << i << endl;
		Sleep(500);
	}
}

void Implementation::func2() {
	for(int i=0; i<100; i++) {
		printf("func2() loop %d\n",i);
		//cout << "func2() loop " << i << endl;
		Sleep(500);
	}
}

void Implementation::func3() {
	for(int i=0; i<100; i++) {
		printf("func3() loop %d\n",i);
		//cout << "func3() loop " << i << endl;
		Sleep(500);
	}
}

void Implementation::func4() {
	for(int i=0; i<100; i++) {
		printf("func4() loop %d\n",i);
		//cout << "func4() loop " << i << endl;
		Sleep(500);
	}
}

ActiveObject::ActiveObject(Interface& iptr) : imp(iptr) {}

void ActiveObject::func1() {
	static ThreadData d(&imp,Interface::func1);
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)startFunction,(void *)&d,0,0);
}
void ActiveObject::func2() {
	static ThreadData d(&imp,Interface::func2);
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)startFunction,(void *)&d,0,0);
}
void ActiveObject::func3() {
	static ThreadData d(&imp,Interface::func3);
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)startFunction,(void *)&d,0,0);
}
void ActiveObject::func4() {
	static ThreadData d(&imp,Interface::func4);
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)startFunction,(void *)&d,0,0);
}


Interface* buildActiveObject(Interface& obj) {
	return new ActiveObject(obj);
}

//global data - visible to all threads
Implementation implementation;


void main() {

	Interface* i_ptr = buildActiveObject(implementation);

	i_ptr->func1();
	i_ptr->func2();
	i_ptr->func3();
	i_ptr->func4();

	Sleep(INFINITE);	
}