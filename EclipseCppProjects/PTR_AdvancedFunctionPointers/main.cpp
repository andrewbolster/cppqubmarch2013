#include <iostream>

using namespace std;

void func() {
	cout << "<void>func()" << endl;
}
int func(int i) {
	cout << "<int>func(<int>)" << endl;
	return i;
}
int func(int i,double d) {
	cout << "<int>func(<int><double>)" << endl;
	return i;
}
class MyClass {
public:
	int func() {
		cout << "<int>MyClass::func()" << endl;
		return 0;
	}
};

int main() {

	//The compiler can work out which function
	// we mean via the type of the pointer
	void(*f_ptr1)() = func;
	int(*f_ptr2)(int) = func;
	int(*f_ptr3)(int,double) = func;

	f_ptr1();
	f_ptr2(27);
	f_ptr3(27,8.3);

	//Show both ways of calling a method
	// via a pointer
	MyClass mc;
	MyClass *mc_ptr = &mc;
	int(MyClass::*m_ptr)() = &MyClass::func;
	(mc.*m_ptr)();
	(mc_ptr->*m_ptr)();

        return 0;
}
