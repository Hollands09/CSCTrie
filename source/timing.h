#ifndef _TIME_FUNC_
#define _TIME_FUNC_

#include <chrono>
#include <mutex>
#include <thread>

void timer(std::chrono::high_resolution_clock &time) {
	// Need a clock to mark the start time of the performed function and a clock to mark the end time
	auto time1 = std::chrono::high_resolution_clock::now();
	auto time2 = std::chrono::high_resolution_clock::now();
	// Get the difference in time between the two clocks for the run time of the performed function
	auto timelapsed = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

}

#endif // !_TIME_FUNC_

