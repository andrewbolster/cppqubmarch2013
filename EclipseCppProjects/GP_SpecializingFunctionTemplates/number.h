#include <iostream>

using std::ostream;

class Number {
	friend Number operator+(const Number&, const Number&);
private:
	int value;
public:
	Number(int num);
	void print(ostream& output) const;
};
Number operator+(const Number& lhs, const Number& rhs);
ostream& operator<<(ostream& output, const Number& rhs);
