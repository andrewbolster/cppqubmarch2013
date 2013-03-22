#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void * func(void * data);

const int WAIT_IN_MICROSECONDS = 250000;
const int ITERATION_COUNT = 50;

int main() {
	pthread_t threadOne;
	pthread_t threadTwo;
	pthread_t threadThree;

	pthread_create(&threadOne, 0, func, (void *)"first thread");
	pthread_create(&threadTwo, 0, func, (void *)"second thread");
	pthread_create(&threadThree, 0, func, (void *)"third thread");

	string * val1;
	pthread_join(threadOne,(void **)&val1);

	string * val2;
	pthread_join(threadTwo,(void **)&val2);

	string * val3;
	pthread_join(threadThree,(void **)&val3);

	cout << "All threads completed with return values:" << endl;
	cout << "\t" << *val1 << endl;
	cout << "\t" << *val2 << endl;
	cout << "\t" << *val3 << endl;

	delete val1;
	delete val2;
	delete val3;

	cout << "End of main" << endl;
}

void * func(void * data) {
	const char * name = (char *)data;
	for(int i=0;i<ITERATION_COUNT;i++) {
		printf("%s message %d\n",name,i);
		usleep(WAIT_IN_MICROSECONDS);
	}
	string * retval = new string(name);
	retval->append(" finished!");
	return retval;
}

