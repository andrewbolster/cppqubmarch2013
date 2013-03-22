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

bool isNotLetter(const char val);
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

bool isNotLetter(const char val) {
	return val < 'a' || val > 'z';
}

bool isPalindrome(const char * data) {
	string input(data);

	int start = 0;
	int end = input.length() - 1;

	while(start < end) {
		while(isNotLetter(input[start])) {
			start++;
		}
		while(isNotLetter(input[end])) {
			end--;
		}
		if(input[start] != input[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void testForPalindrome(const char * data) {
	if(isPalindrome(data)) {
		cout << data << " is a palindrome!" << endl;
	} else {
		cout << data << " is NOT a palindrome!" << endl;
	}
}

