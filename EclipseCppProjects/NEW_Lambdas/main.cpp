#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void demo1();
void demo2();
void demo3();
void demo4();
void demo5();

int main() {
	demo1();
	demo2();
	demo3();
	demo4();
	demo5();
}
void demo1() {
	auto simpleLambda = [](int a, int b) { return (a <= b) ? "foo" : "bar"; };

	cout << simpleLambda(20,30) << endl;
	cout << simpleLambda(30,20) << endl;
}
void demo2() {
	auto multiLineLambda = [](int a, int b)->const char * {
								if(a <= b) {
									return "foo";
								} else {
									return "bar";
								}
							};

	cout << "------" << endl;
	cout << multiLineLambda(20,30) << endl;
	cout << multiLineLambda(30,20) << endl;
}
void demo3() {
	auto noArgsLambda = [] { return "foobar"; };

	cout << "------" << endl;
	cout << noArgsLambda() << endl;
}
void demo4() {
	int a = 12;
	auto lambdaCapturingByRef = [&]()->int {
										a = a * 2;
										return a;
									};
	cout << "------" << endl;
	cout << lambdaCapturingByRef() << endl;
	cout << "Local variable now: " << a << endl;
}
void demo5() {
	vector<int> input;
	input.push_back(10);
	input.push_back(20);
	input.push_back(30);
	input.push_back(40);
	input.push_back(50);

	cout << "------" << endl;
	cout << "Values from vector when doubled are:" << endl;
	for_each(input.begin(), input.end(), [](int val) { cout << val * 2 << endl; });
}




