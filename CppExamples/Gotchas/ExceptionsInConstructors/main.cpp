#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
	MyClass(int i);
	~MyClass();
};

MyClass::MyClass(int i) {
	cout << "MyClass constructor" << endl;
	if(i > 0) {
		throw string("Exception from MyClass constructor");
	}
}

MyClass::~MyClass() {
	cout << "MyClass destructor" << endl;
}

void op1() {
	MyClass mc(-1);
}
void op2() {
	MyClass mc(1);
}

int main() {
	cout << "About to call op1" << endl;
	try {
		op1();
	} catch(string & ex) {
		cout << "Catch block one caught: " << ex << endl;
	}
	cout << "About to call op2" << endl;
	try {
			op2();
	} catch(string & ex) {
		cout << "Catch block two caught: " << ex << endl;
	}
}

