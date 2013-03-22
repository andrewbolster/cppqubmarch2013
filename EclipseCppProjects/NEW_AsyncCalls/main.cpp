#include <thread>
#include <mutex>
#include <iostream>
#include <future>
#include <ctime>

using namespace std;

struct MyReturn {
	double retval;
	time_t timeCompleted;

	void print(ostream & out) {
		tm * when  = localtime(&timeCompleted);
		out << "\t" << retval << " at "
		    << when->tm_hour << ":" << when->tm_min << ":" << when->tm_sec
		    << endl;
	}
};

MyReturn threadFunc(int secondsToSleep, double valueToReturn) {
	this_thread::sleep_for(chrono::seconds(secondsToSleep));
	MyReturn r {valueToReturn, time(0) };
	return r;
}

int main() {
	future<MyReturn> f1 = async(launch::async, [](){ return threadFunc(8, 1.23); });
	future<MyReturn> f2 = async(launch::async, [](){ return threadFunc(16, 4.56); });
	future<MyReturn> f3 = async(launch::async, [](){ return threadFunc(24, 7.89); });

	while(!f1.is_ready() && !f2.is_ready() || !f3.is_ready()) {
		cout << "One or more threads running so main spinning..." << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}

	MyReturn r1 = f1.get();
	MyReturn r2 = f2.get();
	MyReturn r3 = f3.get();

	cout << "Retrieved the results: " << endl;
	r1.print(cout);
	r2.print(cout);
	r3.print(cout);

	return 0;
}





