#include <iostream>

using namespace std;

class BaseOne {
public:
   ~BaseOne() {
	   cout << "BaseOne::~BaseOne" << endl;
   }
};
class DerivedOne : public BaseOne {
public:
    ~DerivedOne() {
		   cout << "DerivedOne::~DerivedOne" << endl;
   }
};

class BaseTwo {
public:
   virtual ~BaseTwo() {
	   cout << "BaseTwo::~BaseTwo" << endl;
   }
};
class DerivedTwo : public BaseTwo {
public:
    ~DerivedTwo() {
		   cout << "DerivedTwo::~DerivedTwo" << endl;
   }
};

int main() {
    DerivedOne * dptr1 = new DerivedOne;
    DerivedTwo * dptr2 = new DerivedTwo;

    BaseOne * bptr1 = dptr1;
    BaseTwo * bptr2 = dptr2;

    delete bptr1;

    cout << "--------------------" << endl;

    delete bptr2;

    return 0;
}

