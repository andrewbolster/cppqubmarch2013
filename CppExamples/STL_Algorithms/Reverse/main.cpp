#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int main() {
	vector<string> vec;
	vec.push_back("ab");
	vec.push_back("cd");
	vec.push_back("ef");
	vec.push_back("gh");
	vec.push_back("ij");

	reverse(vec.begin(),vec.end());
	showContents(vec,cout);

	cout << endl << "---------" << endl;

	reverse(vec.begin(),vec.end());
	showContents(vec,cout);
}