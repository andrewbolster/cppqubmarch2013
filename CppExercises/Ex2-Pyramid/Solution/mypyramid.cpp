#include <iostream>

using namespace std;

int main() {
	cout << "Enter the size of the pyramid..." << endl;
	int height;
	cin >> height;
	cout << "Here is a pyramid of size " << height << endl;
	
	/* 6
	 * _____#
	 * ____###
	 * ___#####
	 * __#######
	 * _#########
	 * ###########
	 * */

	for(int n=1; n<=height; n++)

}

void pyramid_line(int n){
	cout << std::string(height-n,' ')+std::string((2*n)-1, '#') << endl;
}
