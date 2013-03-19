#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

class Generator {
	string token;
	string state;
public:
	Generator(char *str) : state(str), token(str) {}
	string operator()() {
		return state += token;
	}
};

int main() {
	vector<string> vec(12);

	Generator gen1("a");

	generate(vec.begin(),vec.end(),gen1);
	showContents(vec,cout);

	cout << endl << endl << "----------------" << endl << endl;

	Generator gen2("A");

	generate_n(vec.begin(),6,gen2);
	showContents(vec,cout);
}
