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
	
	back_insert_iterator< list<string> > back_iter(listOne);
	front_insert_iterator< list<string> > front_iter(listOne);

	cout << endl << "BEFORE FIRST COPY" << endl << endl;
	showContents(listOne,cout);

	copy(listTwo.begin(),listTwo.end(),back_iter);
	cout << endl << "AFTER FIRST COPY" << endl << endl;
	showContents(listOne,cout);

	copy(listTwo.begin(),listTwo.end(),front_iter);
	cout << endl << "AFTER SECOND COPY" << endl << endl;
	showContents(listOne,cout);

}