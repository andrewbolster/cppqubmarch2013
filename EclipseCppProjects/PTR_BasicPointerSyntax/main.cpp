#include <iostream>

using namespace std;

int main() {
    int i = 27;

    int * i_ptr = &i;
    cout << "value in i is " << i << endl;
    cout << "address of i is " << &i << endl;
    cout << "value in pointer is " << i_ptr << endl;
    cout << "value from dereferencing pointer is " << *i_ptr << endl;

    int ** i_ptr_ptr = &i_ptr;
    cout << "address of i_ptr is " << &i_ptr << endl;
    cout << "value in pointer to pointer is " << i_ptr_ptr << endl;
    cout << "value from dereferencing pointer to pointer is " << *i_ptr_ptr << endl;

    int *** i_ptr_ptr_ptr = &i_ptr_ptr;
    cout << "address of i_ptr_ptr is " << &i_ptr_ptr << endl;
    cout << "value in pointer to pointer to pointer is " << i_ptr_ptr_ptr << endl;
    cout << "value from dereferencing pointer to pointer to pointer is " << *i_ptr_ptr_ptr << endl;

    //References dont work the same way as pointers...
    int & ref1 = i;
    int & ref2 = ref1;
    int & ref3 = ref2;

    cout << "Address of i is " << &i << endl;
    cout << "Addresses of references are " << &ref1 << " " << &ref2 << " " << &ref3 << endl;
    cout << "Value of i is " << ref1 << " " << ref2 << " " << ref3 << endl;

    return 0;
}
