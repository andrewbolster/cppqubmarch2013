#include "flight.h"

namespace demo {

	Flight::Flight(string origin, string destination, Seating seating) {
		this->origin = origin;
		this->destination = destination;
		this->seating = seating;
	}

	double Flight::cost(int distance) {
		double cost = 0;
		if(seating == FIRST_CLASS) {
			cost = 500;
			if(distance > 200) {
				cost += distance * 0.60;
			} else {
				cost += distance * 0.50;
			}
		} else if(seating == BUSINESS_CLASS) {
			cost = 300;
			if(distance > 200) {
				cost += distance * 0.40;
			} else {
				cost += distance * 0.30;
			}
		} else if(seating == STANDARD_CLASS) {
			cost = 250;
			if(distance > 200) {
				cost += distance * 0.20;
			} else {
				cost += distance * 0.10;
			}
		}
		return cost;
	}

}
