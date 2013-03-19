#include <iostream>

using namespace std;

class Base {
public:
    virtual void func(int i=99) {
        cout << "Base::func called with value " << i << endl;
    }
};

class Derived : public Base {
public:
    //BAD - redefining default parameter value of virtual function
    void func(int i=100) {
        cout << "Derived::func called with value " << i << endl;
    }
};

int main() {
    Derived d;

    Derived * d_ptr = &d;
    Base * b_ptr = &d;

    d_ptr->func(); //prints Derived::func called with value 100
    b_ptr->func(); //prints Derived::func called with value 99
}