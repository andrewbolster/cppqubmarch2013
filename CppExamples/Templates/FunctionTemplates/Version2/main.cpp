#include "number.h"
#include <iostream>

/*
	Show nontype template parameters
*/

template <typename T, int SIZE> T addAll(T * data_ptr) {
	T total = 0;
	for(int i=0;i<SIZE;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

int main() {
	//Create three instances of the template
	double(* d_ptr)(double *) = addAll<double,10>;
	int(* i_ptr)(int *) = addAll<int,10>;
	Number(* n_ptr)(Number *) = addAll<Number,10>;

	double darray[10] = {1,2,3,4,5,6,7,8,9,10};
	double resultOne = d_ptr(darray);
	std::cout << "First total is: " << resultOne << std::endl;

	int iarray[10] = {1,2,3,4,5,6,7,8,9,10};
	int resultTwo = i_ptr(iarray);
	std::cout << "Second total is: " << resultTwo << std::endl;

	Number numbers[] = {1,2,3,4,5,6,7,8,9,10};
	Number resultThree = n_ptr(numbers);
	std::cout << "Third total is: " << resultThree << std::endl;
}