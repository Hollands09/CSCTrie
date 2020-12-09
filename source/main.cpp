#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Timer.h"
#include "Rando.h"
#include "Trie.h"

//Test to show insertion time of 42000+ words and searching for 1 word
void test1(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);

//Test to show search time of a random number of words.
void test2(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);

//This is to test the runtime for a million and 3 million words (obviously including repeats).
void test3(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);

int main() {

	Dictionary english; //imports English "dictionary" to be used for inserstion.
	Timer Timer; //used to keep track of run time of different routines.

	std::ofstream dotfile;  //This is not complete but will.  Supposed to be part of the dot file generation.
	dotfile.open("dotfile.txt", std::ofstream::out);
		if (!dotfile) {
			std::cout << "file not created" << std::endl;
			return 0;
		}
		dotfile << "digraph {\n";


	test1(english, Timer, dotfile);
	test2(english, Timer, dotfile);
	test3(english, Timer, dotfile);

	system("pause");
	return 0;
}


void test1(Dictionary& dictionary, Timer timer, std::ofstream &dotfile) {

	std::cout << "////****TEST ONE, 1 word in a dictionary****////\n\n";
	
	Trie* trie = new Trie;

	std::string word = "AARDVARK";

	timer.setTime(1); //set time

	for (size_t i = 1; i < dictionary.dictionary.size(); i++) { //insert all entries of the dictionary
		
		trie->insert(trie, &dictionary.dictionary[i], dotfile);
	
	}

	timer.setTime(2); //end time and output runtime.

	std::cout << " For " << dictionary.dictionary.size() << " inputs to the trie\n\n";
	
	timer.setTime(1);

	trie->search(trie, &word); //search trie for "AARDVARK"
	
	timer.setTime(2);

	std::cout << " to search for 1 word in the trie\n\n";

	system("pause");
}


void test2(Dictionary& dictionary, Timer timer, std::ofstream& dotfile) {

	std::cout << "////****TEST TWO, random words in a dictionary****////\n\n";

	Trie* trie = new Trie;
	
	unsigned int wordSeed = rando(dictionary.dictionary.size()); //Random number generator

	timer.setTime(1);

	for (size_t i = 1; i < dictionary.dictionary.size(); i++) { //insert all dictionary entries
		
		trie->insert(trie, &dictionary.dictionary[i], dotfile);
	
	}

	timer.setTime(2);

	std::cout << " For " << dictionary.dictionary.size() << " inputs to the trie\n\n";

	timer.setTime(1);

	for (int i = 0; i < wordSeed; i++) { //search a random number of entries in the trie between 0 and dictionary size
		
		std::string word = dictionary.dictionary[i];

		trie->search(trie, &word);

	}

	timer.setTime(2);

	std::cout << " to search for " << wordSeed << " words in the trie\n\n";

	system("pause");
}


void test3(Dictionary& dictionary, Timer timer, std::ofstream& dotfile) {

	std::cout << "////****TEST THREE, many dictionaries in 1 tree****////\n\n";
	
	Trie* trie = new Trie;

	timer.setTime(1);

	for (size_t i = 0; i < 1000000; i++) {

		unsigned int wordSeed = rando(dictionary.dictionary.size());

		trie->insert(trie, &dictionary.dictionary[wordSeed], dotfile); //insert the dictionary in a random order 1000000 times
	}

	timer.setTime(2);

	std::cout << " For 1000000 inputs to the trie\n\n";

	system("pause");

	for (int i = 0; i < 3; i++) {

		unsigned int birdSeed = rando(dictionary.dictionary.size());
	
		std::string word = dictionary.dictionary[birdSeed];
	
		timer.setTime(1);
	
		int output = trie->search(trie, &word);
	
		timer.setTime(2);
	
		std::cout << " to search for " << output << " word in the trie of a 1 million inputs\n\n";
	
	}


	system("pause");

	std::cout << "now lets strap in\n\n";
	
	timer.setTime(1);

		for (size_t i = 0; i < 3000000; i++) {

			unsigned int wordSeed = rando(dictionary.dictionary.size());

			trie->insert(trie, &dictionary.dictionary[wordSeed], dotfile);
		}

	timer.setTime(2);

	std::cout << " For 3000000 inputs to the trie\n\n";
}
