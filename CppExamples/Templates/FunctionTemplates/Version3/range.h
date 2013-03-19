class Range;

class Range {
private:
	int limit;
public:
	Range(int i);
	Range& operator++(int);
	bool operator<(Range r);
	operator int();
};


