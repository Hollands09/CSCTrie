#ifndef _TRIE_
#define _TRIE_
#include <string>
#include <iostream>


class Trie
{
public:

	Trie();

	Trie* createNode();

	void insert(Trie* root, std::string key);

	int search(Trie* root, std::string key);

	bool empty(Trie* root);

	Trie* deleteNode(Trie* root, int depth, std::string key);

	Trie* child[26];
	bool endString;
	int depth, count;
};

#endif _TRIE_