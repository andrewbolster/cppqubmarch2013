
namespace demo {
	class SeatingType {
	public:
		virtual double cost(int distance) = 0;
	};

	class StandardSeatingType : public SeatingType {
	public:
		double cost(int distance);
	};

	class BusinessSeatingType : public SeatingType {
	public:
		double cost(int distance);
	};

	class FirstClassSeatingType : public SeatingType {
	public:
		double cost(int distance);
	};
}