#include <iostream>
#include "flight.h"

using demo::Flight;
using std::cout;
using std::endl;

int main() {

	Flight f1("Belfast","Dublin",Flight::STANDARD_CLASS);

	cout << "Short standard class flight costs " << f1.cost(100) << endl;
	cout << "Long standard class flight costs " << f1.cost(300) << endl;

	f1.changeSeating(Flight::BUSINESS_CLASS);
	cout << "Short business class flight costs " << f1.cost(100) << endl;
	cout << "Long business class flight costs " << f1.cost(300) << endl;

	f1.changeSeating(Flight::FIRST_CLASS);
	cout << "Short first class flight costs " << f1.cost(100) << endl;
	cout << "Long first class flight costs " << f1.cost(300) << endl;
}