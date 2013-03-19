#include <iostream>

//prototypes for exact matches
void func(int i);
void func(int* i_ptr);
void func(void (*f_ptr)(int));
void func(const float *f_ptr);
void func(double &d);

//prototypes for other types of match
void func2(int i);
void func2(double d);
void func3(double d);
void func3(void *v_ptr);
void func4(long l);
void func5(int * i_ptr);
void func5(float *f_ptr);

//a class whose instances can be converted to longs
class MyClass {
public:
	operator long() {
		return 23;
	}
};

int main() {
	//EXACT MATCHES

	int i=9;
	int iarray[10];
	float *f_ptr = 0;
	double d = 2.34;

	//exact match - lvalue
	func(i);

	//exact match - rvalue
	func(10);

	//exact match - array to pointer conversion
	func(iarray);

	//eaxct match - function to pointer conversion
	func(func);

	//exact match - qualification conversion
	func(f_ptr);

	//exact match - argument is a valid initializer
	func(d);


	//PROMOTIONS

	short s = 2;
	float f = 2.3f;

	//promotion - short to int
	func2(s);

	//promotion - float to double
	func2(f);


	//STANDARD CONVERSIONS

	//conversion - integer to double
	func3(i);

	//conversion - float pointer to void pointer
	func3(f_ptr);


	//USER DEFINED CONVERSIONS
	MyClass mc;
	func4(mc);

	//ERRORS

	//ambiguous - float pointer or int pointer?
	//func5(0);

	//error - no matching function
	//func5();

	return 0;
}
void func(int i) {
	std::cout << "func taking an integer of value: " << i << std::endl;
}

void func(int* i_ptr) {
	std::cout << "func taking a pointer to integer argument" << std::endl;
}

void func(void (*f_ptr)(int)) {
	std::cout << "func taking a function pointer argument" << std::endl;
	f_ptr(4);
}

void func(const float *f_ptr) {
	std::cout << "func taking a pointer to constant float argument" << std::endl;
}

void func(double &d) {
	std::cout << "func taking a reference to a double" << std::endl;
}

void func2(int i) {
	std::cout << "func2 taking an integer of value: " << i << std::endl;
}

void func2(double d) {
	std::cout << "func2 taking an double of value: " << d << std::endl;
}

void func3(double d) {
	std::cout << "func3 taking an double of value: " << d << std::endl;
}

void func3(void *v_ptr) {
	std::cout << "func3 taking a void pointer" << std::endl;
}
void func4(long l) {
	std::cout << "func4 taking a long of value: " << l << std::endl;
}

void func5(int * i_ptr) {
	std::cout << "func5 taking an int pointer" << std::endl;
}

void func5(float *f_ptr) {
	std::cout << "func5 taking a float pointer" << std::endl;
}




