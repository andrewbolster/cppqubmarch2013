#include <iostream>
#include "flight.h"

using demo::Flight;
using std::cout;
using std::endl;

int main() {

	Flight f1("Belfast","Dublin",Flight::STANDARD_CLASS);
	Flight f2("Belfast","Chicago",Flight::BUSINESS_CLASS);
	Flight f3("Belfast","Manchester",Flight::FIRST_CLASS);

	cout << "Short standard class flight costs " << f1.cost(100) << endl;
	cout << "Long standard class flight costs " << f1.cost(300) << endl;

	cout << "Short business class flight costs " << f2.cost(100) << endl;
	cout << "Long business class flight costs " << f2.cost(300) << endl;

	cout << "Short first class flight costs " << f3.cost(100) << endl;
	cout << "Long first class flight costs " << f3.cost(300) << endl;
}