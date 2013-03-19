#include <iostream>

double addAll(double * data_ptr, int length) {
    double total = 0;
    for(int i=0;i<length;i++) {
        total = total + data_ptr[i];
    }
    return total;
}

int main() {
    double darray[10] = {1,2,3,4,5,6,7,8,9,10};
    double result = addAll(darray,10);
    std::cout << "Total is: " << result << std::endl;
}