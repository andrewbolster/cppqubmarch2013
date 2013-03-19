#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee {
public:
	Employee(const char * name);
	Employee(const char * name, int age, double salary);
	~Employee();
	void awardBonus(double bonus);
	void print();
private:
	string name;
	int age;
	double salary;
};


#endif //EMPLOYEE_H