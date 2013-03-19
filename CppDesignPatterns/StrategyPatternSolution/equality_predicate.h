#ifndef EQUALITY_PREDICATE_H
#define EQUALITY_PREDICATE_H

#include "predicate.h"

namespace demo {
	template <typename T> class EqualityPredicate : public Predicate<T> {
	public:
		EqualityPredicate(T test);
		bool match(const T & item);
	private:
		T test;
	};
	
	template <typename T> EqualityPredicate<T>::EqualityPredicate(T test) : test(test) {
	}
	template <typename T> bool EqualityPredicate<T>::match(const T & item) {
		return test == item;
	}
}

#endif //EQUALITY_PREDICATE_H