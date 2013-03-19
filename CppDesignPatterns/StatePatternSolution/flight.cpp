
#include "flight.h"

namespace demo {

	Flight::Flight(string origin, string destination, Seating seating) {
		this->origin = origin;
		this->destination = destination;
		changeSeating(seating);
	}

	Flight::~Flight() {
		delete seatingType;
	}

	void Flight::changeSeating(Seating seating) {
		if(seating == FIRST_CLASS) {
			seatingType = new FirstClassSeatingType;
		} else if(seating == STANDARD_CLASS) {
			seatingType = new StandardSeatingType;
		} else if(seating == BUSINESS_CLASS) {
			seatingType = new BusinessSeatingType;
		} 
	}

	double Flight::cost(int distance) {
		return seatingType->cost(distance);
	}

}