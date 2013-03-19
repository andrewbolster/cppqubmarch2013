#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

//A structure that contains the data
// to be passed to a new thread
struct DataForThread {
	char name[36];
	int limit;
};

//This is the function we want to run
// in new threads using the pthreads library
void*  workerThreadFunc(void* data);

int main() {
	//the number of threads to start
	int numThreads = 5;

	//the id's of the threads we will start
	pthread_t threadIds[numThreads];

	//create all the threads
	for(int i=1;i<=numThreads;i++) {
		//create a data structure containing
		// the data the new thread will need
		struct DataForThread * dft = (struct DataForThread *) malloc(sizeof(struct DataForThread));
		sprintf(dft->name,"Thread%d",i);
		dft->limit = i * 10;

		//launch the thread with 'workerThreadFunc' as its main
		pthread_create(&threadIds[i - 1],NULL,workerThreadFunc,dft);
	}

	//wait for the threads to complete
	for(int i=1;i<=numThreads;i++) {
		printf("Waiting for thread %d\n",i);
		pthread_join(threadIds[i - 1],0);
		printf("Thread %d exited\n",i);
	}
	printf("Program complete...\n");
}

//many copies of this method will be run, each in a different thread
void* workerThreadFunc(void* data) {
	struct DataForThread* info = (struct DataForThread*)data;

	for(int i=1;i<=info->limit;i++) {
		printf("\t%s message %d of %d\n",info->name,i,info->limit);
		sleep(1);
	}

	free(info);
	return 0;
}