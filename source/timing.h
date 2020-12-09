#ifndef _TIME_FUNC_
#define _TIME_FUNC_

#include <chrono>
#include <mutex>
#include <thread>

void timer(std::chrono::high_resolution_clock &time) {

	auto time1 = std::chrono::high_resolution_clock::now();
	auto time2 = std::chrono::high_resolution_clock::now();
	auto timelapsed = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

}

#endif // !_TIME_FUNC_

