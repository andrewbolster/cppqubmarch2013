#include<iostream>

using namespace std;

int main() {
	cout << "Enter a number..." << endl;
	
	int number;
	cin >> number;

	if(number < 10) {
		cout << "Number is less than ten" << endl;
	} else if(number < 20) {
		cout << "Number is less than twenty" << endl;
	} else if(number < 30) {
		cout << "Number is less than thirty" << endl;
	}else {
		cout << "Number is thirty or greater" << endl;
	}
}
