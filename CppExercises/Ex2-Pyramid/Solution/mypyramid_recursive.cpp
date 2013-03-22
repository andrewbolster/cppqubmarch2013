#include <iostream>

using namespace std;

void pyramid_line(int n,int h = -1);

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
	pyramid_line(height);
}

void pyramid_line(int n, int h){
	if (h<0) h=n;
	if (n>1) pyramid_line(n-1, h);
	cout << std::string(h-n,' ')+std::string((2*n)-1, '#') << endl;
}
