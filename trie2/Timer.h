#ifndef _TIMER_
#define _TIMER_

#include <chrono>
#include <vector>
#include <fstream>
#include <string>

//Timer class to be used as containers to store timing data of specific functions run time
//Methods are left public because they need to be called outside of the class

class Timer
{

public:

	//default constructor
	Timer();

	//Enter name for dataset to be used on x y label for plots
	Timer(std::string name);

	//destructor
	~Timer();

	//sets t1. used before function
	void setT1();

	//sets t2 use after function
	void setT2();

	//stores tDiff and input of your choice in the vectors input and times.  Used to print out .m files for matlab
	void graph(double input);

	//Enter "plot" or "scatter" for your desired plot output.  point can be 'ko' for black circles or 'rd' for red diamonds, see matlab help plot for examples
	void printTimer(std::fstream& file, std::string plotType, std::string point); 

	//used for finding difference in times to find run time for a function
	std::chrono::high_resolution_clock::time_point t1, t2;

private:

	//stores value of t2 - t1
	std::chrono::duration<double> tDiff;

	//stores values of tDiff to help plot runtime
	std::vector<std::chrono::duration<double> > times;
	
	//stores input of choice to plot runtime
	std::vector<double> inputs;

	//used when printing x/y labels for plot
	std::string label;
};

#endif //_TIMER_

