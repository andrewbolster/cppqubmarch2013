#include <string.h>
#include <iostream>

using namespace std;

struct Employee {
    int Age;
    float Salary;
    char Name[10];
    char Dept[10];
};

void useEmployee(Employee * e_ptr);
void printEmployee(Employee * e_ptr);

int main() {
    Employee e;
    useEmployee(&e);
    printEmployee(&e);
}
void useEmployee(Employee * e_ptr) {
    e_ptr->Age = 27;
    e_ptr->Salary = 30000;
    strcpy(e_ptr->Name, "Joe Smith");
    strcpy(e_ptr->Dept,"Marketing");
};

void printEmployee(Employee * e_ptr) {
    cout << "Employee called " << e_ptr->Name << " in dept " << e_ptr->Dept
         << " of age " << e_ptr->Age << " earning " << e_ptr->Salary << endl;
}
