#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using std::string;

namespace demo {

	class Flight {
	public:
		enum Seating {FIRST_CLASS, STANDARD_CLASS, BUSINESS_CLASS};
		Flight(string origin, string destination, Seating seating);
		double cost(int distance);
	private:
		string origin;
		string destination;
		Seating seating;
	};

}

#endif //FLIGHT_H
