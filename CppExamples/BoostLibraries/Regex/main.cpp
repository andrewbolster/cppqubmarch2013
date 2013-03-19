#include <iostream>
#include <string>

#include <boost/regex.hpp>

using std::string;

void printMatches(const string & textToSearch, const string & regularExpression) ;

int main() {
	string text = "ABCdefGHIjklMNOpqrSTUvwxYZA";
	printMatches(text,"[A-Z]{2}");
	printMatches(text,"[A-Z]{2}[a-z]");
	printMatches(text,"[A-Z]{2}[a-z]{2}");
	printMatches(text,"[A-Z][a-z]+");
	printMatches(text,"[A-Za-z]{6}$");
	printMatches(text,"[^M]+");
}

void printMatches(const string & textToSearch, const string & regularExpression) {
	using std::endl;
	using std::cout;
	using boost::regex;
	using boost::regex_search;
	using boost::smatch;

	cout << endl << "Looking for " << regularExpression << " in " << textToSearch << endl;

	string::const_iterator start = textToSearch.begin();
	string::const_iterator end = textToSearch.end();
	regex expression(regularExpression);
	smatch result;

	cout << "\tMatched: ";
	while(regex_search(start,end,result,expression)) {
		cout << result << " ";
		start = result[0].second;
	}
	cout << endl;
}

