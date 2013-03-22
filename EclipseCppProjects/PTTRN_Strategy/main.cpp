#include <iostream>
#include <string>

using namespace std;

class Employee;

class PrintStrategy {
public:
	virtual void print(const Employee& employee, ostream& stream) = 0;
};

class VerbosePrintStrategy : public PrintStrategy {
public:
	void print(const Employee& employee, ostream& stream);
};

class XMLPrintStrategy : public PrintStrategy {
public:
	void print(const Employee& employee, ostream& stream);
};

class CommaSeparatedPrintStrategy : public PrintStrategy {
public:
	void print(const Employee& employee, ostream& stream);
};

class Employee {
	friend class VerbosePrintStrategy;
	friend class XMLPrintStrategy;
	friend class CommaSeparatedPrintStrategy;
public:
	Employee(string name, string address, double salary, PrintStrategy& strategy);
	void print();
private:
	string name;
	string address;
	double salary;
	PrintStrategy& printStrategy;

};

Employee::Employee(string name,
				   string address,
				   double salary,
				   PrintStrategy& strategy) : printStrategy(strategy) {

	this->name = name;
	this->address = address;
	this->salary = salary;
}

void Employee::print() {
	printStrategy.print(*this, cout);
}

void VerbosePrintStrategy::print(const Employee& employee, ostream& stream) {
	stream << "Employee with name " << employee.name
		   << " at address " << employee.address
		   << " with salary " << employee.salary
		   << endl << endl;
}

void XMLPrintStrategy::print(const Employee& employee, ostream& stream) {
	stream << "<employee>\n\t<name>" << employee.name << "</name>" << endl
		   << "\t<address>" << employee.address << "</address>" << endl
		   << "\t<salary>" << employee.salary << "</salary>" << endl
		   <<  "</employee>" << endl << endl;
}

void CommaSeparatedPrintStrategy::print(const Employee& employee, ostream& stream) {
	stream << employee.name << " , " << employee.address << " , " << employee.salary << endl;
}

int main() {

	VerbosePrintStrategy vps;
	XMLPrintStrategy xps;
	CommaSeparatedPrintStrategy csps;

	Employee joe1("Joe Bloggs","10 Arcatia Road",40000,vps);
	Employee joe2("Joe Bloggs","10 Arcatia Road",40000,xps);
	Employee joe3("Joe Bloggs","10 Arcatia Road",40000,csps);

	joe1.print();
	joe2.print();
	joe3.print();
}

