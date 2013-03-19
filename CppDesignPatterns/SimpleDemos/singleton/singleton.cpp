#include <iostream>
#include <string>

using namespace std;

class Singleton {
public:
	//create or return the singleton
	static Singleton& instance();
	string getMessage();

private: 
	//clients cannot copy the singleton
	Singleton(string msg);
	//assignment is a contradiction for singletons
	Singleton& operator=(const Singleton& rhs);

	string message;
};

Singleton::Singleton(string msg) : message(msg) {}

string Singleton::getMessage() {
	return message;
}

Singleton& Singleton::instance() {
	static Singleton obj("The Singleton");
	return obj;
}

void main() {

	Singleton& s1 = Singleton::instance();
	Singleton& s2 = Singleton::instance();

	cout << "s1 class is called " << s1.getMessage() << " and lives at " << &s1 << endl;
	cout << "s2 class is called " << s2.getMessage() << " and lives at " << &s2 << endl;
}


