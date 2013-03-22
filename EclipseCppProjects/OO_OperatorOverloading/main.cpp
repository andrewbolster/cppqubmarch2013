#include<iostream>
#include<sstream>

using namespace std;

class Point;

ostream& operator<<(ostream& s,const Point& p);

class Point {
friend ostream& operator<<(ostream& s,const Point& p);
private:
    int x;
    int y;
public:
    Point(int a=0,int b=0):x(a),y(b){}
    Point(const Point& rhs):x(rhs.x),y(rhs.y){}
    Point& operator=(const Point& rhs);
    Point& operator=(int * values);
    bool operator==(const Point& rhs);
    Point operator+(const Point& rhs);
};

Point& Point::operator=(const Point& rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
}
Point& Point::operator=(int * values) {
    x = values[0];
    y = values[1];
    return *this;
}

bool Point::operator==(const Point& rhs) {
    return((x == rhs.x) && (y == rhs.y));
}

Point Point::operator+(const Point& rhs) {
    Point sum(x + rhs.x, y + rhs.y);
    return sum;
}

ostream& operator<<(ostream& s,const Point& p) {
    return s << "x coordinate is " << p.x << " and y coordinate is " << p.y << endl;
}

int main() {
    Point tst1(1,1), tst2(2,2);

    //test operator+
    Point tst3 = tst1 + tst2;
    cout<<tst3;

    //test operator=(Point)
    tst1 = tst2;
    cout<<tst1;

    //test operator=(int *)
    int location[2] = {7,9};
    tst3 = location;
    cout << tst3;

    //test operator==
    if(tst1 == tst2) cout <<"points match" <<endl;

    return 0;
}
