#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "showContents.h"

using namespace std;

bool lessThanThirty(int value) {
	return value < 30;
}

int main() {
	vector<int> input;
	input.push_back(10);
	input.push_back(50);
	input.push_back(20);
	input.push_back(30);
	input.push_back(40);
	input.push_back(50);

	replace(input.begin(),input.end(),50,180);
	replace_if(input.begin(),input.end(),lessThanThirty,200);

	showContents(input,cout);
}
