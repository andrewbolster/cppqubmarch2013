#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class MyClass {
public:
	MyClass(int value) : value(value) {}
	int getValue() { return value; }
private:
	int value;
};

map<string, vector<MyClass>> * func() {

	vector<MyClass> theVector;
	theVector.push_back(MyClass(12));
	theVector.push_back(MyClass(13));
	theVector.push_back(MyClass(14));
	theVector.push_back(MyClass(15));
	theVector.push_back(MyClass(16));

	map<string, vector<MyClass>> * data = new map<string, vector<MyClass>>();
	data->insert(pair<string, vector<MyClass>>("ab12",theVector));
	data->insert(pair<string, vector<MyClass>>("cd34",theVector));
	data->insert(pair<string, vector<MyClass>>("ef56",theVector));

	return data;
}

int main() {
	auto myvar1 = 12;
	auto myvar2 = new string("abc");
	auto myvar3 = func();

	myvar1 += 3;
	(*myvar2) += "def";
	myvar3->at("cd34").push_back(17);
	myvar3->at("cd34").push_back(18);
	myvar3->at("cd34").push_back(19);

	cout << "Modifed data is:" << endl;
	cout << "\tmyvar1:" << myvar1 << endl;
	cout << "\tmyvar2:" << *myvar2 << endl;

	cout << "\tmyvar3:" << endl;
	for(auto iterator1 = myvar3->begin(); iterator1 != myvar3->end(); iterator1++) {
		auto row = *iterator1;
		cout << "\t\t" << row.first << " holding:" << endl;
		for(auto iterator2 = row.second.begin(); iterator2 != row.second.end(); iterator2++) {
			cout << "\t\t\t" << iterator2->getValue() << endl;
		}
	}

	delete myvar2;
	delete myvar3;
}



