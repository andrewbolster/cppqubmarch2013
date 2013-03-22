#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

void * func(void * data);

struct MyData {
	const char * threadName;
	pthread_mutex_t * theMutex;
};

const int WAIT_IN_MICROSECONDS = 100000;
const int LONG_WAIT_IN_MICROSECONDS = WAIT_IN_MICROSECONDS * 10;
const int ITERATION_COUNT = 50;

int main() {
	pthread_t threadOne;
	pthread_t threadTwo;
	pthread_t threadThree;

	pthread_mutex_t * mutex = new pthread_mutex_t;
	pthread_mutex_init(mutex,0);

	MyData data1 = {"first thread", mutex};
	MyData data2 = {"second thread", mutex};
	MyData data3 = {"third thread", mutex};

	pthread_create(&threadOne, 0, func, (void *)&data1);
	pthread_create(&threadTwo, 0, func, (void *)&data2);
	pthread_create(&threadThree, 0, func, (void *)&data3);

	usleep(LONG_WAIT_IN_MICROSECONDS); //let the threads start
	while(pthread_mutex_trylock(mutex)) {
		printf("Main thread cant acquire mutex - spinning...\n");
		usleep(LONG_WAIT_IN_MICROSECONDS);
	}
	printf("Main thread has acquired mutex\n");
	pthread_mutex_unlock(mutex);

	pthread_join(threadOne,0);
	pthread_join(threadTwo,0);
	pthread_join(threadThree,0);

	cout << "All threads completed" << endl;
	pthread_mutex_destroy(mutex);
	cout << "End of main" << endl;
}

void * func(void * data) {
	MyData * realData = (MyData *)data;
	for(int i=0;i<ITERATION_COUNT;i++) {
		pthread_mutex_lock(realData->theMutex);
		printf("%s iteration %d message A\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message B\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message C\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message D\n",realData->threadName,i);
		pthread_mutex_unlock(realData->theMutex);
		usleep(WAIT_IN_MICROSECONDS);
	}
	return 0;
}

