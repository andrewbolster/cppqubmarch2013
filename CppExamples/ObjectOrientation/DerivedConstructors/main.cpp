#include<iostream>

using namespace std;

class Base {
public:
    Base();
    Base(int i);
    Base(float f);
    Base(int i, float f);
    ~Base();
private:
    int ival;
    float fval;
};

class Derived : public Base {
public:
    Derived();
    Derived(int i);
    Derived(float f);
    Derived(int i, float f);
    Derived(int i, float f, double d);
    ~Derived();
private:
    double dval;
};

//Base Constructors
Base::Base() : ival(0), fval(0) {
    cout << "Base::Base()" << endl;
}
Base::Base(int i) : ival(i), fval(0) {
    cout << "Base::Base(int)" << endl;
}
Base::Base(float f) : ival(0), fval(f) {
    cout << "Base::Base(float)" << endl;
}
Base::Base(int i, float f) : ival(i), fval(f) {
    cout << "Base::Base(int,float)" << endl;
}
Base::~Base() {
    cout << "Base::~Base()" << endl;
}

//Derived Constructors
Derived::Derived() : dval(0) {
    cout << "Derived::Derived()" << endl;
}
Derived::Derived(int i) : Base(i), dval(0) {
    cout << "Derived::Derived(int)" << endl;
}
Derived::Derived(float f) : Base(f), dval(0) {
    cout << "Derived::Derived(float)" << endl;
}
Derived::Derived(int i, float f) : Base(i,f), dval(0) {
    cout << "Derived::Derived(int,float)" << endl;
}
Derived::Derived(int i, float f, double d) : Base(i,f), dval(d) {
    cout << "Derived::Derived(int,float,double)" << endl;
}
Derived::~Derived() {
    cout << "Derived::~Derived()" << endl;
}

void msg(char* str) {
    cout << "\nCreating object " << str << endl;
}

int main() {

    msg("d1");
    Derived d1;
    msg("d2");
    Derived d2(7);
    msg("d3");
    Derived d3(3.4f);
    msg("d4");
    Derived d4(4,5.6f);
    msg("d5");
    Derived d5(5,6.7f,8.9);

    cout << endl;

    return 0;
}