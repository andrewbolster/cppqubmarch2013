#include<iostream>
using std::cout;
using std::endl;

class Accumulator {
    int total;
public:
    Accumulator();
    void add(int p1);
    void operator()(int * p1);
	int operator()();
};

Accumulator::Accumulator() : total(0){}

void Accumulator::add(int p1) {
    total += p1;
}
void Accumulator::operator()(int * p1) {
    *p1 = total;
}
int Accumulator::operator()() {
    return total;
}

int main() {
    Accumulator accumulator;
    
    accumulator.add(10);
    accumulator.add(20);
    accumulator.add(30);
    accumulator.add(40);
    accumulator.add(50);
    
    //Use function call operators
	cout << "Total is: " << accumulator() << endl;

	int total = 0;
    accumulator(&total);
    cout << "Total is: " << total << endl;
    
    return 0;
}