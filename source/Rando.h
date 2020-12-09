#ifndef _RANDO_
#define _RANDO_

#include <random>
#include <chrono>

// Random number generator for selecting a random word
unsigned int rando(int max) {
	
	// Seed based off of system clock
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> dist(0, max);

	seed = dist(generator);

	return seed;

}

#endif
