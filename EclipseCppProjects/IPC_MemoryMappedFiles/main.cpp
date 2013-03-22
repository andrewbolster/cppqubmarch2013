#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <iostream>

using std::cout;
using std::endl;

struct MyData {
	pid_t pid;
	int val1;
	double val2;
	bool val3;
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

	if((firstChildPID = fork()) == 0) {
		MyData data = {getpid(), 12,3.4,true};
		MyData * tmp = (MyData *)address;
		*tmp = data;
		exit(0);
	}
	if((secondChildPID = fork()) == 0) {
		MyData data = {getpid(), 57,7.8,false};
		MyData * tmp = (MyData *)address;
		tmp++;
		*tmp = data;
		exit(0);
	}
	waitpid(firstChildPID,&exitStatusOne,0);
	waitpid(secondChildPID,&exitStatusTwo,0);

	cout << "Child processes exited with values " << exitStatusOne
	     << " and " << exitStatusTwo << endl << endl;

	cout << "Data in shared memory is:" << endl;
	MyData * ptr = (MyData *)address;
	cout << "\t" << ptr->pid << " " << ptr->val1 << " " << ptr->val2 << " " << ptr->val3 << endl;
	ptr++;
	cout << "\t" << ptr->pid << " " << ptr->val1 << " " << ptr->val2 << " " << ptr->val3 << endl << endl;
	cout << "End of main process" << endl;
}
