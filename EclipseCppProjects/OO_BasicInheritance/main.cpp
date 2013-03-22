#include "employee.h"

int main() {
	Employee e("Joe Bloggs",27,30000);
	Manager m("Dave Smith",35,40000,"IT",250000);

	e.print();
	m.print();

	e.awardBonus(500);
	m.awardBonus(750);

	e.print();
	m.print();
}
