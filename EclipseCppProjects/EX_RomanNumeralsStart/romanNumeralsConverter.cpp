#include <iostream>

using namespace std;

struct RomanNumeral {
	int decimalValue;
	char * stringValue;
};

void setup(RomanNumeral * ptr);
void convert(int number, RomanNumeral * numeral);

int main() {
	RomanNumeral numerals[9];
	//setup(numerals);

	cout << "Enter the number" << endl;
	int number;
	cin >> number;

	//convert and print the number...
}
