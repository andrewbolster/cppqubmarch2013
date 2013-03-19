#include "employee.h"

int main() {
	Employee e1("Joe Bloggs",27,30000);
	Employee e2("Jane Smith",30,40000);

	e1.print();
	e2.print();

	e1.awardBonus(500);
	e2.awardBonus(750);

	e1.print();
	e2.print();
}
