#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

namespace demo {
	template <typename T> class Transformation {
	public:
		virtual void apply(T & item) = 0;
	};
}

#endif //TRANSFORMATION_H