#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

#include "ShowContents.h"

using namespace std;

int main() {
	list<string> listOne;
	listOne.push_back("abc");
	listOne.push_back("def");
	listOne.push_back("ghi");

	list<string> listTwo;
	listTwo.push_back("zzz");
	listTwo.push_back("yyy");
	listTwo.push_back("xxx");
	
	swap_ranges(listOne.begin(),listOne.end(),listTwo.begin());

	showContents(listOne,cout);
}