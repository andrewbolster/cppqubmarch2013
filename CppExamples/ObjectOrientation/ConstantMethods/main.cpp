#include<iostream>
#include<string>

using namespace std;

class MyClass {
public:
    MyClass(int p) : i(p) {}
    int get() const {
        cout << "const version of get" << endl;
        return i;
    }
    int get() {
        cout << "non const version of get" << endl;
        return i;
    }
private:
    int i;
};

void printOne(const MyClass & param) {
    cout << param.get() << endl;
}
void printTwo(MyClass & param) {
    cout << param.get() << endl;
}
void printThree(const MyClass * param) {
    cout << param->get() << endl;
}
void printFour(MyClass * param) {
    cout << param->get() << endl;
}

int main() {
    MyClass mc(30);
    printOne(mc);
    printTwo(mc);
    printThree(&mc);
    printFour(&mc);
}