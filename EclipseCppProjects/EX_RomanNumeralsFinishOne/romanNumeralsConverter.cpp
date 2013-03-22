#include <iostream>

using namespace std;

struct RomanNumeral {
	int decimalValue;
	const char * stringValue;
};

void setup(RomanNumeral * ptr);
void convert(int number, RomanNumeral * numeral);

int main() {
	RomanNumeral numerals[9];
	setup(numerals);

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

void setup(RomanNumeral * ptr) {
	const char * stringValues[] = {"C","XC","L","XL","X","IX","V","IV","I"};
	int decimalValues[] = {100,90,50,40,10,9,5,4,1};

	for(int i=0;i<9;i++) {
		ptr->decimalValue = decimalValues[i];
		ptr->stringValue = stringValues[i];
		ptr++;
	}
}
