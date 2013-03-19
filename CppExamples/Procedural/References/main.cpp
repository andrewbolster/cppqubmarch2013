#include<iostream>
using namespace std;

void op1(int i) {
	cout << "Address after passing by value is "<< &i << endl;
}

void op2(int& i) {
	cout << "Address after passing by reference is "<< &i << endl;
	i++;
	cout << "Incremented value to " << i << endl;
}

void op3(int *i) {
	cout << "Location of pointer is "<< &i << " location of value is "<< i << endl;
}

const char* str1 = "First test string";
const char* str2 = "Second test string";

//Swap the contents of two pointers using both 
// pointer to pointers and references to pointers
void swapStrings(const char** str_ptr_ptr, const char* &str_ptr_ref) {

	const char* temp = *str_ptr_ptr;

	*str_ptr_ptr = str_ptr_ref;
	str_ptr_ref = temp;
}
int main(){

	int test=7;

	cout << "Address of test is " << &test << endl;

	op1(test);

	op2(test);
	cout << "Value after calling op2 is " << test << endl;

	op3(&test);

	cout << endl;

	swapStrings(&str1, str2);

	cout << "str1 now points to: " << str1 <<endl;
	cout << "str2 now points to: " << str2 <<endl;

	return 0;
}