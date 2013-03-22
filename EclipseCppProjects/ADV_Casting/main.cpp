#include <iostream>

using namespace std;

class Employee {
public:
	void op1();
	virtual ~Employee();
};

class Manager : public Employee {
public:
	void op2();
};

void castAwayConst(const int * ptr);
void downcast(Employee * ptr);
void reinterpret();
void standard();

int main() {
	int val = 123;
	castAwayConst(&val);

	cout << "----- Casting Away Const -----" << endl;
	cout << "Value of val is: " << val << endl;

	cout << "----- Performing Downcasts -----" << endl;
	Manager m;
	downcast(&m);

	cout << "----- Reinterpreting Types -----" << endl;
	reinterpret();

	cout << "----- Standard Casts -----" << endl;
	standard();
}

Employee::~Employee() {
}

void Employee::op1() {
	cout << "Employee method..." << endl;
}

void Manager::op2() {
	cout << "Manager method..." << endl;
}

void castAwayConst(const int * ptr) {
	int * tmp = const_cast<int *>(ptr);
	*tmp = 456;
}

void downcast(Employee * ptr) {
	ptr->op1();
	Manager * tmp = dynamic_cast<Manager *>(ptr);
	tmp->op2();
}

void reinterpret() {
	const char * str1  = "ABCDEF";
	long val = reinterpret_cast<long>(str1);
	const char * str2 =  reinterpret_cast<const char *>(val);
	cout << "Value of string is " << str2 << endl;
}

void standard() {
	double val = 12.345;
	float tmp = static_cast<float>(val);
	cout << "Value of float is " << tmp << endl;
}

