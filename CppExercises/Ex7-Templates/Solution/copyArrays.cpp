#include<iostream>

using namespace std;

//generic solution
template <typename T, typename U>void copyArrays(T * ptr1, T * ptr2, U * ptr3, int size);
//full specialization for T=short U=short
template <>void copyArrays(short * ptr1, short * ptr2, short* ptr3, int size);
//partial spacialization for T = anything U=float
template <typename T>void copyArrays(T * ptr1, T * ptr2, float* ptr3, int size);

template <typename T>void print(T * ptr1, int size, char * msg);

int main() {
	int iarray1[] = {10,20,30,40,50};
	int iarray2[] = {100,200,300,400,500};
	int iarray3[5];

	copyArrays(iarray1,iarray2,iarray3, 5);
	print(iarray3,5,"results for T=int,U=int");

	double darray1[] = {10.1,20.2,30.3,40.4,50.5};
	double darray2[] = {100.1,200.2,300.3,400.4,500.5};
	double darray3[5];

	copyArrays(darray1,darray2,darray3, 5);
	print(darray3,5,"results for T=double,U=double");

	short sarray1[] = {10,20,30,40,50};
	short sarray2[] = {100,200,300,400,500};
	short sarray3[5];

	copyArrays(sarray1,sarray2,sarray3, 5);
	print(sarray3,5,"results for T=short,U=short");

	float farray1[5];

	copyArrays(iarray1,iarray2,farray1, 5);
	print(iarray3,5,"results for T=int,U=float");


}
template <typename T, typename U>void copyArrays(T * ptr1, T * ptr2, U * ptr3, int size) {
	for(int i=0;i<size;i++) {
		*ptr3++ = *ptr1++ + *ptr2++;
	}
}
template <> void copyArrays(short * ptr1, short * ptr2, short* ptr3, int size) {
	cout << endl << "SPECIALIZATION FOR T=short U=short USED" << endl;
	for(int i=0;i<size;i++) {
		*ptr3++ = *ptr1++ + *ptr2++;
	}
}
template <typename T>void copyArrays(T * ptr1, T * ptr2, float* ptr3, int size) {
	cout << endl << "PARTIAL SPECIALIZATION FOR T=anything U=float USED" << endl;
	for(int i=0;i<size;i++) {
			*ptr3++ = *ptr1++ + *ptr2++;
	}
}
template <typename T>void print(T * ptr1, int size, char * msg) {
	cout << endl << msg << endl;
	for(int i=0;i<5;i++) {
		cout << ptr1[i] << endl;
	}
}

