#include "Trie.h"


Trie::Trie(){}

Trie::~Trie(){}

//Used to create children
Trie* Trie::createNode(){

	Trie* node = new Trie;
	
	node->endString = false;

	return node;
}


//Insert method.  As the input is a string and we only need a char
//Each string has to be broken down within so the Char can be used as a map key
void Trie::insert(Trie*& root, std::string* key, std::ofstream &dotfile) {

	//If node is empty, make one.
	if (root == nullptr) {

		root = createNode();

	}

	// Whatever the previous node was is now going through the same process.
	Trie* curr = root;
	
	//This is used to utilize individual chars in a string. 
	std::string temp = *key;

for (int i = 0; i < temp.size(); i++){

	//if the map doesnt have a pair i.e key "D" and Memory address of Trie
	//Make one
	if (curr->map.find(temp[i]) == curr->map.end()) {

		curr->map[temp[i]] = createNode();

		}

	//itterate through of "keys" of a string to be put into a trie.
	curr = curr->map[temp[i]];
	
	}

	//If repeat work in trie ++ to count.
	curr->count += 1;

	//Finally, we have a leaf.  Let the world know this is a word.
	curr->endString = true;

}

//This is pretty similary to how the insert method works.  Take a key
//check map for all pairs key and memory address
//if finally finally a node is marked as endString then return count and true (1)
//Previous implementation used the int.  Didnt change it.
int Trie::search(Trie*& root, std::string* key) {
	
	if (root == nullptr) {

		std::cout << key << " does not exist in Trie\n\n";

		return 0;

	}

	Trie* curr = root;

	//iterate through idividual "keys" in a string
	std::string temp = *key;

	//if loop finished then endString has to be true so output 
	//if the word exists in the trie.
	for (size_t i = 0; i < temp.size(); i++) {

		curr = curr->map[temp[i]];

		if (curr == nullptr) {

			std::cout << *key << " does not in exist in trie\n\n";

			return 0;
		}

	}

		std::cout << *key << " exists " << curr->count;
		curr->count == 1 ? std::cout << " time in the Trie\n\n" : std::cout << " times in the Trie\n\n";

		return 1;

}


void Trie::dotPrintHelper(Trie*& node,std::string *key, std::ofstream& dotfile) {

	dotfile << "a -- b\n" << "c -- d\n" << "}";


}


