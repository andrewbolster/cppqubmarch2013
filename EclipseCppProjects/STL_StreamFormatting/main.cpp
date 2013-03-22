#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	const char * str1 = "ABCD";
	const char * str2 = "ABCDEFGH";
	const char * str3 = "ABCDEFGHIJKL";
	const char * str4 = "ABCDEFGHIJKLMNOP";
	const char * str5 = "ABCDEFGHIJKLMNOPQRST";
	const char * str6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << endl << "Formatting Strings" << endl << endl;

	cout << setw(26) << right << str1 << endl;
	cout << setw(26) << right << str2 << endl;
	cout << setw(26) << right << str3 << endl;
	cout << setw(26) << right << str4 << endl;
	cout << setw(26) << right << str5 << endl;
	cout << setw(26) << right << str6 << endl;

	double d1 = 1.2;
	double d2 = 1.23;
	double d3 = 1.234;
	double d4 = 1.2345;
	double d5 = 1.23456;

	cout << endl << "Formatting Numbers" << endl << endl;

	cout << setprecision(5) << fixed << d1 << endl;
	cout << setprecision(5) << fixed << d2 << endl;
	cout << setprecision(5) << fixed << d3 << endl;
	cout << setprecision(5) << fixed << d4 << endl;
	cout << setprecision(5) << fixed << d5 << endl;

}
