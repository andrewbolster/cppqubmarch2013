#include "seating.h"

namespace demo {

	double StandardSeatingType::cost(int distance) {
		double cost = 250;
		if(distance > 200) {
			cost += distance * 0.20;
		} else {
			cost += distance * 0.10;
		}
		return cost;
	}

	double BusinessSeatingType::cost(int distance) {
		double cost = 300;
		if(distance > 200) {
			cost += distance * 0.40;
		} else {
			cost += distance * 0.30;
		}
		return cost;
	}

	double FirstClassSeatingType::cost(int distance) {
		double cost = 500;
		if(distance > 200) {
			cost += distance * 0.60;
		} else {
			cost += distance * 0.50;
		}
		return cost;
	}
}

