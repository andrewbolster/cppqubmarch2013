#include <iostream>

using namespace std;

class Tester {
    int value;
public:
    explicit Tester(int i) {
        value = i;
    }
};

void func(Tester t) {}

int main() {
    //OK - direct initialization
    Tester t1(7); 
    //OK - explicit cast
    Tester t2 = (Tester)8;

    //INVALID - implicit cast
    //Tester t3 = 9;
    //INVALID - implicit cast
    //func(10);
}