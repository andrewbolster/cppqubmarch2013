#include <iostream>
#include <sstream>

using namespace std;

int main() {
	ostringstream output;
	output << "Values are: ";
	output << 12;
	output << " ";
	output << 34.56;
	output << " ";
	output << false;
	output << endl;

	string message = output.str();
	cout << message;
}
