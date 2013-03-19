#include<iostream>

using namespace std;

typedef void (*FUNC_INT_PTR)(int);

void funcOne(int i) {
    cout<< "funcOne called with " << i << endl;
}
void funcTwo(int i) {
    cout<< "funcTwo called with " << i << endl;
}
void funcThree(int i) {
    cout<< "funcThree called with " << i << endl;
}
void doCallback(FUNC_INT_PTR callback, int param) {
	callback(param);
}

int main() {
	FUNC_INT_PTR ptr1 = funcOne;
	FUNC_INT_PTR ptr2 = funcTwo;
	FUNC_INT_PTR ptr3 = funcThree;

	doCallback(ptr1,10);
	doCallback(ptr2,20);
	doCallback(ptr3,30);
}