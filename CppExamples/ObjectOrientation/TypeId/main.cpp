#include <iostream>
#include <typeinfo>

using namespace std;

/*
    This will only work in Visual C++ if you
    compile with /GR to turn on RTTI

    Project->Properties->Configuration Properties->Language->Enable RTTI
*/


class Base {
    virtual void func() {}
};
class Derived : public Base {
    void func() {}
};

void testPtr(Base * ptr);

int main() {

    cout << "integer name is: " << typeid(int).name() << endl << endl;
    cout << "char pointer name is: " << typeid(char *).name() << endl << endl;
    cout << "double reference name is: " << typeid(double &).name() << endl << endl;

    Base * b_ptr = new Derived;
    cout << "Base name is: " << typeid(Base).name() << endl << endl;
    cout << "Base pointer is: " << typeid(b_ptr).name() << endl << endl;
    cout << "Base pointer target is: " << typeid(*b_ptr).name() << endl << endl;

    Base * ptr1 = 0;
    testPtr(ptr1);
    Base * ptr2 = new Base;
    testPtr(ptr2);
    Base * ptr3 = new Derived;
    testPtr(ptr3);
}
void testPtr(Base * ptr) {
    try {
        if(typeid(*ptr) == typeid(Base)) {
            cout << "ptr points to an instance of Base" << endl << endl;
        } else if(typeid(*ptr) == typeid(Derived)) {
            cout << "ptr points to an instance of Derived" << endl << endl;
        } else {
            cout << "dont have a clue what ptr points to" << endl << endl;
        }
    } catch(bad_typeid& ex) {
        cout << "CAUGHT: " << ex.what() << endl << endl;
    }
}