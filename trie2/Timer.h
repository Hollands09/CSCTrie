#ifndef _TIMER_
#define _TIMER_

#include <chrono>
#include <vector>
#include <fstream>
#include <string>

class Timer
{

public:

	Timer();

	Timer(std::string name);

	~Timer();

	void setT1();

	void setT2();

	void graph(int input);

	void printTimer(std::fstream& file);

	std::chrono::high_resolution_clock::time_point t1, t2;

	std::chrono::duration<double> tDiff;

	std::vector<std::chrono::duration<double> > times;
	
	std::vector<int> inputs;

	std::string label;
};

#endif //_TIMER_

