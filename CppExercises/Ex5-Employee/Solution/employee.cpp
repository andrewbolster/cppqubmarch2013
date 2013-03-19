#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee(const char * name) {
	this->name = name;
	age = 0;
	salary = 0.0;
}
Employee::Employee(const char * name, int age, double salary) {
	this->name = name;
	this->age = age;
	this->salary = salary;
}
Employee::~Employee() {
	cout << "End of " << name << " at " << this << endl;
}
void Employee::awardBonus(double bonus) {
	salary += bonus;
}
void Employee::print() {
	cout << name << " of age " << age << " earning " << salary << endl;
}