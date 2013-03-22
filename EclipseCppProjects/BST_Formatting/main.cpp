#include <iostream>
#include <string>
#include <vector>
#include <boost/format.hpp>

using namespace std;
using namespace boost;

int main() {
	string data = "This library avoids the pain of coverting values like %3%, %2% and %1% into strings";

	int tst1 = 123;
	double tst2 = 4.56;
	double tst3 = -7.89;

	string result = str(format(data) % tst1 % tst2 % tst3 );

	cout << result << endl;

	string data2 = "\tThe number is: %|08.3f|";

	cout << "Examples of formatting numbers:" << endl;
	cout << format(data2) % 1.2 << endl;
	cout << format(data2) % 12.34 << endl;
	cout << format(data2) % 123.456 << endl;
	cout << format(data2) % 1234.5678 << endl;
}

