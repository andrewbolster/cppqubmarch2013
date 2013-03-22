#include <iostream>
#include <string>

using namespace std;

const char * data1 = "a man, a plan, a canal, panama";
const char * data2 = "gold is where you find it";
const char * data3 = "if i had a hi-fi";
const char * data4 = "fortune favors the prepared mind";
const char * data5 = "rats live on no evil star";
const char * data6 = "there is no abstract living";
const char * data7 = "some men interpret nine memos";

void removeAll(string & input, const char val);
bool isPalindrome(const char * data);
void testForPalindrome(const char * data);

int main() {
	testForPalindrome(data1);
	testForPalindrome(data2);
	testForPalindrome(data3);
	testForPalindrome(data4);
	testForPalindrome(data5);
	testForPalindrome(data6);
	testForPalindrome(data7);
}

bool isPalindrome(const char * data) {
	string input(data);

	removeAll(input,' ');
	removeAll(input,',');
	removeAll(input,'-');

	//cout << "New input is: " << input << endl;

	string reversedInput;
	for(unsigned int i=0;i<input.length();i++) {
		reversedInput.insert(0,1,input[i]);
	}

	//cout << "Reversed input is: " << reversedInput << endl;

	return input.compare(reversedInput) == 0;
}

void removeAll(string & input, const char val) {
	unsigned long pos = input.find(val);
	while(pos != string::npos) {
		input.erase(pos,1);
		pos = input.find(val);
	}
}

void testForPalindrome(const char * data) {
	if(isPalindrome(data)) {
		cout << data << " is a palindrome!" << endl;
	} else {
		cout << data << " is NOT a palindrome!" << endl;
	}
}

