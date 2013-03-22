#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	istringstream input("abcdef 12 3.45 1");

	string sval;
	int ival;
	double dval;
	bool bval;

	input >> sval;
	input >> ival;
	input >> dval;
	input >> bval;

	if(bval) {
		cout << sval << endl;
		cout << "Total is: " << ival + dval << endl;
	} else {
		cout << "Cannot read from stream" << endl;
	}
}
