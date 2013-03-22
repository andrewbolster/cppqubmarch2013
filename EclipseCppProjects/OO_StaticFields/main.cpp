#include<iostream>
#include<vector>

using namespace std;

class Test {
private:
    static int createdCounter;
    static int existingCounter;
public:
    static int numCreated();
    static int numObjects();
    Test();
    Test(const Test& rhs);
    ~Test();
};

int Test::createdCounter = 0;
int Test::existingCounter = 0;

int Test::numObjects() {
    return existingCounter;
}
int Test::numCreated() {
    return createdCounter;
}

Test::~Test() {
	existingCounter--;
}

Test::Test() {
    createdCounter++;
    existingCounter++;
}
Test::Test(const Test& rhs) {
    createdCounter++;
    existingCounter++;
}

int main() {
    vector<Test> v;
	//v.reserve(100);
    for(int i=0; i< 100; i++) {
        Test t;
        v.push_back(t);
    }
    cout << "Number of objects created is: " << Test::numCreated() << endl;
    cout << "Number of current objects is: " << Test::numObjects() << endl;
}
