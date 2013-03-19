#include<iostream>
#include<string>

using namespace std;

class MyClass {
public:
    MyClass(int p1,int p2) {
        field1 = p1;
        field2 = p2;
    }
    MyClass(int p1) {
        field1 = p1;
        field2 = p1 + 1;
    }
    void print() {
        cout << "Values are: " << field1 << " and " << field2 << endl;
    }
private:
    int field1;
    int field2;
};

void doPrint(MyClass param) {
    param.print();
}

int main() {
    MyClass mc1(7,6);
    doPrint(mc1);

    doPrint(167);
}