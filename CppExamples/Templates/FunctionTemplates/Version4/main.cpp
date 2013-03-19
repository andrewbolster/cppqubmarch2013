#include "number.h"
#include "range.h"
#include <iostream>

/*
	Show partial template specialization
*/

template <typename T, typename U> T addAll(T * data_ptr, U length) {
	T total = 0;
	for(U i=0;i<length;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

//Define a partial specialization for Range objects
template <typename T> T addAll(T * data_ptr, Range& size) {
	std::cout << "Partial specialization for Range used" << std::endl;
	T total = 0;
	for(int i=0;i<size.getValue();i++) {
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

	//Tempate instance for Number and Range
	Number numbers[] = {1,2,3,4,5,6,7,8,9,10};
	Range arraySize(10);
	Number resultThree = addAll(numbers,arraySize);
	std::cout << "Third total is: " << resultThree << std::endl;
}