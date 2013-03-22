#include <stdio.h>
#include <thread>
#include <mutex>
#include <queue>
#include <string>
#include <condition_variable>

using namespace std;

void producer(condition_variable * theCondition, mutex * theMutex, queue<string> * theQueue) {
	string data[] = {"abc","def","ghi","jkl","mno","pqr","xxx"};
	for(int i=0;i<7;i++) {
		theMutex->lock();
		theQueue->push(data[i]);
		printf("Producer just published (will notify in 2 secs)\n");
		this_thread::sleep_for(chrono::seconds(2));
		theCondition->notify_one();
		theMutex->unlock();
		this_thread::sleep_for(chrono::seconds(4));
	}
}

void consumer(condition_variable * theCondition, mutex * theMutex, queue<string> * theQueue) {
	while(true) {
		unique_lock<mutex> uniqueLock(*theMutex);
		theCondition->wait(uniqueLock,[theQueue]{ return !theQueue->empty(); });
		string str = theQueue->front();
		theQueue->pop();
		printf("Consumer just read %s\n", str.c_str());
		theMutex->unlock();
		if(str == "xxx") {
			break;
		}
	}
}

int main() {
	condition_variable myCondition;
	mutex myMutex;
	queue<string> myQueue;

	thread t1(producer, &myCondition, &myMutex, &myQueue);
	thread t2(consumer, &myCondition, &myMutex, &myQueue);

	t1.join();
	t2.join();

	printf("End of main...");
}



