#ifndef _DICTIONARY_
#define _DICTIONARY_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

class Dictionary
{

public: 

	Dictionary();

	size_t dictionarySize;
	std::string line;
	std::vector<std::string> dictionary;

};

#endif // !_DICTIONARY_