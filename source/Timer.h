#ifndef _TIMER_
#define _TIMER_
////////////////////////////////////////////////////////////
//
// Timer class for tracking and storing run time.
//
////////////////////////////////////////////////////////////

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

using namespace std::chrono;

class Timer
{
	public:
		//default constructor
		Timer();
		
		//Destructor
		~Timer();

		//pass 1 or 2 to set respective clocks.  If 2 is entered it will also output the run time.
		void setTime(int clockNum);

		//part of chrono declared here and initialized in constructor.
		high_resolution_clock::time_point t1, t2;
		
		//Not a microsecond  value in the traditional sense, its still part of the chrono and if awful to cast
		//Stores the delta between t2 and t1.
		microseconds timeElapsed;
};

#endif //_TIMER_
