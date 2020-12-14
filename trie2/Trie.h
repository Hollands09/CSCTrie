#ifndef _TRIE_
#define _TRIE_

#include <iostream>
#include <fstream>
#include <vector>;

class Trie
{

public:

	Trie();

	~Trie();

	//inserts a string into a trie.
	void insert(std::string key);

	//search for a specific string in a trie.  Outputs total count and if it exists in the trie or not.
	bool search(std::string key);

	bool search(std::string key, std::string ret);

	//Prints a string in a Trie into .dot file format.  Uses pointer value as node name so that the letters go to their appropriate children.
	void printDot(Trie*& trie, std::string key, std::fstream& dotfile);

private:

	//returns false is leaf else returns true.
	bool hasChildren(Trie const* root); //returns 0 if leaf

	//nodes for the dotfile are based off of pointer i.e
	//node00A97640 [label="L"]
	//so when this specific L in the trie goes to its next letter lets say it goes to I
	//node00A96AD8 [label="I"] this I has a specific trie node pointer value so all L's and I's
	//go to their correct unique node.  LablePrint prints the node and its equivilent letter value.
	void labelPrint(Trie*& trie, std::string key, std::fstream& dotfile); 

	enum Lang { //meant for later implementations of different languages/char sets.

		english = 128

	};

	//Each node holds its child nodes here.
	Trie* child[Lang::english];
	
	//True if leaf
	bool endString;

	//Increments if string is put into the trie multiple times.
	int count;

};
#endif //_TRIE_
