#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(const string &name, int age);
    void swap(Person &other);
    void print();
};

Person::Person(const string &name, int age) {
	this->name = name;
	this->age = age;
}

void Person::print() {
	cout << "Person called " << name
             << " of age " << age << endl;
}

void Person::swap(Person &other) {
    string name = this->name;
    int age = this->age;

    this->name = other.name;
    this->age = other.age;

    other.name = name;
    other.age = age;
}

int main() {
    Person dave("dave",27);
    Person marge("marge",50);

    dave.swap(marge);

    cout << "daves details are: ";
    dave.print();
    cout << "marges details are: ";
    marge.print();
}