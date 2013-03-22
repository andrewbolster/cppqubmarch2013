#include <iostream>
#include "maths.h"

using namespace std;
using math::circumference;

int main() {
	cout << "Addition gives " << math::add(12,14) << endl;
	cout << "Subtraction gives " << math::subtract(30,18) << endl;
	cout << "Circumference is " << circumference(10) << endl;
}