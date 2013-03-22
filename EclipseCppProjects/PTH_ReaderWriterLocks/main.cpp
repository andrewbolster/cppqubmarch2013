#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

void * readerFunc(void * data);
void * writerFunc(void * data);

struct MyData {
	const char * threadName;
	pthread_rwlock_t  * theRWLock;
};

const int WAIT_IN_MICROSECONDS = 100000;
const int ITERATION_COUNT = 20;

int main() {
	pthread_t threadOne;
	pthread_t threadTwo;
	pthread_t threadThree;
	pthread_t threadFour;
	pthread_t threadFive;
	pthread_t threadSix;

	pthread_rwlock_t * rwLock = new pthread_rwlock_t;
	pthread_rwlock_init(rwLock,0);

	MyData data1 = {"reader thread one", rwLock};
	MyData data2 = {"reader thread two", rwLock};
	MyData data3 = {"reader thread three", rwLock};
	MyData data4 = {"reader thread four", rwLock};
	MyData data5 = {"writer thread one", rwLock};
	MyData data6 = {"writer thread two", rwLock};

	pthread_create(&threadOne, 0, readerFunc, (void *)&data1);
	pthread_create(&threadTwo, 0, readerFunc, (void *)&data2);
	pthread_create(&threadThree, 0, readerFunc, (void *)&data3);
	pthread_create(&threadFour, 0, readerFunc, (void *)&data4);
	pthread_create(&threadFive, 0, writerFunc, (void *)&data5);
	pthread_create(&threadSix, 0, writerFunc, (void *)&data6);

	pthread_join(threadOne,0);
	pthread_join(threadTwo,0);
	pthread_join(threadThree,0);
	pthread_join(threadFour,0);
	pthread_join(threadFive,0);
	pthread_join(threadSix,0);

	cout << "All threads completed" << endl;
	pthread_rwlock_destroy(rwLock);
	cout << "End of main" << endl;
}

void * readerFunc(void * data) {
	MyData * realData = (MyData *)data;

	for(int i=0;i<ITERATION_COUNT;i++) {
		pthread_rwlock_rdlock(realData->theRWLock);
		printf("%s iteration %d message A\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message B\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message C\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message D\n",realData->threadName,i);
		pthread_rwlock_unlock(realData->theRWLock);
		usleep(WAIT_IN_MICROSECONDS);
	}
	return 0;
}

void * writerFunc(void * data) {
	MyData * realData = (MyData *)data;

	for(int i=0;i<ITERATION_COUNT;i++) {
		pthread_rwlock_wrlock(realData->theRWLock);
		printf("%s iteration %d message A\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message B\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message C\n",realData->threadName,i);
		usleep(WAIT_IN_MICROSECONDS);
		printf("%s iteration %d message D\n",realData->threadName,i);
		pthread_rwlock_unlock(realData->theRWLock);
		usleep(WAIT_IN_MICROSECONDS);
	}
	return 0;
}

