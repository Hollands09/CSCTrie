#ifndef _TRIE_
#define _TRIE_
////////////////////////////////////////////////////////////
//
// Implementation of a Trie.
//
//TODO: Add recursive delete.  Dotfile generations.
////////////////////////////////////////////////////////////


#include <string>
#include <unordered_map>
#include <errno.h>
#include <fstream>
#include "Timer.h"

class Trie
{
public:

	//Default constructor nothing special here.
	Trie();

	//Destructor
	~Trie();

	//Creates new node and returns it.
	Trie* createNode();

	//passed pointer refernce more specifically to modify the map for childen
	void insert(Trie*& root, std::string* key, std::ofstream &dotfile);

	//Searches the trie for specified word, returns number of repeats.
	int search(Trie*& root, std::string* key);

	/*
	I never want to look at these again but I will.
	void triePrintNull(std::string key, int nullcount, std::ofstream& dotfile);

	void triePrintDot(Trie*& node, std::ofstream& dotfile);
	*/ 


	void dotPrintHelper(Trie*& node, std::string* key, std::ofstream& dotfile);

	//If leaf endString = true.
	bool endString = false;
	
	//Used in prior implementations using arrays.
	int depth = 0;
	
	//If a string is added twice it increments (string actually wont be in trie twice but it was tried to be added)
	int count = 0;

	//I didn't want to use maps at all but the larger inputs and the larger dictionaries were causing crashes due to the large amount 
	//of unused pointers towards the end of the bottom of the tree.
	std::unordered_map<char, Trie*> map;

};

#endif _TRIE_
