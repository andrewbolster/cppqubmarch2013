#include<iostream>
using namespace std;

class Base{
private:
    int i;
protected:
    Base(int x) : i(x){}
public:
    Base():i(0){}
    int foo() { return i; }
    void bar() { cout << "Base::bar() called" <<endl; }
};


//public inheritance from base
class PublicDerived : public Base {
public:
    PublicDerived(int x) : Base(x){}
};


//protected inheritance from base
class ProtectedDerived : protected Base {
public:
    ProtectedDerived(int x) : Base(x){}

    Base* convert(ProtectedDerived* p){
        return p;
    }
    int callFoo() {
        return foo();
    }
};

//private inheritance from base
class PrivateDerived : private Base {
public:
    PrivateDerived() : Base() {}
    //exempt bar() from the effects
    // of private inheritance
    using Base::bar;
};

//public inheritance from PrivateDerived
class Leaf : public PrivateDerived {
    //wont work, foo is private in superclass
    int callFoo() {
        //return foo();
        return 0;
    }
};

int main() {

    //fine, a PublicDerived is-a base
    Base *bptr = new PublicDerived(8);
    cout << bptr->foo() << endl;

    //no good, only ProtectedDerived and its subclasses
    // can know that it inherits from base
    //Base *bptr2 = new ProtectedDerived(8);

    //no good, only PrivateDerived knows it inherits from base
    //Base *bptr3 = new PrivateDerived();

    ProtectedDerived *ptr = new ProtectedDerived(12);

    //wont work, foo is now protected
    //ptr->foo();

    //will work, ProtectedDerived can call Base::foo for us
    cout << ptr->callFoo() << endl;

    //fine, ProtectedDerived is allowed to convert to Base*
    Base *bptr4 = ptr->convert(ptr);
    cout << bptr4->foo() << endl;

    PrivateDerived *ptr2 = new PrivateDerived;
    //wont work, foo is now private
    //ptr->foo();
    //fine, because we have exempted bar
    ptr2->bar();

    delete bptr;
    delete bptr4;

    return 0;
};