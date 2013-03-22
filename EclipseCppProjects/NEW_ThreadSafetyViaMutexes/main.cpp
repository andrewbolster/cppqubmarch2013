#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

void printMsgs(mutex* theMutex, const char * msg, int num) {
	lock_guard<mutex>guard(*theMutex);
	printf("%s iteration %d message A\n", msg, num);
	this_thread::sleep_for(chrono::milliseconds(100));
	printf("%s iteration %d message B\n", msg, num);
	this_thread::sleep_for(chrono::milliseconds(100));
	printf("%s iteration %d message C\n", msg, num);
	this_thread::sleep_for(chrono::milliseconds(100));
}

void myfunc(mutex* theMutex, const char * msg, int count) {
	for(int i=0;i<count;i++) {
		printMsgs(theMutex, msg, i);
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main() {
	mutex myMutex;

	thread t1(myfunc, &myMutex, "T1", 20);
	thread t2(myfunc, &myMutex, "T2", 20);
	thread t3(myfunc, &myMutex, "T3", 20);

	t1.join();
	t2.join();
	t3.join();

	printf("End of main...");
}
