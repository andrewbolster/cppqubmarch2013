#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int timesTwo(int value) {
	return value *= 2;
}

int main() {
	vector<int> input;
	input.push_back(10);
	input.push_back(20);
	input.push_back(30);
	input.push_back(40);
	input.push_back(50);

	transform(input.begin(),input.end(),input.begin(),timesTwo);
	
	showContents(input,cout);
}