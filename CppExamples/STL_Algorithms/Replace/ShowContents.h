#include<iostream>
#include<algorithm>

using namespace std;

class PrintFunctor {
	ostream& output;
public:
	PrintFunctor(ostream& output) : output(output){}
	template<typename T> void operator()(T& value) {
		output << value << endl;
	}
};

template<typename T> void showContents(T& container, ostream& output) {
	typename T::iterator start = container.begin();
	typename T::iterator stop = container.end();
	PrintFunctor functor(output);

	for_each(start,stop, functor);
}