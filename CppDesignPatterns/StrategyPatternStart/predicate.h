#ifndef PREDICATE_H
#define PREDICATE_H

namespace demo {
	template <typename T> class Predicate {
	public:
		virtual bool match(const T & item) = 0;
	};
}

#endif //PREDICATE_H