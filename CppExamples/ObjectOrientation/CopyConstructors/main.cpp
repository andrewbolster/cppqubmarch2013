#include<iostream>
#include<string>

using namespace std;

class MyClass {
public:
    MyClass(int p1,double p2) {
        field1 = p1;
        field2 = p2;
    }
    MyClass(const MyClass & other){
        cout << "MyClass copy constructor" << endl;
        field1 = other.field1;
        field2 = other.field2;
    }
    void print() {
        cout << "Values are: " << field1 << " " << field2 << endl;
    }
private:
    int field1;
    double field2;
};

void doPrint(MyClass param) {
    param.print();
}

int main() {
    MyClass mc1(7,3.4);
    mc1.print();

    MyClass mc2 = mc1;
    MyClass mc3(mc1);

    mc2.print();
    mc3.print();

    doPrint(mc1);
    doPrint(mc2);
    doPrint(mc3);
    
    return 0;
}