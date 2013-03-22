#include<iostream>
#include<string>

using namespace std;

class MyClass {
public:
    MyClass(int p1,double p2) {
        field1 = p1;
        field2 = p2;
    }
    MyClass(const MyClass & other) {
        cout << "MyClass copy constructor" << endl;
        field1 = other.field1;
        field2 = other.field2;
    }
    MyClass & operator=(const MyClass & rhs) {
        cout << "MyClass assignment operator" << endl;
        field1 = rhs.field1;
        field2 = rhs.field2;
        return *this;
    }
    void print() {
        cout << "Values are: " << field1 << " " << field2 << endl;
    }
private:
    int field1;
    double field2;
};

//COPY CONSTRUCTOR CALLED
void doPrint(MyClass param) {
    param.print();
}

int main() {
    MyClass mc1(7,3.4);
    mc1.print();

    //In C++ you can say 'int i = 7;' or 'int i(7);'
    MyClass mc2 = mc1;	//COPY CONSTRUCTOR
    MyClass mc3(mc1);	//COPY CONSTRUCTOR

    MyClass mc4(45,67.8);

    //Equivalent to mc2.operator=(mc4)
    mc2 = mc4;          //ASSIGNMENT OPERATOR
    mc2.print();

    //Equivalent to mc4.operator=(mc3.operator=(mc1));
    mc4 = mc3 = mc1;
    mc4.print();
}
