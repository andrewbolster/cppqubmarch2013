#include <iostream>

using namespace std;

class Base {
public:
   void op(int i) {
        cout << "Base::op<int>" << endl;
    }
    void op(float f) {
        cout << "Base::op<float>" << endl;
    }
};
class Derived : public Base {
public:
    //this declaration hides the methods called
    // op declared in class Base, it does NOT
    // overload the method unless you include
	// using Base::op;
    void op(double d) {
        cout << "Derived::op<double>" << endl;
    }
};

int main() {
    Derived d;
    d.op(5);

    return 0;
}

