#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

void loadTestData(vector<string>& vec);

int main() {
	vector<string> vecOne;
	loadTestData(vecOne);

	sort(vecOne.begin(),vecOne.end());
	showContents(vecOne,cout);
	cout << endl << "--------" << endl;

	vector<string> vecTwo;
	loadTestData(vecTwo);

	vector<string>::iterator middle = vecTwo.begin() + 5;
	partial_sort(vecTwo.begin(),middle,vecTwo.end());
	showContents(vecTwo,cout);
}

void loadTestData(vector<string>& vec) {
	vec.push_back("aa");
	vec.push_back("zz");
	vec.push_back("bb");
	vec.push_back("yy");
	vec.push_back("cc");
	vec.push_back("xx");
	vec.push_back("dd");
	vec.push_back("ww");
	vec.push_back("ee");
	vec.push_back("vv");
	vec.push_back("ff");
	vec.push_back("uu");
	vec.push_back("gg");
	vec.push_back("tt");
	vec.push_back("hh");
	vec.push_back("ss");
	vec.push_back("ii");
	vec.push_back("rr");
	vec.push_back("jj");
	vec.push_back("qq");
	vec.push_back("kk");
	vec.push_back("pp");
	vec.push_back("ll");
	vec.push_back("oo");
	vec.push_back("mm");
	vec.push_back("nn");
}