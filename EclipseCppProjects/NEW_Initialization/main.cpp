#include<iostream>
#include<string>

using namespace std;

struct MyStruct {
	int i;
	double d;
	bool b;

	void print(ostream& sink) {
		sink << i << " " << d << " " << b << endl;
	}
};

class MyClass {
public:
	MyClass(short s, float f, const string & str) {
		cout << "MyClass constructor called!" << endl;
		this->s = s;
		this->f = f;
		this->str = str;
	}
	void print(ostream& sink) {
		sink << s << " " << f << " " << str << endl;
	}
private:
	short s;
	float f;
	string str;
};

int main() {
	MyStruct ms {12, 3.4, true};
	MyClass  mc {56, 7.8f, "abc"};

	ms.print(cout);
	mc.print(cout);
}






