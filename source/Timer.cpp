#include "Timer.h"

Timer::Timer() {
	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
}
void Timer::setTime(int clockNum) {

	if (clockNum == 1) {

		t1 = high_resolution_clock::now();

	}
	else if (clockNum == 2) {

		t2 = high_resolution_clock::now();
		auto timeElapsed = duration_cast<microseconds>(t2 - t1); // Calculate difference between the end time and start time to determine total run time
		
		// Output in microseconds since the times are very small numbers
		std::cout << "duration of routine is " << timeElapsed.count() << " microseconds";

	}

}
