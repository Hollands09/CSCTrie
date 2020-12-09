
Skip to content
Pull requests
Issues
Marketplace
Explore
@Hollands09
Learn Git and GitHub without any code!

Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.
Hollands09 /
CSCTrie
Private

1
0

    0

Code
Issues
Pull requests
Actions
Projects
Security
Insights

    Settings

CSCTrie/source/main.cpp
@Hollands09
Hollands09 Finally getting to push everything
Latest commit eb9f53f 2 hours ago
History
1 contributor
141 lines (88 sloc) 3.08 KB
#include <iostream>
#include "Trie.h"
#include <string>
#include "Dictionary.h"
#include "Timer.h"
#include "Rando.h"

void test1(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);
void test2(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);
void test3(Dictionary& dictionary, Timer timer, std::ofstream& dotfile);

int main() {

	Dictionary english;
	Timer Timer;

	std::ofstream dotfile;
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
}

void test1(Dictionary& dictionary, Timer timer, std::ofstream &dotfile) {

	std::cout << "////****TEST ONE, 1 word in a dictionary****////\n\n";

	std::string word = "AARDVARK";
	Trie* trie = new Trie;


	timer.setTime(1);

	for (size_t i = 1; i < dictionary.dictionary.size(); i++) {
		trie->insert(trie, &dictionary.dictionary[i], dotfile);
	}

	timer.setTime(2);

	std::cout << " For " << dictionary.dictionary.size() << " inputs to the trie\n\n";
	
	timer.setTime(1);
	trie->search(trie, &word);
	timer.setTime(2);

	std::cout << " to search for 1 word in the trie\n\n";

	system("pause");
}

void test2(Dictionary& dictionary, Timer timer, std::ofstream& dotfile) {

	std::cout << "////****TEST TWO, random words in a dictionary****////\n\n";

	Trie* trie = new Trie;
	unsigned int wordSeed = rando(dictionary.dictionary.size());

	timer.setTime(1);

	for (size_t i = 1; i < dictionary.dictionary.size(); i++) {
		trie->insert(trie, &dictionary.dictionary[i], dotfile);
	}

	timer.setTime(2);

	std::cout << " For " << dictionary.dictionary.size() << " inputs to the trie\n\n";

	timer.setTime(1);

	for (int i = 0; i < wordSeed; i++) {
		
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

		trie->insert(trie, &dictionary.dictionary[wordSeed], dotfile);
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

    © 2020 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Help
    Contact GitHub
    Pricing
    API
    Training
    Blog
    About

