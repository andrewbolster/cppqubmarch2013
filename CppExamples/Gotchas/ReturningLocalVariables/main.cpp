#include <iostream>
#include <string>

using namespace std;

//never return the address of
// a local variable...
int * op1() {
	int value = 101;
	return &value;
}

void op2() {
	double d = 123.456;
}

int main() {
	int * result = op1();
	cout << "Result is " << *result << endl;
	op2();
	cout << "Result is " << *result << endl;
}