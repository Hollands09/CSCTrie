#ifndef _TRIE_
#define _TRIE_

#include <string>
#include <unordered_map>
#include "Timer.h"
#include <errno.h>
#include <fstream>

class Trie
{
public:

	Trie();

	Trie* createNode();

	void insert(Trie*& root, std::string* key, std::ofstream &dotfile);

	int search(Trie*& root, std::string* key);

	void triePrintNull(std::string key, int nullcount, std::ofstream& dotfile);

	void dotPrintHelper(Trie*& node, std::string *key, std::ofstream& dotfile);

	void triePrintDot(Trie*& node, std::ofstream& dotfile);

	bool endString = false;
	
	int depth = 0;

	int count = 0;

	std::unordered_map<char, Trie*> map;

};

#endif _TRIE_