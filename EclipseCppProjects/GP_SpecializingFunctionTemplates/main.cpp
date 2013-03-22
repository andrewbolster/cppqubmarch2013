#include "number.h"
#include <iostream>
#include <list>

using namespace std;

/*
	Show full template specialization and template template parameters
*/

template <typename T, typename U> T addAll(T * data_ptr, U length) {
	T total = 0;
	for(U i=0;i<length;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

//Define a specialization for Numbers and integers
template <> Number addAll(Number * data_ptr, int length) {
	cout << "Specialization for number used" << endl;
	Number total = 0;
	for(int i=0;i<length;i++) {
		total = total + data_ptr[i];
	}
	return total;
}

//Define a specialization for lists - note that typename is required for second parameter
// because the compiler needs to be explicitly told that iterator is a dependant type
template <typename T> T addAll(list<T> * data, typename list<T>::iterator end) {
	cout << "Specialization for list used" << endl;
	T total = 0;
	typename list<T>::iterator iter;
	for(iter = data->begin(); iter!= end; iter++) {
		total = total + *iter;
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

	//Template specialization for Number
	Number numbers[] = {1,2,3,4,5,6,7,8,9,10};
	Number resultThree = addAll(numbers,10);
	std::cout << "Third total is: " << resultThree << std::endl;

	//Template specialization for list<T>
	list<int> intList;
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);
	intList.push_back(4);
	intList.push_back(5);
	intList.push_back(6);
	intList.push_back(7);
	intList.push_back(8);
	intList.push_back(9);
	intList.push_back(10);
	int resultFour = addAll(&intList,intList.end());
	std::cout << "Fourth total is: " << resultFour << std::endl;

}
