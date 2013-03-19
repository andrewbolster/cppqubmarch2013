#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
	~MyClass();
};

MyClass::~MyClass() {
	throw string("Exception from ~MyClass ");
}

void op1(int i) {
	if(i > 0) {
		throw string("Exception from op2");
	}
}
void op2() {
	MyClass mc;
	op1(-1);
}
void op3() {
	MyClass mc;
	op1(1);
}

void myTerminate() {
	cout << "Custom terminate function called" << endl << endl;
}

int main() {
	set_terminate(&myTerminate);
	cout << "About to call op2" << endl;
	try {
		op2();
	} catch(string & ex) {
		cout << "Catch block one caught: " << ex << endl;
	}
	cout << "About to call op3" << endl;
	try {
			op3();
		} catch(string & ex) {
			cout << "Catch block two caught: " << ex << endl;
	}
}

