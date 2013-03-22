#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class StringLengthFunctor {
public:
	bool operator()(string& value) {
		return value.length() == 5;
	}
};

int main() {
	vector<string> vec;
	vec.push_back("zzz");
	vec.push_back("aaaaa");
	vec.push_back("aaaa");
	vec.push_back("aaa");
	vec.push_back("aa");
	vec.push_back("a");
	vec.push_back("zzz");
	vec.push_back("bbbbb");
	vec.push_back("bbbb");
	vec.push_back("bbb");
	vec.push_back("bb");
	vec.push_back("b");
	vec.push_back("zzz");

	long number = count(vec.begin(),vec.end(),"zzz");

	cout << "There are " << number << " elements with value zzz" << endl;

	StringLengthFunctor slf;
	number = count_if(vec.begin(),vec.end(),slf);

	cout << "There are " << number << " elements with five characters" << endl;
}