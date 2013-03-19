#include <iostream>

using namespace std;

class Number {
    friend Number operator+(const Number&, const Number&);
private:
    int value;
public:
    Number(int num);
    void print(ostream& output) const;
};

Number operator+(const Number& lhs, const Number& rhs) {
    int total = lhs.value + rhs.value;
    Number tmp(total);
    return tmp;	
}

ostream& operator<<(ostream& output, const Number& rhs) {
    rhs.print(output);
    return output;
}

Number::Number(int num) {
    value = num;
}

void Number::print(ostream& output) const {
    output << "The value in this number is: " << value << endl;
}

int main() {
    Number no1(8);
    Number no2(2);

    Number no3 = no1 + no2;
    cout << no3;

    Number no4 = 12 + no3;
    cout << no4;
}