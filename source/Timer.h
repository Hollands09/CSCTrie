#ifndef _TIMER_
#define _TIMER_

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

using namespace std::chrono;

class Timer
{
	public:
		
		Timer();

		void setTime(int clockNum);

		high_resolution_clock::time_point t1, t2;
		microseconds timeElapsed;
};

#endif //_TIMER_
