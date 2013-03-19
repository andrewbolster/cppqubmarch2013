#ifndef DECORATOR_H
#define DECORATOR_H

#include "list.h"
#include <string>

using std::string;

namespace demo {

	template <typename T> class UnmodifiableList : public List<T> {
	public:
		UnmodifiableList(List<T> & list);
		void add(T item);
		T get(int index);
		int length();
		T remove(int index);
	private:
		List<T> & wrappedList;
	};

	template<typename T> UnmodifiableList<T>::UnmodifiableList(List<T> & list) : wrappedList(list) {
	}
	template<typename T> void UnmodifiableList<T>::add(T item) {
		throw string("Cannot add to unmodifiable list!");
	}
	template<typename T> T UnmodifiableList<T>::get(int index) {
		return wrappedList.get(index);
	}
	template<typename T> int UnmodifiableList<T>::length() {
		return wrappedList.length();
	}
	template<typename T> T UnmodifiableList<T>::remove(int index) {
		throw string("Cannot remove from unmodifiable list!");
	}
}

#endif //DECORATOR_H