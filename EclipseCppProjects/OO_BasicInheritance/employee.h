#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee {
public:
	Employee(const char * name);
	Employee(const char * name, int age, double salary);
	virtual void awardBonus(double bonus);
	virtual void print();
private:
	string name;
	int age;
	double salary;
};

class Manager : public Employee {
public:
	Manager(const char * name, int age,
			double salary, const char * deptName,
			double budget);
	void raiseBudget(double increment);
	void awardBonus(double bonus);
	void print();
private:
	string deptName;
	double budget;
};


#endif //EMPLOYEE_H
