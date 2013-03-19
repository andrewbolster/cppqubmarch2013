#include <iostream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main() {
	typedef tokenizer<char_separator<char> > char_tokenizer;
	typedef tokenizer<offset_separator> offset_tokenizer;
	
	string data = "There is no abstract living";
	
	char_separator<char> sep1(" ","t");
	char_tokenizer tokenizer1(data,sep1);
	
	int offsets[] = {3,4,7,5};
	offset_separator sep2(offsets[0], offsets[3]);
	offset_tokenizer tokenizer2(data,sep2);
	
	cout << "Results of character based tokenization are:" << endl;
	for(char_tokenizer::iterator iter = tokenizer1.begin(); iter != tokenizer1.end(); iter++) {
		cout << *iter << endl;	
	}
	
	cout << "Results of offset based tokenization are:" << endl;
	for(offset_tokenizer::iterator iter = tokenizer2.begin(); iter != tokenizer2.end(); iter++) {
		cout << *iter << endl;	
	}
}