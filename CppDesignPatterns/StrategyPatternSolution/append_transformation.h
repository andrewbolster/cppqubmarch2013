#ifndef APPEND_TRANSFORMATION_H
#define APPEND_TRANSFORMATION_H

#include "transformation.h"

namespace demo {
	template <typename T> class AppendTransformation : public Transformation<T> {
	public:
		AppendTransformation(T extra);
		void apply(T & item);
	private:
		T extra;
	};

	template <typename T> AppendTransformation<T>::AppendTransformation(T extra) : extra(extra) {
	}

	template <typename T> void AppendTransformation<T>::apply(T & item) {
		item += extra;
	}
}

#endif //APPEND_TRANSFORMATION_H