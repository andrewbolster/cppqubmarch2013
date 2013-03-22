#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "seating.h"

using std::string;

namespace demo {

	class Flight {
	public:
		enum Seating {FIRST_CLASS, STANDARD_CLASS, BUSINESS_CLASS};
		Flight(string origin, string destination, Seating seating);
		double cost(int distance);
		void changeSeating(Seating seating);
		~Flight();
	private:
		string origin;
		string destination;
		SeatingType * seatingType;
	};

}

#endif //FLIGHT_H
