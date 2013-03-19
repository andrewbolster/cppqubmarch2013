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
	vec.push_back("kl");

	for(unsigned int i=0;i< vec.size(); i++) {
		vector<string>::iterator begin = vec.begin();
		vector<string>::iterator middle = begin + 1;
		rotate(begin,middle,vec.end());
		showContents(vec,cout);
		cout << endl << "---------" << endl;
	}
}