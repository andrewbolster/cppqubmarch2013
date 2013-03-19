#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

bool greaterThanFifty(int& value) {
	return value > 50;
}

int main() {
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(90);
	vec.push_back(20);
	vec.push_back(80);
	vec.push_back(70);
	vec.push_back(60);
	vec.push_back(50);
	vec.push_back(40);

	vector<int>::iterator partition_iter;

	partition_iter = partition(vec.begin(),vec.end(),greaterThanFifty);

	showContents<vector<int> >(vec.begin(),partition_iter,cout);
	cout << endl << "--------" << endl;
	showContents<vector<int> >(partition_iter,vec.end(),cout);	
}