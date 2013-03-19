
#include<iostream>

using namespace std;

void printArrayUsingPointerArithmetic(int *);
void printArrayUsingBrackets(int *);

int main() {
	int iarray[] = {101,202,303,404,505};
	cout << "--- EX 1 ---" << endl;
	printArrayUsingPointerArithmetic(iarray);
	cout << "--- EX 2 ---" << endl;
	printArrayUsingBrackets(iarray);
}
void printArrayUsingPointerArithmetic(int * i_ptr1) {
	cout << *i_ptr1 << endl; //101
	i_ptr1++;
	cout << *i_ptr1 << endl; //202
	i_ptr1++;
	cout << *i_ptr1 << endl; //303
	i_ptr1++;
	cout << *i_ptr1 << endl; //404
	i_ptr1++;
	cout << *i_ptr1 << endl; //505
}
void printArrayUsingBrackets(int * i_ptr2) {
	cout << i_ptr2[0] << endl; //101
	cout << i_ptr2[1] << endl; //202
	cout << i_ptr2[2] << endl; //303
	cout << i_ptr2[3] << endl; //404
	cout << i_ptr2[4] << endl; //505
}