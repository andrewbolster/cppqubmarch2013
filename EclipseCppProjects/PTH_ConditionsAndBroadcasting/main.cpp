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
	pthread_cond_t  * theCondition;
};

const int WAIT_IN_MICROSECONDS = 100000;
const int LONG_WAIT_IN_MICROSECONDS = WAIT_IN_MICROSECONDS * 50;
const int ITERATION_COUNT = 10;

int main() {
	pthread_t threadOne;
	pthread_t threadTwo;
	pthread_t threadThree;

	pthread_mutex_t * mutex = new pthread_mutex_t;
	pthread_mutex_init(mutex,0);

	pthread_cond_t * condition = new pthread_cond_t;
	pthread_cond_init(condition,0);

	MyData data1 = {"first thread", mutex, condition};
	MyData data2 = {"second thread", mutex, condition};
	MyData data3 = {"third thread", mutex, condition};

	pthread_create(&threadOne, 0, func, (void *)&data1);
	pthread_create(&threadTwo, 0, func, (void *)&data2);
	pthread_create(&threadThree, 0, func, (void *)&data3);

	//let the threads start and begin waiting
	usleep(LONG_WAIT_IN_MICROSECONDS);
	printf("Main thread about to wake up all threads...\n");
	pthread_cond_broadcast(condition);

	pthread_join(threadOne,0);
	pthread_join(threadTwo,0);
	pthread_join(threadThree,0);

	cout << "All threads completed" << endl;
	pthread_mutex_destroy(mutex);
	pthread_cond_destroy(condition);
	cout << "End of main" << endl;
}

void * func(void * data) {
	MyData * realData = (MyData *)data;

	pthread_mutex_lock(realData->theMutex);
	printf("%s about to start waiting\n",realData->threadName);
	pthread_cond_wait(realData->theCondition, realData->theMutex);
	printf("%s has been woken up\n",realData->threadName);
	pthread_mutex_unlock(realData->theMutex);

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


