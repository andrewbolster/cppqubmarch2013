#ifndef ARRAY_H
#define ARRAY_H

#include "interface.h"

namespace demo {

	template <typename T> class ArrayList : public List<T> {
	public:
		ArrayList(int i);
		void add(T item);
		T get(int index);
		int length();
		T remove(int index);
	private:
		void expandArray();
	private:
		int insertIndex;
		int capacity;
		T * buffer;
	};

	template <typename T> ArrayList<T>::ArrayList(int i) : insertIndex(0), capacity(i)  {
		buffer = new T[i];
	}

	template <typename T> int ArrayList<T>::length() {
		return insertIndex;
	}

	template <typename T> T ArrayList<T>::get(int index) {
		return buffer[index];
	}

	template <typename T> void ArrayList<T>::add(T item) {
		if(insertIndex == capacity) {
			expandArray();
		}
		buffer[insertIndex++] = item;
	}

	template <typename T> T ArrayList<T>::remove(int index) {
		T value = buffer[index];
		for(int i = index+1; i < insertIndex; i++) {
			buffer[i - 1] = buffer[i];
		}
		insertIndex--;
		return value;
	}

	template <typename T> void ArrayList<T>::expandArray() {
		T * oldBuffer = buffer;
		capacity *= 2;
		buffer = new T[capacity];
		for(int i=0;i<insertIndex;i++) {
			buffer[i] = oldBuffer[i];
		}
		delete[] oldBuffer;
	}
}

#endif //ARRAY_H



