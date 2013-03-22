#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	pid_t childProcessID;
	int fileDescriptors[2];
	int exitStatus;

	cout << "Start of main process (" << getpid() << ")" << endl;

	pipe(fileDescriptors);
	if((childProcessID = fork()) == 0) {
		//we are in a child process
		close(fileDescriptors[1]);
		char buffer[10];
		for(int i=0;i<10;i++) {
			read(fileDescriptors[0],buffer,10);
			cout << "Child process (" << getpid() << ") just read in " << buffer << endl;
		}
		exit(0);
	} else {
		close(fileDescriptors[0]);
		char buffer[10];
		for(int i=0;i<10;i++) {
			sprintf(buffer,"Message %d",i);
			write(fileDescriptors[1],buffer,10);
			sleep(2);
		}
	}
	waitpid(childProcessID,&exitStatus,0);

	cout << "Child process exited with value " << exitStatus << endl;
	cout << "End of main process (" << getpid() << ")" << endl;
}

