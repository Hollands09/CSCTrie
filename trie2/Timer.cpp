#include "Timer.h"

Timer::Timer() {

	t1 = std::chrono::high_resolution_clock::now();

	t2 = std::chrono::high_resolution_clock::now();

	tDiff = std::chrono::duration_cast<std::chrono::duration<double >>(t2 - t1);
}

Timer::Timer(std::string name) {

	t1 = std::chrono::high_resolution_clock::now();

	t2 = std::chrono::high_resolution_clock::now();

	tDiff = std::chrono::duration_cast<std::chrono::duration<double >>(t2 - t1);

	label = name;
}

Timer::~Timer() {


}

void Timer::setT1() {

	this->t1 = std::chrono::high_resolution_clock::now();

}

void Timer::setT2() {

	this->t2 = std::chrono::high_resolution_clock::now();

}

void Timer::graph(int input) {

	if (this->label == "Input Total") {

		tDiff += std::chrono::duration_cast<std::chrono::duration<double >>(this->t2 - this->t1);

	}
	else {

		tDiff = std::chrono::duration_cast<std::chrono::duration<double >>(this->t2 - this->t1);

	}
	this->times.push_back(tDiff);
	this->inputs.push_back(input);

}


void Timer::printTimer(std::fstream& file) {

	file << "clc\n clear\n ylabel('Time')\n xlabel('" << this->label << "')\n  grid on\n y = [";

	for (int i = 0; i < this->times.size(); i++) {

		file << this->times[i].count() << " ";

	}

	file << "];\n x = [";

	for (int i = 0; i < this->inputs.size(); i++) {

		file << this->inputs[i] << " ";

	}

	file << "];\n hold on\n plot(x, y)\n hold off\n pause\n";

}