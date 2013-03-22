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
void Employee::awardBonus(double bonus) {
	salary += bonus;
}
void Employee::print() {
	cout << name << " of age " << age << " earning " << salary << endl;
}
Manager::Manager(const char * name, int age,
				 double salary, const char * deptName,
				 double budget) : Employee(name,age,salary) {
	  this->deptName = deptName;
	  this->budget = budget;

}
void Manager::raiseBudget(double increment) {
	budget += increment;
}
void Manager::awardBonus(double bonus) {
		Employee::awardBonus(bonus * 2);
}
void Manager::print() {
	Employee::print();
	cout << "\t managing " << deptName << " with budget " << budget << endl;
}
