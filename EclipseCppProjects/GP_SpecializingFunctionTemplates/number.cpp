#include "number.h"
#include <iostream>

using namespace std;

Number operator+(const Number& lhs, const Number& rhs) {
	int total = lhs.value + rhs.value;
	Number tmp(total);
	return tmp;
}

ostream& operator<<(ostream& output, const Number& rhs) {
	rhs.print(output);
	return output;
}

Number::Number(int num) {
	value = num;
}

void Number::print(ostream& output) const {
	output << value;
}
