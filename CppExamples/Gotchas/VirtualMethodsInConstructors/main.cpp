#include <iostream>

using namespace std;


class Base {
public:
	Base();
	virtual void func();
};

class Derived : public Base {
public:
	Derived();
	void func();
};

Base::Base() {
	func();
}
Derived::Derived() : Base() {
}
void Base::func() {
	cout << "Base version of func called..." << endl;
}
void Derived::func() {
	cout << "Derived version of func called..." << endl;
}

int main() {
	Derived d;
}