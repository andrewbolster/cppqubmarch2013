#include "number.h"
#include "range.h"
#include <iostream>

/*
	Show templates with multiple template parameters
*/

template <typename T, typename U> T addAll(T * data_ptr, U length) {
	T total = 0;
	for(U i=0;i<length;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

int main() {
	//Template instance for T = double, U = int
	double darray[10] = {1,2,3,4,5,6,7,8,9,10};
	double resultOne = addAll(darray,10);
	std::cout << "First total is: " << resultOne << std::endl;

	//Template instance for T = int, U = int
	int iarray[10] = {1,2,3,4,5,6,7,8,9,10};
	int resultTwo = addAll(iarray,10);
	std::cout << "Second total is: " << resultTwo << std::endl;

	Number numbers[] = {1,2,3,4,5,6,7,8,9,10};

	//Template instance for T = Number, U = int
	Number resultThree = addAll(numbers,10);
	std::cout << "Third total is: " << resultThree << std::endl;
	
	//Template instance for T = Number, U = Range
	Range arraySize(10);
	Number resultFour = addAll(numbers,arraySize);
	std::cout << "Fourth total is: " << resultFour << std::endl;
}