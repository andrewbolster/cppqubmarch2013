#include <stdio.h>
#include <iostream>
#include <thread>

using namespace std;

void myfunc(const char * msg, int count) {
	for(int i=0;i<count;i++) {
		printf("%s message %d\n", msg, i);
		this_thread::sleep_for(chrono::seconds(1));
	}
}

class StatelessFunctor {
public:
	void operator()(const char * msg, int count) {
		for(int i=0;i<count;i++) {
			printf("%s message %d\n", msg, i);
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
};

class StatefulFunctor {
public:
	StatefulFunctor(const char * msg, int count) : msg(msg), count(count) {}
	StatefulFunctor(const StatefulFunctor& other) {
		cout << "StatefulFunctor copy constructor called..." << endl;
		msg = other.msg;
		count = other.count;
	}
	void operator()() {
		for(int i=0;i<count;i++) {
			printf("%s message %d\n", msg, i);
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
private:
	const char * msg;
	int count;
};

int main() {
	StatelessFunctor obj1;
	StatefulFunctor obj2("Stateful functor",20);

	thread t1(myfunc,"Function",20);
	thread t2(obj1, "Stateless functor", 20);
	thread t3(obj2);

	t1.join();
	t2.join();
	t3.join();
	cout << "Threads completed - end of main..." << endl;
}




