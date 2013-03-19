#include <iostream>

#include <boost/lambda/lambda.hpp>
#include <boost/function.hpp>

using std::cout;
using std::endl;
using boost::function;
using boost::lambda::_1;
using boost::lambda::_2;

int main() {
	function<void(int,int)>	    add = cout << "Adding gives: " <<  (_1 + _2) << "\n";
	add(11,5);

	function<void(int,int)>	    subtract = cout << "Subtracting gives: "  << ( _1 - _2) << "\n";
	subtract(11,5);

	function<void(int,int)>	    multiply = cout << "Multiplying gives: "  <<  (_1 * _2) << "\n";
	multiply(11,5);
}