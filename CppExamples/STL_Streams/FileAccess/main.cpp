#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

	ifstream infile("in.txt");
	ofstream outfile("out.txt");

	char buffer[256];
	int lineCount = 0;

	while(!infile.eof()) {
		infile.getline(buffer,256);
		outfile << "Line " << ++lineCount << ": " << buffer << endl;
	}
	cout << "All done..." << endl;
}