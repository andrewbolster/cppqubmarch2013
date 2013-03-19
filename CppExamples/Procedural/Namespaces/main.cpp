#include <iostream>
#include <string>

using namespace std;  //bring in all symbols from std namespace

namespace A {
	void print(string str) {
		cout << str << endl;
	}
}
namespace B {
	using A::print;	//bring in a single symbol from namespace A
	void printStrings(string str1, string str2, string str3) {
		print(str1);
		print(str2);
		print(str3);
	}
}
int main() {
	B::printStrings("abc","def","ghi");
	return 0;
}
