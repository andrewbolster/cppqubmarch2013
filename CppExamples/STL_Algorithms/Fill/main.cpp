#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int main() {
	vector<string> vec(12);

	fill(vec.begin(),vec.end(),"aaa");
	showContents(vec,cout);

	cout << endl << endl << "----------------" << endl << endl;

	fill_n(vec.begin(),6,"zzz");
	showContents(vec,cout);
}
