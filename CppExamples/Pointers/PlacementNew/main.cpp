#include <iostream>

using namespace std;

int main() {
    if((2 * sizeof(short)) == sizeof(int)) {
        short sarray[2];
        //use placement new
        int * i_ptr = new (sarray) int;
        *i_ptr = 12;
        cout << "Value is " << *i_ptr << endl;
    }
    return 0;
}