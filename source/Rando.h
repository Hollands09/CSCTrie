#ifndef _RANDO_
#define _RANDO_
////////////////////////////////////////////////////////////
//
// This is just use for generating a seeded random number.
//
////////////////////////////////////////////////////////////
#include <random>
#include <chrono>

unsigned int rando(int max) {

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();  //Time since epoch Doesnt like that is cast to an u_int but oh well.
	
	std::default_random_engine generator(seed); //std library number generator c++11.  Can be seeded like we did here.
	
	std::uniform_int_distribution<int> dist(0, max); //c++11 goodies for making ensuring that the random generated number is "random"

	seed = dist(generator);

	return seed;

}

#endif
