#include<string>
#include<iostream>
#include "bridge.h"

using namespace std;


void main() {
	Stack stack;

	stack.add("abc");
	stack.add("def");
	stack.add("ghi");
	stack.add("jkl");
	stack.add("mno");
	stack.add("pqr");
	stack.add("stu");

	cout << "item 3 is " << stack.get(3) << endl;
}