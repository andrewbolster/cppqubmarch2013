#include <iostream>

using namespace std;

int main() {
    int myarray[10] = {101,202,303,404,505,606,707,808,909,0};
    int * i_ptr = myarray;
    while(*i_ptr != 0) {
            cout << *i_ptr << endl;
            i_ptr++;
    }
    cout << "-----------------------" << endl;
    int * i_ptr2 = myarray;
    int count = 0;
    while(i_ptr2[count] != 0) {
        cout << i_ptr2[count++] << endl;
    }
    return 0;
}
