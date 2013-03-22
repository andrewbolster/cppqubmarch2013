#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

namespace demo {
	struct mystruct {
		int a;
		double b;
		bool c;
	};
	void func(const mystruct & ms) {
		cout << "Func called with values " << ms.a << " "
			 << ms.b << " and " << ms.c << endl;
	}
	ostream & operator<<(ostream & output, const mystruct & data) {
		output << data.a << " " << data.b << " " << data.c << endl;
		return output;
	}
}
int main() {
	demo::mystruct val = {12, 3.4, true};
	func(val);
	cout << val;
}
