#include<iostream>

using namespace std;

class X;

int test(X& x);

class Z {
public:
    int test(X& x);
};

class Y{
private:
    //cannot be seen from X as friendship is one way
    int hidden; 
public:
    int test(X& x);
};

class X {
private:
    int i;
    int func(){return 27;}
    friend int test(X& x);      //global function test is a friend		
    friend int Y::test(X& x);	//method test in class Y is a friend
    friend class Z;             //all methods of Z are friends

    friend int test2(X& x) {	//this rarely used syntax declares
        return x.func();        // a global function called test2
    }                           // which is a friend of X
public:
    X():i(17){}
};

int test(X& x) {return x.i;}
int Y::test(X& x){return x.i;}
int Z::test(X& x){return x.func();}

int main(){
    X x;
    Y y;
    Z z;

    cout << "Values returned are: " << test(x) << " " << test2(x)  
         << " " << y.test(x) << " " << z.test(x) << endl;
}