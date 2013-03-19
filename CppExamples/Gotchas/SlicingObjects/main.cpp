#include <iostream>

using namespace std;

class Base {
public:
	virtual void func();
};

class Derived : public Base {
public:
	void func();
};

void Base::func() {
	cout << "Base version of func called..." << endl;
}
void Derived::func() {
	cout << "Derived version of func called..." << endl;
}

void test(Base b) {
	b.func();
}

int main() {
	Derived d;

	//show slicing in arrays
	Base tstarray[10];
	tstarray[0] = d;
	tstarray[0].func();

	//show slicing in parameters
	test(d);
}