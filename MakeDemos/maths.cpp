#include "maths.h"

//function definitions
namespace math {
	int add(int no1, int no2) {
		return no1 + no2;
	}
	int subtract(int no1, int no2) {
		return no1 - no2;
	}
}
double math::circumference(double diameter) {
	return PI * diameter;
}
