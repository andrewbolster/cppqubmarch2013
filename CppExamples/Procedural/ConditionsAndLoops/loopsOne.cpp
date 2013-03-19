#include<iostream>

using namespace std;

int main() {
	cout << "Enter a number..." << endl;
	
	int number;
	cin >> number;

	int countOne = 0;
	while(countOne < number) {
		cout << "While loop message: " << countOne++ << endl;
	}
	cout << "--------------------" << endl;
		
	int countTwo = 0;
	do {
		cout << "Do While loop message: " << countTwo++ << endl;
	} while(countTwo < number);
	cout << "--------------------" << endl;
	
	int countThree = 0;
	while(1) {
		if(countThree == number) {
			break;
		} else {
			cout << "Infinite While loop message: " << countThree << endl;
		}
		countThree++;
	}
}
