#include <iostream>

using namespace std;

struct RomanNumeral {
	int decimalValue;
	char * stringValue;
} numerals[]  = { {100, "C"}, 
                  {90, "XC"}, 
				  {50, "L"}, 
				  {40, "XL"}, 
				  {10, "X"}, 
				  {9, "IX"}, 
				  {5, "V"}, 
				  {4, "IV"}, 
				  {1, "I"} } ;

void convert(int number, RomanNumeral * numeral);

int main() {
	cout << "Enter the number" << endl;
	int number;
	cin >> number;

	if(number <= 0) {
		cout << "Invalid number!" << endl;
	} else {
		convert(number,numerals);
	}
}

void convert(int number, RomanNumeral * numeral) {
	int times = number / numeral->decimalValue;
	int remainder = number % numeral->decimalValue;

	if(times > 0) {
		for(int i=0;i<times;i++) {
			cout << numeral->stringValue;
		}
	}

	if(remainder > 0) {
		convert(remainder,++numeral);
	} else {
		cout << endl;
	}
}