#include "Dictionary.h"

Dictionary::Dictionary() {

	std::ifstream wordList("../Trie2/english.txt"); //Store 42000+ english words in this class to be used later on.

	while (std::getline(wordList, line)) {

		std::transform(line.begin(), line.end(), line.begin(), ::toupper); // convert all words to uppercase

		dictionary.push_back(line);
	}

	dictionarySize = dictionary.size() - 1;

}

Dictionary::~Dictionary() {


}
