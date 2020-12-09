#include "Dictionary.h"


Dictionary::Dictionary() {

	std::ifstream wordList("../Trie/english.txt");

	while (std::getline(wordList, line)) {

		std::transform(line.begin(), line.end(), line.begin(), ::toupper);

		dictionary.push_back(line);
	}

	dictionarySize = dictionary.size();

}
