#include <iostream>

using namespace std;

class Base {
public:
   void op(int i) {
        cout << "Base::op called" << endl;
    }
};
class Derived : public Base {
public:
    void op(int i) {
        cout << "Derived::op called" << endl;
    }
};

int main() {
    Derived d;

    Base * bptr = &d;
    Derived * dptr = &d;

    Base & bref = d;
    Derived & dref = d;

    bptr->op(12);
    bref.op(12);

    dptr->op(12);
    dref.op(12);

    return 0;
}

