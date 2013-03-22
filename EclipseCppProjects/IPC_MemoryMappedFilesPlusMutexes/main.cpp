#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <iostream>

using std::cout;
using std::endl;

struct MyData {
	pthread_mutex_t mutex;
	pthread_cond_t condition;
	int data;
};

int main() {
	//this file could be created via 'dd if=/dev/zero of=test.txt bs=256 count=10'
	const char * path = "/home/garth/tmp/test.txt";
	pid_t firstChildPID;
	pid_t secondChildPID;
	int fileDescriptors[2];
	int exitStatusOne;
	int exitStatusTwo;

	cout << "Main process started with pid " << getpid() << endl;

	int fd = open(path,O_RDWR);
	void * address = mmap(0,1024,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

	MyData * dataPtr = (MyData *)address;

	//initilaize the mutex so it can be used across processes
	pthread_mutexattr_t mutexAttributes;
	pthread_mutexattr_init(&mutexAttributes);
	pthread_mutexattr_setpshared(&mutexAttributes,PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&dataPtr->mutex,&mutexAttributes);

	//initilaize the condition so it can be used across processes
	pthread_condattr_t conditionAttributes;
	pthread_condattr_init(&conditionAttributes);
	pthread_condattr_setpshared(&conditionAttributes,PTHREAD_PROCESS_SHARED);
	pthread_cond_init(&dataPtr->condition,&conditionAttributes);

	if((firstChildPID = fork()) == 0) {
		for(int i=0;i<20;i++) {
			pthread_mutex_lock(&dataPtr->mutex);
			dataPtr->data = i * 2;
			cout << "First child just wrote " << dataPtr->data << endl;
			pthread_mutex_unlock(&dataPtr->mutex);
			pthread_cond_signal(&dataPtr->condition);
			sleep(1);
		}
		exit(0);
	}
	if((secondChildPID = fork()) == 0) {
		for(int i=0;i<20;i++) {
			pthread_mutex_lock(&dataPtr->mutex);
			pthread_cond_wait(&dataPtr->condition,&dataPtr->mutex);
			cout << "Second child just read " << dataPtr->data << endl;
			pthread_mutex_unlock(&dataPtr->mutex);
		}
		exit(0);
	}
	waitpid(firstChildPID,&exitStatusOne,0);
	waitpid(secondChildPID,&exitStatusTwo,0);

	cout << "Child processes exited with values " << exitStatusOne
	     << " and " << exitStatusTwo << endl << endl;
	cout << "End of main process" << endl;
}

