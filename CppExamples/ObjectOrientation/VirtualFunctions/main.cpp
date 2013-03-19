#include<iostream>
#include<string>

using namespace std;

class Person {
public:
    virtual void downsize();
};

class Employee : public Person {
public:
    void downsize();
};

class Manager : public Employee {
public:
    void downsize();
};

void fireEverybody(Person ** staff, int noOfStaff);

int main() {
    Person person;
    Employee employee;
    Manager manager;

    //Apparent type is Person
    //Actual (Inherent) type varies
    Person * p1 = &person;
    Person * p2 = &employee;
    Person * p3 = &manager;

    p1->downsize();
    p2->downsize();
    p3->downsize();

    Person * staff[] = {p1,p2,p3};
    fireEverybody(staff,3);
}
void fireEverybody(Person ** staff, int noOfStaff) {
    cout << "----------------------" << endl;
    for(int i=0;i<noOfStaff;i++) {
        staff[i]->downsize();
    }
}
void Person::downsize() {
    cout << "Person fired!" << endl;
}
void Employee::downsize() {
    cout << "Employee fired!" << endl;
}
void Manager::downsize() {
    cout << "Manager fired!" << endl;
}
