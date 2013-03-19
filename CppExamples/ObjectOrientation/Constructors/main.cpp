#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

/* Class declaration - normally goes in header file */

class Employee {
//Public members can be used by anyone
public:
    //Constructors
    Employee();
    Employee(const string& name);
    Employee(const string& name, const string& address);
    Employee(const string& name, const string& address, double basicSalary);
    //Destructor
    ~Employee();
    //Methods
    void printDetails();
//Private members are hidden from everyone
private:
    //Fields
    string name;
    string address;
    double basicSalary;
};

/* Class definition - normally goes in cpp file */

Employee::Employee() {
    cout << "Default constructor" << endl;
    name = "NO_NAME";
    address = "NO_ADDRESS";
    basicSalary = 0;
}
Employee::Employee(const string& name) {
    cout << "Single parameter constructor" << endl;
    this->name = name;
    address = "NO_ADDRESS";
    basicSalary = 0;
}
Employee::Employee(const string& name, const string& address) {
    cout << "Two parameter constructor" << endl;
    this->name = name;
    this->address = address;
    basicSalary = 0;
}
Employee::Employee(const string& name, const string& address, double basicSalary) {
    cout << "Three parameter constructor" << endl;
    this->name = name;
    this->address = address;
    this->basicSalary = basicSalary;
}
Employee::~Employee() {
    cout << "Destructor of Employee " << name <<endl;
}
void Employee::printDetails() {
    cout << "Employee called: " << name << " at address " << address << " with salary " << basicSalary << endl << endl;
}

int main() {

    Employee e;
    e.printDetails();

    Employee e2("Joe Bloggs");
    e2.printDetails();

    Employee e3("Fred Flintstone","10 Arcatia Drive");
    e3.printDetails();

    Employee e4("Barney Rubble","10 Prospect Park",20000);
    e4.printDetails();
    
    return 0;
}