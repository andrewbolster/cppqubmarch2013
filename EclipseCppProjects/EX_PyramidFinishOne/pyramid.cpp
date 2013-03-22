#include <iostream>

using namespace std;

int main() {
	cout << "Enter the size of the pyramid..." << endl;
	int height;
	cin >> height;
	cout << "Here is a pyramid of size " << height << endl;

	int spaces = height - 1;
	int hashes = 1;

	//for each row in the pyramid
	while(spaces >= 0) {
		//print out the spaces
		for(int y=0;y<spaces;y++) {
			cout << " ";
		}
		//print out the hashes
		for(int y=0;y<hashes;y++) {
			cout << "#";
		}
		//take a new line
		cout << endl;
		//adjust the counters
		spaces--;
		hashes += 2;
	}
}