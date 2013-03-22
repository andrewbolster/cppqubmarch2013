#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using std::cout;
using std::endl;

void func(const char * name);

const int SLEEP_IN_SECONDS = 1;
const int ITERATION_COUNT = 20;
const int NUM_PROCESSES = 4;

int main() {
	const char * processNames[] = {"Process A", "Process B", "Process C", "Process D"};
	pid_t processIDs[NUM_PROCESSES];
	int exitStatusValues[NUM_PROCESSES];

	for(int i=0;i<NUM_PROCESSES;i++) {
		if((processIDs[i] = fork()) == 0) {
			//we are in a child process
			func(processNames[i]);
			exit(0);
		} else {
			printf("Just started %s with id %d\n",processNames[i],processIDs[i]);
		}
	}
	for(int i=0;i<NUM_PROCESSES;i++) {
		waitpid(processIDs[i],&exitStatusValues[i],0);
	}
	cout << "Processes exited with values ";
	for(int i=0;i<NUM_PROCESSES;i++) {
		cout << exitStatusValues[i] << " ";
	}
	cout << endl;
	cout << "End of main" << endl;
}
void func(const char * name) {
	for(int i=0;i<ITERATION_COUNT;i++) {
		printf("%s message %d\n",name,i);
		sleep(SLEEP_IN_SECONDS);
	}
}

