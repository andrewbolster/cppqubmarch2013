#include<iostream>

struct Data {
    int i;
    float f;
    double d;
};

void printData(const Data& d) {
    std::cout<< "i is " << d.i << " f is " << d.f << " and d is " << d.d << std::endl;
}

class Pointer {
public:
    Pointer(Data *dptr) {
        this->dptr = dptr;
    }
    Data* operator->() {
        return dptr;
    }
    Data& operator*() {
        return *dptr;
    }
    ~Pointer() {
        delete dptr;
    }
private:
    Data *dptr;
};

int main() {
    Pointer p(new Data());

    p->d = 12.3;
    p->f = 1.3f;
    p->i = 7;

    printData(*p);
}