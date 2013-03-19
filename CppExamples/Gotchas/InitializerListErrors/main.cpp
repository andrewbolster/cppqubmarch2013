#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Person {
private:
    const int ageNextYear;
    const int ageNow;
public:
    Person(int age);
    void print();
};

Person::Person(int age) : ageNow(age), ageNextYear(ageNow + 1) {}

void Person::print() {
    cout << "Person aged " << ageNow << " now and "
         << ageNextYear << " next year " << endl;
}

int main() {
    Person dave(29);
    dave.print();
    return 0;
}