#include<iostream>

using namespace std;

int main() {
	int myarray[] = {1,2,3,4,5,6,7,8,9,10,11};
	int size = 12;

	cout << "----- Loop One -----" << endl;
	for(int i=0;i<size;i++) {
		cout << "\t" << myarray[i] << endl;
		i += 1;
	}
	cout << "----- Loop Two -----" << endl;
	for(int i=0;i<size;i+=2) {
		cout << "\t" << myarray[i] << endl;
	}
}
