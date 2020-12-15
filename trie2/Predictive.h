#ifndef _PREDICTIVE_
#define _PREDICTIVE

#include "Trie.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Dictionary.h"

//
//This is in the words, planning on using boost to parse the command line to search the trie for words similar to the one being typed.  Ignore.
//

void predictiveText() {

	Trie* trie = new Trie;

	Dictionary english;

	for (size_t i = 0; i < 15; i++) {

		trie->insert(english.dictionary[i]);


	}

	std::string input;

	while (std::getline(std::cin, input)) {

		std::stringstream ss(input);
		std::string output;

		ss >> output;

		std::cout << output << "\n";


	}


}

#endif // !_PREDICTIVE_
