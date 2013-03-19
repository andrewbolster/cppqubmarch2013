#include "number.h"
#include <iostream>

/*
	Implement addAll as a simple template
*/

template <typename T> T addAll(T * data_ptr, int length) {
	T total = 0;
	for(int i=0;i<length;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

int main() {
	//Template instance for double
	double darray[10] = {1,2,3,4,5,6,7,8,9,10};
	double resultOne = addAll(darray,10);
	std::cout << "First total is: " << resultOne << std::endl;

	//Template instance for integer
	int iarray[10] = {1,2,3,4,5,6,7,8,9,10};
	int resultTwo = addAll(iarray,10);
	std::cout << "Second total is: " << resultTwo << std::endl;

	//Template instance for Number
	Number numbers[] = {1,2,3,4,5,6,7,8,9,10};
	Number resultThree = addAll(numbers,10);
	std::cout << "Third total is: " << resultThree << std::endl;

	//Explicitly specify the type of T (not required)
	short sarray[10] = {1,2,3,4,5,6,7,8,9,10};
	short resultFour = addAll<short>(sarray,10);
	std::cout << "Fourth total is: " << resultFour << std::endl;

}