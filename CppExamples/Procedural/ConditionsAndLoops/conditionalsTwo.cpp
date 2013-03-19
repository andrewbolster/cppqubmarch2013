#include<iostream>

using namespace std;

int main() {
	cout << "Enter a number (preferably 10,20,30,40 or 50)" << endl;
	
	int number;
	cin >> number;

	switch(number) {
	case 10:
		cout << "Number is 10" << endl;
		break;
	case 20:
		cout << "Number is 20" << endl;
		break;
	case 30:
	case 40:
	case 50:
		cout << "Number is 30, 40 or 50" << endl;
		break;
	default:
		cout << "Unknown number " << number << endl;
	}
}
