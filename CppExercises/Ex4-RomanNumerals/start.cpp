#include <iostream>

using namespace std;

struct RomanNumeral {
	int decimalValue;
	const char * stringValue;
};

void setup(RomanNumeral * ptr);
void print_numerals(RomanNumeral * ptr);
void convert(int number, RomanNumeral * numeral);

int main() {
	RomanNumeral lookup[9];
	RomanNumeral numerals[9];
	setup(lookup);
	print_numerals(lookup);

	cout << "Enter the number" << endl;
	int number;
	cin >> number;

}

void setup(RomanNumeral * numerals){
	numerals->decimalValue = 100; 
	numerals->stringValue = "C";
	numerals++;

	numerals->decimalValue = 90; 
	numerals->stringValue = "XC";
	numerals++;

	numerals->decimalValue = 50; 
	numerals->stringValue = "L";
	numerals++;
	
	numerals->decimalValue = 40; 
	numerals->stringValue = "XL";
	numerals++;
	
	numerals->decimalValue = 10; 
	numerals->stringValue = "X";
	numerals++;

	numerals->decimalValue = 9; 
	numerals->stringValue = "IX";
	numerals++;
	
	numerals->decimalValue = 5; 
	numerals->stringValue = "V";
	numerals++;
	
	numerals->decimalValue = 4; 
	numerals->stringValue = "IV";
	numerals++;
	
	numerals->decimalValue = 1; 
	numerals->stringValue = "I";
}

void print_numerals(RomanNumeral * numerals){
	for (int i = 0; i < 9; numerals++, i++){
		cout << numerals -> decimalValue << numerals -> stringValue << endl;
	}
}
