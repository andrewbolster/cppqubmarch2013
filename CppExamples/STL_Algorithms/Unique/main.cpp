#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int main() {
	vector<string> vec;
	vec.push_back("ab");
	vec.push_back("ab");
	vec.push_back("cd");
	vec.push_back("cd");
	vec.push_back("ef");
	vec.push_back("ef");
	vec.push_back("gh");
	vec.push_back("gh");
	vec.push_back("ij");
	vec.push_back("ij");

	vector<string>::iterator new_end_iter;

	new_end_iter = unique(vec.begin(),vec.end());

	showContents< vector<string> >(vec.begin(),new_end_iter,cout);
	cout << endl << endl << "------------" << endl << endl;
	showContents(vec,cout);
}