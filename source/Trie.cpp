#include "Trie.h"


Trie::Trie(){}

Trie* Trie::createNode(){

	Trie* node = new Trie;
	
	node->endString = false;

	return node;
}

void Trie::insert(Trie*& root, std::string* key, std::ofstream &dotfile) {

	if (root == nullptr) {

		root = createNode();

	}

	Trie* curr = root;
	
	std::string temp = *key;

for (int i = 0; i < temp.size(); i++){

	if (curr->map.find(temp[i]) == curr->map.end()) {

		curr->map[temp[i]] = createNode();

		}

	curr = curr->map[temp[i]];
	
	}

	curr->count += 1;
	curr->endString = true;

}

int Trie::search(Trie*& root, std::string* key) {
	
	if (root == nullptr) {

		std::cout << key << " does not exist in Trie\n\n";

		return 0;

	}

	Trie* curr = root;

	std::string temp = *key;

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

void Trie::triePrintNull(std::string key, int nullcount, std::ofstream& dotfile) {

}

void Trie::dotPrintHelper(Trie*& node,std::string *key, std::ofstream& dotfile) {


}

void Trie::triePrintDot(Trie*& node, std::ofstream& dotfile) {



}
