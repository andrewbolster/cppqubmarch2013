#include<iostream>

using namespace std;

int main() {
	cout << "Enter a number..." << endl;
	
	int number;
	cin >> number;

	for(int i=0;i<number;i++) {
		cout << "First for loop message: " << i  << endl; 
	}
	printf("--------------------\n");
		
	for(int i=number;i>0;i--) {
		cout << "Second for loop message: " << i  << endl;
	}
	printf("--------------------\n");	
	
	int count = 0;
	for(;;) {
		if(count == number) {
			break;
		} else {
			cout << "Third for loop message: " << count  << endl;
		}
		count++;
	}
}
