#include "range.h"

Range::Range(int i) : limit(i) {}

Range& Range::operator++(int) {
	limit++;
	return *this;
}
bool Range::operator<(Range r) {
	return limit < r.limit;
}

Range::operator int() {
	return limit;	
}