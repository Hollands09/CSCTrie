#ifndef _DICTIONARY_
#define _DICTIONARY_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

//This dictionary is meant to be used store masses of words and place them into a trie.

class Dictionary
{

public:

	Dictionary(); //default constructor

	~Dictionary();

	size_t dictionarySize; //total strings input from constructor.

	std::string line; //Individual string from .txt to be converted to uppercase.
	
	std::vector<std::string> dictionary; //all converted words stored in a vector.

};

#endif // !_DICTIONARY_