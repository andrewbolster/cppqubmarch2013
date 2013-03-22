#include<iostream>

using namespace std;

void funcOne(int i) {
   cout<< "funcOne called with " << i << endl;
}
int funcTwo(int i, double d) {
    cout<< "funcTwo called with " << i << " and " << d << endl;
	return 7;
}
double funcThree(char * str) {
    cout<< "funcThree called with " << str << endl;
	return 7.89;
}
int main() {
	void (* ptr1)(int) = funcOne;
	int (* ptr2)(int, double) = funcTwo;
	double (* ptr3)(char *) = funcThree;

	ptr1(10);
	ptr2(11, 12.34);
	ptr3("ABCD");
}
