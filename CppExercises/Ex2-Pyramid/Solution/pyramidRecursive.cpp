#include <iostream>

using namespace std;

void drawPyramid(int spaces, int hashes);

int main() {
	cout << "Enter the size of the pyramid..." << endl;
	int height;
	cin >> height;
	cout << "Here is a pyramid of size " << height << endl;

	drawPyramid(height - 1,1);
}

void drawPyramid(int spaces, int hashes) {
	if(spaces > 0) {
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
		drawPyramid(spaces -1, hashes + 2);
	}
}