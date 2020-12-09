#include "Dictionary.h"


Dictionary::Dictionary() {
	// Pull word list from file directory
	std::ifstream wordList("../Trie/english.txt");
	// Capitalize word list for consistency
	while (std::getline(wordList, line)) {

		std::transform(line.begin(), line.end(), line.begin(), ::toupper);

		dictionary.push_back(line);
	}
	// Establish the size of the word bank
	dictionarySize = dictionary.size();

}
