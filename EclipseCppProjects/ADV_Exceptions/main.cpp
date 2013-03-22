#include<iostream>
#include<string>
using namespace std;

class Test {
private:
	const string name;
public:
	Test(string s);
	~Test();
};
Test::Test(string s) : name(s) {
    cout << "----> Constructor of " << name << endl;
}
Test::~Test() {
    cout << "----> Destructor of " << name << endl;
}

void op1();
void op2();
void op3();
void op4();

int main() {
    cout << "Start of main" << endl;
    try {
        op1();
    } catch(const char * msg) {
        cout << "----> Just caught " << msg << endl;
    }
    cout << "End of main" << endl;
    return 0;
}
void op1() {
    cout << "\tStart of op1" << endl;
    Test t("T1");
    op2();
    cout << "\tEnd of op1" << endl;
}
void op2() {
    cout << "\t\tStart of op2" << endl;
    Test t("T2");
    op3();
    cout << "\t\tEnd of op2" << endl;
}
void op3() {
    cout << "\t\t\tStart of op3" << endl;
    Test t("T3");
    op4();
    cout << "\t\t\tEnd of op3" << endl;
}
void op4() {
    cout << "\t\t\t\tStart of op4" << endl;
    Test t("T4");
    throw "EXCEPTION !!";
    cout << "\t\t\t\tEnd of op4" << endl;
}

