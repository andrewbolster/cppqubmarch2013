#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int main() {
	vector<string> vec;
	vec.push_back("abc");
	vec.push_back("def");
	vec.push_back("ghi");
	vec.push_back("jkl");

	list<int> lst;
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	cout << "Vector contents are: " << endl;
	showContents(vec,cout);

	cout << endl << "List contents are: " << endl;
	showContents(lst,cout);
}
