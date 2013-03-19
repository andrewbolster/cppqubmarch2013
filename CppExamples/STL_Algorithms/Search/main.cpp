#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void showSearchAlgorithm();
void showSearchNAlgorithm();

int main() {
	showSearchAlgorithm();
	showSearchNAlgorithm();
}

void showSearchAlgorithm() {
	vector<string> vec;
	vec.push_back("ab");
	vec.push_back("cd");
	vec.push_back("ef");
	vec.push_back("gh");
	vec.push_back("ij");
	vec.push_back("kl");

	vector<string> target;
	target.push_back("ef");
	target.push_back("gh");
	target.push_back("ij");

	vector<string>::iterator result;
	result = search(vec.begin(),vec.end(),target.begin(),target.end());
	if(result == vec.end()) {
		cout << "Sequence cannot be found" << endl;
	} else {
		cout << "Sequence found at " << result - vec.begin() << endl; 
	}
}
void showSearchNAlgorithm() {
	vector<string> vec;
	vec.push_back("ab");
	vec.push_back("cd");
	vec.push_back("ef");
	vec.push_back("gh");
	vec.push_back("xx");
	vec.push_back("xx");
	vec.push_back("xx");
	vec.push_back("xx");
	vec.push_back("ij");
	vec.push_back("kl");

	vector<string>::iterator result;
	result = search_n(vec.begin(),vec.end(),4,"xx");
	if(result == vec.end()) {
		cout << "Sequence cannot be found" << endl;
	} else {
		cout << "Sequence found at " << result - vec.begin() << endl; 
	}
}