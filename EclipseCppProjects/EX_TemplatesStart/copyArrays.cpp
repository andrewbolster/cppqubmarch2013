#include<iostream>

using namespace std;

void copyArrays(int * ptr1, int * ptr2, int * ptr3, int size);
void print(int * ptr1, int size);

int main() {
	int iarray1[] = {10,20,30,40,50};
	int iarray2[] = {100,200,300,400,500};
	int iarray3[5];

	copyArrays(iarray1,iarray2,iarray3, 5);
	print(iarray3,5);
}
void copyArrays(int * ptr1, int * ptr2, int * ptr3, int size) {
	for(int i=0;i<size;i++) {
		*ptr3++ = *ptr1++ + *ptr2++;
	}
}
void print(int * ptr1, int size) {
	for(int i=0;i<size;i++) {
		cout << ptr1[i] << endl;
	}
}

