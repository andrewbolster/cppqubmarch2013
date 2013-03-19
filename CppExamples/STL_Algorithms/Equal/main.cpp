#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

void showEqualAlgotithm(vector<string> p1,vector<string> p2);

int main() {
	vector<string> vecOne;
	vecOne.push_back("abc");
	vecOne.push_back("def");
	vecOne.push_back("ghi");
	vecOne.push_back("jkl");
	vecOne.push_back("mno");

	vector<string> vecTwo;
	vecTwo.push_back("abc");
	vecTwo.push_back("def");
	vecTwo.push_back("ghi");
	vecTwo.push_back("jkl");
	vecTwo.push_back("mno");

	vector<string> vecThree;
	vecThree.push_back("abc");
	vecThree.push_back("def");
	vecThree.push_back("ghi");
	vecThree.push_back("zzz");
	vecThree.push_back("jkl");
	vecThree.push_back("mno");

	showEqualAlgotithm(vecOne,vecTwo);
	showEqualAlgotithm(vecOne,vecThree);
}
void showEqualAlgotithm(vector<string> p1,vector<string> p2) {

	bool result = equal(p1.begin(),p1.end(),p2.begin());

	if(result) {
		cout << "Containers match" << endl;
	} else {
		cout << "Containers do not match " << endl;
	}
}