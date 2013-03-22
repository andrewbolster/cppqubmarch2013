#include <stdio.h>
#include <iostream>
#include <thread>

using namespace std;

void myfunc() {
	for(int i=0;i<20;i++) {
		printf("myfunc message %d\n", i);
		this_thread::sleep_for(chrono::seconds(1));
	}
}

class MyFunctor {
public:
	void operator()() {
		for(int i=0;i<20;i++) {
			printf("myfunctor message %d\n", i);
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
};

int main() {
	MyFunctor obj;

	thread t1(myfunc);
	thread t2(obj);

	t1.join();
	t2.join();
	cout << "Threads completed - end of main..." << endl;
}




