#ifndef INTERFACE_H
#define INTERFACE_H

#include "predicate.h"
#include "transformation.h"

namespace demo {
	template <typename T> class List {
	public:
		virtual void add(T item) = 0;
		virtual T get(int index) = 0;
		virtual int length() = 0;
		virtual T remove(int index) = 0;
		virtual int collect(Predicate<T> & p) = 0;
		virtual void transform(Transformation<T> & t) = 0;
	};
}

#endif //INTERFACE_H