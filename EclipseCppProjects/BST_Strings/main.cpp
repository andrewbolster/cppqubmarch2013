#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>


using namespace std;
using namespace boost;

void testContains(const string & test, const string & substring);
bool splitPredicate(char ch);

int main() {
	string data = "A rolling stone gathers no moss";

	cout << "String starts as: " << data << endl << endl;

	to_upper(data);

	cout << "Converted to upper case is: " << data << endl << endl;

	to_lower(data);

	cout << "Converted to lower case is: " << data << endl << endl;

	testContains(data,"stone");

	testContains(data,"gthers");

	replace_first(data, "gathers", "accumulates");

	cout << "After replacement is: " << data << endl << endl;

	erase_first(data, "stone");

	cout << "After erasure is: " << data << endl << endl;

	vector<string> results1;
	split(results1, data, splitPredicate, token_compress_on);
	cout << "Split on whitespace found: " << endl;
	for(vector<string>::iterator iter = results1.begin(); iter != results1.end(); iter++) {
		cout << *iter << endl;
	}
	cout << endl;

	vector<string> results2;
	regex expression("[aeiou]");
	split_regex(results2, data, expression);
	cout << "Split on regex found: " << endl;
	for(vector<string>::iterator iter = results2.begin(); iter != results2.end(); iter++) {
		cout << *iter << endl;
	}
}

bool splitPredicate(char ch) {
	return ch == ' ';
}

void testContains(const string & test, const string & substring) {
	if(contains(test, substring)) {
		cout << "The substring " << substring << " occurs in " << test << endl << endl;
	} else {
		cout << "The substring " << substring << " does not occur in " << test << endl << endl;
	}
}




