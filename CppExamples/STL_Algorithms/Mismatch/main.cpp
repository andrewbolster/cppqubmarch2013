#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

void showMismatchAlgotithm(vector<string> p1,vector<string> p2);

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

	showMismatchAlgotithm(vecOne,vecTwo);
	showMismatchAlgotithm(vecOne,vecThree);
}
void showMismatchAlgotithm(vector<string> p1,vector<string> p2) {

	typedef vector<string>::iterator strIterType;
	typedef pair<strIterType,strIterType> resultType;

	resultType result = mismatch(p1.begin(),p1.end(),p2.begin());

	if(result.first == p1.end()) {
		cout << "Containers match!" << endl;
	} else {
		cout << "Containers stop matching at position "
			<< result.first - p1.begin() << endl;
	}
}