#include <iostream>

using namespace std;

enum Directions { NORTH = 10, SOUTH, EAST = 20, WEST };

void setSail(enum Directions d);

int main() {
	enum Directions d1 = NORTH;
	enum Directions d2 = SOUTH;
	enum Directions d3 = EAST;
	enum Directions d4 = WEST;
        
	setSail(d1);
	setSail(d2);
	setSail(d3);
	setSail(d4);
}

void setSail(enum Directions d) {
	cout << "You want to sail: " << endl;
	switch (d) {
		case NORTH:
			cout << "North (" << NORTH << ")" << endl;
			break;
		case SOUTH:
			cout << "South (" << SOUTH << ")" << endl;
			break;
		case EAST:
			cout << "East (" << EAST << ")" << endl;
			break;
		case WEST:
			cout << "West (" << WEST << ")" << endl;
			break;
	}
}